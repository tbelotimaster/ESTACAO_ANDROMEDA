//Dev: Tiago Beloti

//libs do projeto
#include <ESP8266WiFi.h> //lib para conexão wifi
#include <DHT.h> //lib sensor de temperatura (primeira medição) + Humidade
#include <PubSubClient.h> //conexão MQTT client, pub/sub
#include <Wire.h> //Lib para o funcionamento do protocolo I2C
#include <SFE_BMP180.h> //Barometro digital 
#include <Adafruit_VEML6070.h> //lib para o sensor VEML6070 UV
#include <NTPClient.h> //lib para o protocolo NTP
#include <RTClib.h> //lib real time clock DS1307
#include <WiFiUdp.h> //lib do protocolo UDP
#include <MySQL_Generic.h> //lib de conexão ao mysql(mariadb) do servidor
#include "time.h" //lib de sync de tempo
/*
* Defines do projeto
*/
#define DHTPIN 0 //Pino onde o DHT está ligado (D3)
//#define SSID_REDE "belotinetwork" //Nome da rede
#define SSID_REDE "1a2b3c" //Nome da rede
//#define SENHA_REDE "ad9ded041cbf" //Senha da rede
#define SENHA_REDE "#GarenTI2023" //Senha da rede
#define INTERVALO_ENVIO       600000 //intervalo de envio de mensagens MQTT (10min)
//#define INTERVALO_ENVIO       30000 //intervalo de envio de mensagens MQTT (30 segundos)

//Para outros tipos de sensores DHT, seguir a tabela
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321
//#define DHTTYPE DHT21 // DHT 21 (AM2301

//Para o sensor VEML6070
#define VEML6070_ADDR_L     (0x38) ///< Low address

//Define o pino Analogico do esp12
#define AnalogPin A0

//Para o sensor LDR de 5mm
#define sensorLDRPowerPin 2

//Para o sensor de chuva YL83
#define sensorRainPowerPin 14

//definições para o conector do mysql
#define USING_HOST_NAME     true
#if USING_HOST_NAME
  char server[] = "network.tbmaster.com.br"; //servidor onde esta o banco de dados
#endif
char user[]         = "admin";              // MySQL user login username
char password[]     = "9ded041c";          // MySQL user login password
uint16_t mysql_server_port = 3360;
char default_database[] = "meteorologia_casa";           //"schema banco de dados";

//tabelas do banco de dados
char table_BMP180[]    = "BMP180"; //tabela barometro
char table_DHT11[] = "DHT11"; //tabela sensor de temperatura e umidade
char table_YL83[] = "YL83"; //tabela do sensor de chuva                     

//Var do DHT
float temperatura01_now = 0.0;
float umidade_now = 0.0;

//Var BMP180 (I2C) - D1(SCL), D2(SDA)
double bmp_temp;
double pressao_relativa;
double pressao;
char status;
// int alt; //altitude referente a outra lib, comentado
const int ALTITUDE = 649; //constante da altitude media para minha casa ** IMPORTANTE
const int TEMPO_ESPERA = 3000;

//var VEML6070
int  uv_level;
float  index_uv;

//variaveis para o LDR
float ldr;
float tensao;
float radiancia_mw2;

//YL83 - sensor de chuva
boolean chuva_status;
int rainAnalogVal = 0;

//variavel hora_ntp e data_ntp para o NTP
String hora_ntp;
unsigned long epochtime_ntp;

//variavel now para o RTC
DateTime now;
String DD;
String MM;
int year;
String HH;
String mm;
String ss;
String Formated_RTC_date;
String Formated_RTC_time;
unsigned long RTC_unixtime;

//Instancias e configs
WiFiClient espClient; //Instancia do Wifi
DHT dht(DHTPIN, DHTTYPE); //Instancia do DHT
PubSubClient clientpub(espClient); //cliente de publicação para o MQTT
//Adafruit_BMP085 bmp180; //criação do objeto para o modulo bpm180
SFE_BMP180 bmp180; //criação do objeto na classe SF_BMP180 da lib
Adafruit_VEML6070 uv_sensor = Adafruit_VEML6070(); //criação do objeto para o modulo de sensibilidade UV

