void ler_sensor_chuva()
{

//varianeis locais de escrita ao MQTT
  char MsgRain_rainAnalogVal[4];
  char MsgRain_chuva_status[4];

  digitalWrite(sensorRainPowerPin, HIGH); //liga o sensor
  delay(100); //curto periodo de leitura
  rainAnalogVal = analogRead(AnalogPin);

//detecta se está chovendo ou não
  if (rainAnalogVal <= 200)
  {
    chuva_status = true;
  } else {
    chuva_status = false;
  }


Serial.println();
Serial.println(F(">>>>>Sensor de Chuva<<<<<"));
Serial.println(F("Intensinade da humidade"));
Serial.println(F("Seco = 1024, humidade alta = 201 a 400, humidade baixa = 401 a 1023, chovendo =< 200"));
Serial.println(rainAnalogVal);
Serial.print(F("Chovendo? - "));
Serial.println(chuva_status);
Serial.println();

digitalWrite(sensorRainPowerPin, LOW); //desliga o sensor
delay(1000); //Delay de 1 segundo para dar tempo do pino desligar completamente

//Realiza a publicação dos valores ao MQTT
  sprintf(MsgRain_rainAnalogVal,"%u",rainAnalogVal);
  clientpub.publish("casa/RainAnalogVal", MsgRain_rainAnalogVal);
  
  sprintf(MsgRain_chuva_status,"%u",chuva_status);
  clientpub.publish("casa/RainStatus", MsgRain_chuva_status);


}