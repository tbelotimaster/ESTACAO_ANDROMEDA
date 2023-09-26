void BMP_init()
{
  if (!bmp180.begin())
  {
    delay(100);
    Serial.println(F("BPM180 BAD OR NOT FOUND"));
 } else {
    delay(100);
    Serial.println(F("BPM180 OK"));
  }
  return;
}
//--------------------------------------------------
void lerBMP()
{

char MsgTemperatura_BMP_MQTT[4];
char MsgPressaoMQTT[4];
char MsgAltMQTT[4];
char MsgPressao_relMQTT[4];
  
  //bmp_temp = bmp180.readTemperature(); comentado, referente a lib anterior
  
  status = bmp180.startTemperature(); //inicializa a leitura de temperatura
  if (status !=0) { //garante que a variavel auxiliar de status é diferente de 0
    delay(status); //aguarda a finalização da inicialização
    status = bmp180.getTemperature(bmp_temp); //realiza a medição de temperatura
    if (status !=0) {
      delay(100);
      //imprime as leituras da temperatura
      Serial.println(F(">>>>>Sensor_BMP180<<<<<"));
      Serial.print(F("Temperatura_BMP: "));
      Serial.print(bmp_temp,2); //imprime a temperatura com oversample
      Serial.println(" *C");
        status = bmp180.startPressure(3); //inicia a leitura de pressao com oversample
        if(status !=0) {
          delay(status); //aguarda a inicialização da leitura de pressao
          status = bmp180.getPressure(pressao,bmp_temp); //realiza a medição de pressao em relação a temperatura
          if(status !=0) {
            //imprime as leituras da pressao
            Serial.print(F("Pressao: "));
            Serial.print(pressao,2); //imprime a medicao de pressao com oversample
            Serial.println(F(" mbar"));
            pressao_relativa = bmp180.sealevel(pressao,ALTITUDE); //calcula a pressao relativa
            //imprime as leituras obtidas
            Serial.print(F("Pressao relativa ao nivel do mar: "));
            Serial.print(pressao_relativa,2); //imprime a variavel relativa com oversample
            Serial.println(" mbar \n");
          }
        }
    }
  } else { //caso alguma das leituras não seja feita
    Serial.print(F("Erro na leitura do sensor de pressao e temperatura"));
  }
        
  //pressao = bmp180.readPressure(); //comentado refetente a outra lib
  //delay(100);
  
  //Realiza a publicação dos valores ao MQTT
  sprintf(MsgTemperatura_BMP_MQTT,"%f",bmp_temp);
  clientpub.publish("casa/temperatura_BMP", MsgTemperatura_BMP_MQTT);
  
  sprintf(MsgPressaoMQTT,"%f",pressao);
  clientpub.publish("casa/pressao", MsgPressaoMQTT);

  sprintf(MsgPressao_relMQTT, "%f",pressao_relativa);
  clientpub.publish("casa/pressaorel", MsgPressao_relMQTT);

// comentado devido ao uso de outra lib   
//  sprintf(MsgAltMQTT,"%u",alt);
//  client.publish("casa/altitude", MsgAltMQTT);
  
  return;
}
//--------------------------------------------------
/* comentado devido ao uso de outra lib
void lerAltitude()
{
  delay(100);
  Serial.println("");
  alt = bmp180.readAltitude();
  delay(100);
  Serial.println("");
  Serial.print(F(">>>>>Altitude da estacao(From BMP180): "));
  Serial.print(alt);
  Serial.println(F(" Metros do nivel do mar"));
  Serial.println("");
}
*/
//--------------------------------------------------
