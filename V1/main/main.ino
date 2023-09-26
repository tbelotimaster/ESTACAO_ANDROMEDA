//Bibliotecas
#include <Adafruit_VEML6070.h>
#include <Adafruit_BMP085.h> //compativel para BPM180
#include <Wire.h> //biblioteca I2C
#include <LiquidCrystal_I2C.h> //biblioteca para o display I2C
#include <SD.h> //biblioteca com funções para o MicroSD Adapter
#include <SPI.h> //biblioteca para habilitar o barramento SPI (cs,sck,mosi,miso)
#include <SoftwareSerial.h> //emulação de porta serial nos pinos digitais
#include <RTClib.h> //biblioteca do modulo de relógio real
//#include <DHT.h> //biblioteca do medidor de temperatura e umudade DHT11 ou DHT22
//#include <NTPClient.h> //biblioteca do NTP
//#include <WiFiUdp.h> //biblioteca para pacotes UDP que trabalha com o NTP

//variaveis e definições
byte botao1 = 7;
byte botao_home = 6;
byte statusled = 13;
byte pinoCS = 10;
byte flag_dht_status = 0;
byte flag_ldr_status = 0;

int  uv_level;
int  index_uv;

// byte umidade;
float temperatura;
int altitude, pressao;

int Hor, Min, Seg, dia, mes, ano;

const int LDRpin = A0;
const int SCLPin = A5;
const int SDAPin = A4;

DateTime nowrtc;

const char *ssid = "belotinetwork_guest"; //SSID do wifi
const char *password = "tbmaster8524"; //Senha do wifi

bool isTemp = true, isHome = false, isRad = false, isUV = false;
long nextRun = 0;
float LDR, tensao,tensao2, rad; // rad é irradiancia por metro quadrado (radiancia global de iluminação)
byte grauC[] = {
  B01100,
  B10010,
  B10010,
  B01100,
  B00000,
  B00000,
  B00000,
  B00000
};

//#define DHTPIN 5 //o pino onde o DHT está conectado
//#define DHTTYPE DHT11 // para o DHT11; para demais modelos veja tabela abaixo
//#define DHTTYPE DHT22 // DHT 22 (AM2302)
//#define DHTTYPE DHT21 // DHT 21 (AM2301)

//Configurações e instanciamentos

Adafruit_VEML6070 uv_sensor = Adafruit_VEML6070(); //criação do objeto para o modulo de sensibilidade UV

#define VEML6070_ADDR_L     (0x38) ///< Low address

Adafruit_BMP085 bmp180; //criação do objeto para o modulo bpm180

LiquidCrystal_I2C lcd(0x27,8,2); //display padrão 8 colunas por 2 linhas, inicializa no endereço padrão 0x27

RTC_DS1307 rtc; //criação do objeto para o modulo I2c RTC DS1307

//DHT dht(DHTPIN, DHTTYPE); //Da um nome para o sensor, define o pino onde está conectado e o tipo

SoftwareSerial esp01_serial(2,3); //pino 2 TX, pino 3 RX

File logFile; //objeto que contem o arquivos de log da estação
File logDATA; //objeto que contem o arquivo de log dos instrumentos para analise

//WiFiUDP udp; //cria um objeto UDP
//NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000); //cria um objeto NTP com as configurações necessárias

//----------------------------------------
 
void setup()
{

//debug
Serial.begin(9600);
//debug
  
 lcd.init(); //inicia a instancia do display
 lcd.createChar(0, grauC);//cria o char personalizado de graus celcius
 
//connectWIFI();
//ntp.begin();
 
 pinMode(pinoCS, OUTPUT); //define o CS (Chip Select) do modulo como saída
 pinMode(botao1,INPUT_PULLUP); //define o pino do botão como entrada e acisona o pullup interno
 pinMode(botao_home, INPUT_PULLUP); ////define o pino do botao_home como entrada e acisona o pullup interno
 pinMode(statusled, OUTPUT); //define o pino 13 como saida (status)
 pinMode(SCLPin, INPUT_PULLUP);//pullup interno para multi dispositivos I2c
 pinMode(SDAPin, INPUT_PULLUP);//pullup interno para multi dispositivos I2c

 //esp01_serial.begin(115200); //inicia a serial emulada a 115200 dBs (dafult do esp01)

initSD();//Inicia e testa o SDcard
delay(2000);

BMP_init(); //Inicia o BPM180
delay(2000);

//comentadas as ações do DHT, pois o sensor será acrecentado em uma outra versão
/* DHT_test();
delay(2000);
if (flag_dht_status == 1) {
  trocar_DHT();
}
*/

LDR_test();
delay(2000);
if (flag_ldr_status == 1){
  trocar_LDR();
}

VEML6070_test();

RTC_start();//inicia e testa o RTC DS1307
delay(2000);

Splash();//Exibe a tela de splash
 
}

//----------------------------------------
 
void loop()
{
  long now = millis();
  if(isTemp)
  {
    if(now >= nextRun)
    {
      nextRun = now+60000;
//    temp_umid();
      lerLDR(); //aquisição de dados do LDR
      delay(50);
      lerBMP(); //aquisição de dados do BMP180
      
      VEML6070_show();
      delay(3000);
      
      BMP_screen();
          
     
//    gravaLOG_BMP();
//    gravalogDHT();
//    delay(100);

//    gravalogLDR();
      delay(100);
      
      gravaLOGDATA();
           
    }
  }

  if(isHome)
  {
    if(now >= nextRun)
    {
      nextRun = now+600000;
      Home();
    }
  }

if(isRad)
  {
    if(now >= nextRun)
    {
      nextRun = now+10000;
      mostra_LDR();
    }
  }

if(isUV)
  {
    if(now >= nextRun)
    {
      nextRun = now+10000;
      VEML6070_show();
    }
  }  
  
    
  if(digitalRead(botao1) == LOW && isHome) // Se o botão 1 for pressionado
  {
    isUV = false;
    isHome = false;
    isRad = false;
    isTemp = true;
    nextRun = 0;
    delay(80); //debounce
  }

  if(digitalRead(botao_home) == LOW && !isHome) //Se o botao_home for pressionado
  {
    isHome = true;
    isTemp = false;
    isRad = false;
    isUV = false;
    nextRun = 0;
    delay(80); //debounce
  }


if(digitalRead(botao1) == LOW && isTemp) // Se o botão 1 for pressionado
  {
    isUV = false;
    isHome = false;
    isTemp = false;
    isRad =  true;
    nextRun = 0;
    delay(80); //debounce
  }

if(digitalRead(botao1) == LOW && isRad) // Se o botão 1 for pressionado
  {
    isUV = true;;
    isHome = false;
    isTemp = false;
    isRad =  false;
    nextRun = 0;
    delay(80); //debounce
  }

if(digitalRead(botao1) == LOW && isUV) // Se o botão 1 for pressionado
  {
    isUV = false;
    isHome =true;
    isTemp = false;
    isRad =  false;
    nextRun = 0;
    delay(80); //debounce
  }  

  if(digitalRead(botao1) == LOW and (digitalRead(botao_home) == LOW))//se os 2 botões forem pressionados juntos
  {
    isUV = false;
    isTemp = false;
    isRad = false;
    isHome = false;
    Reseting();
  }
  
}

//----------------------------------------

 
