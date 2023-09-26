void ler_DHT()
{
  //varianeis locais de escrita ao MQTT
  char MsgUmidadeMQTT[4];
  char MsgTemperaturaMQTT[4];
  
  
  temperatura01_now = dht.readTemperature();
  delay(100);
  umidade_now     = dht.readHumidity();
  delay(100);
  
  //debug
  Serial.println(F(">>>>>Sensor_DHT<<<<<"));
  Serial.print(F("Temperatura_DHT: "));
  Serial.println(temperatura01_now);
  Serial.print(F("Umidade: "));
  Serial.println(umidade_now);
  Serial.println("");
    
  //Realiza a publicação dos valores ao MQTT
  //sprintf(MsgUmidadeMQTT,"%2.1f",umidade_now);
  sprintf(MsgUmidadeMQTT,"%2.1f",umidade_now);
  clientpub.publish("casa/umidade", MsgUmidadeMQTT);
  
  //sprintf(MsgTemperaturaMQTT,"%2.1f",temperatura01_now);
  sprintf(MsgTemperaturaMQTT,"%2.1f",temperatura01_now);
  clientpub.publish("casa/temperatura", MsgTemperaturaMQTT);
  
   
}
//-------------------------------------------------------------