//Socket UDP que a lib utiliza para recuperar dados sobre o horário
WiFiUDP udp;

//Objeto responsável por recuperar dados sobre horário
NTPClient ntpClient(udp, "a.ntp.br", -10800, 60000);

//Objeto responsável pelo RTC
RTC_DS1307 DS1307_RTC;

//informações do broker MQTT
//const char* mqttServer = "network.tbmaster.com.br";   //server
const char* mqttServer = "network.tbmaster.com.br";

const char* mqttUser = "andromedamqttadmin";
//const char* mqttUser = "andromedaMQTT";

const char* mqttPassword = "9ded041c";              //user
//const char* mqttPassword = "9ded041c";      //password

const int mqttPort = 1883;                     //port
const char* mqttTopicSub ="casa";            //tópico que sera assinado
int ultimoEnvioMQTT = 0;

//Variaveis referentes a query de INSERT
MySQL_Connection conn((Client *)&client); //instancia do conector mysql
MySQL_Query *query_mem_bmp180; //endereço de memoria da query bmp180
MySQL_Query *query_mem_dht11; //endereço de memoria da query sensor dht11
MySQL_Query *query_mem_yl83; //endereço de memoria da query sensor yl83 - chuva

//-----------------------------------------------------------------------------
void setup() {
  
Serial.begin(115200); //inicializa a serial para DEBUG

pinMode(sensorRainPowerPin, OUTPUT); /* Define o pinmode do controle de energia do sensor de chuva */
pinMode(sensorLDRPowerPin, OUTPUT); //Define o pinmode do controle de energia do sensor LDR de 5mm

/* Inicializa e conecta-se ao wi-fi */
    init_wifi();

/* Inicializa a conexão ao MQTT */
    init_MQTT();

/* Inicializa o client NTP para data e hora*/
    init_NTP();    
    lerHORA();

// Inicia o RTC
    init_RTC ();

//inicializa o sensor BMP180
    BMP_init();

/* Inicializa sensor de temperatura e umidade relativa do ar */
    dht.begin();
    delay(50);

/* Inicializa sensor de leitura de raios UV */
    VEML6070_init();

//faz uma leitura na inicialização e as envia logo no começo
  //lerBMP(); 
  //ler_DHT();
  //ler_VEML6070();

//DEBUG
//Serial.println(__TIME__);
//Serial.println(__DATE__);

}

//------------------------------------------------------------------------------

void loop() {

if (!clientpub.connected()) {
    reconect_MQTT();
  }

  //envia a cada X segundos
  if ((millis() - ultimoEnvioMQTT) > INTERVALO_ENVIO)
  {

  //lerHORA(); //atualiza a variavel "hora" com a hora certa atual
  //Serial.println(hora_ntp);


// leitura de data e tempo do RTC ajustado pelo NTP
  get_time_RTC();

  get_unixtime_RTC();

  get_date_RTC();

//leitura dos sensores
  lerBMP();
   
  ler_DHT();

  ler_VEML6070();

  ler_sensor_chuva();


//Rotina para rodar as Querys INSERT dos sensores  
if (conn.connectNonBlocking(server, mysql_server_port, user, password) != RESULT_FAIL)
{
  delay(500);
  run_insert_bmp180();
  run_insert_dht11();
  run_insert_yl83();
  conn.close();
}
else
{
  Serial.println("Conexão ao banco de dados falhou, tente novamente na proxima interação");
  Serial.println();
}

//Controle de envio do MQTT e proxima leitura dos sensores
  ultimoEnvioMQTT = millis();

  }

 delay(600000); //10min
 //delay(30000); // 30 segundos

 clientpub.loop();

}

//---------------------------------------END-------------------------------------
