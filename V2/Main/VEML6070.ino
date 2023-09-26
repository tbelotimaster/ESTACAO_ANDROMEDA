void VEML6070_init()
{
  uv_sensor.begin(VEML6070_1_T); //setando o tempo para amostragem de luz(integration time), 600ms de espera de captura
                                //valores possiveis VEML6070_x_T sendo x = 1 até 4
  delay(50);                              
}
//---------------------------------------------------------
void ler_VEML6070()
{

//varianeis locais de escrita ao MQTT
  char MsgUV_LEVEL_MQTT[4];
  char MsgUV_INDEX_MQTT[4];
  
  uv_level = uv_sensor.readUV();
  delay(1000); //dalay para o tempo de amostragem
  Serial.println(F(">>>>>NIVEL UV<<<<<"));
  //Serial.println(uv_level);

/*

  if (uv_level <= 2.9)
  {
    Serial.print(F("BAIXO - "));
    Serial.println(uv_level);
  }

  if (uv_level < 5.9 && uv_level > 3)
  {
    Serial.print(F("MODERADO - "));
    Serial.println(uv_level);
  }

  if (uv_level < 7.9 && uv_level > 6)
  {
    Serial.print(F("ALTO - "));
    Serial.println(uv_level);
  }

  if (uv_level < 10.9 && uv_level > 8)
  {
    Serial.print(F("MUITO ALTO - "));
    Serial.println(uv_level);
  }

  if (uv_level >= 11)
  {
    Serial.print(F("EXTREMO - "));
    Serial.println(uv_level);
  }
*/
  
  if (uv_level >= 0 && uv_level < 689)
  {
    index_uv = uv_level/230;
    Serial.print(F("BAIXO - "));
    Serial.println(index_uv);
    Serial.println(F("Proteção recomendada: Livre"));
    delay(50);
  }
  if (uv_level >= 690 && uv_level < 1379)
  {
    index_uv = uv_level/230;
    Serial.print(F("MODERADO - "));
    Serial.println(index_uv);
    Serial.println(F("Proteção recomendada: Uso de camiseta, cobertura pessoal e protetor solar."));
    delay(50);
  }
  if (uv_level >= 1380 && uv_level < 1839)
  {
    index_uv = uv_level/230;
    Serial.print(F("ALTO - "));
    Serial.println(index_uv);
    Serial.println(F("Proteção recomendada: Uso de camiseta, cobertura pessoal, protetor solar e abrigo."));
    delay(50);
  }
  if (uv_level >= 1840 && uv_level < 2529)
  {
    index_uv = uv_level/230;
    Serial.print(F("MUITO ALTO - "));
    Serial.println(index_uv);
    Serial.println(F("Proteção recomendada: Uso de camiseta, cobertura pessoal, protetor solar, abrigo e oculos escuros."));
    delay(50);
  }
  if (uv_level >= 2530 && uv_level < 2760)
  {
    index_uv = uv_level/230;
    Serial.print(F("EXTREMO - "));
    Serial.println(index_uv);
    Serial.println(F("Proteção recomendada: Não recomendado exposição por mais de 15min com protetor solar e coberturas."));
    delay(50);
  }

  
  //Realiza a publicação dos valores ao MQTT
  sprintf(MsgUV_LEVEL_MQTT,"%u",uv_level);
  clientpub.publish("casa/uvlevel", MsgUV_LEVEL_MQTT);
  
  sprintf(MsgUV_INDEX_MQTT,"%u",index_uv);
  clientpub.publish("casa/uvindex", MsgUV_INDEX_MQTT);

}
//---------------------------------------------------------
