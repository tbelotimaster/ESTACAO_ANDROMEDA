void VEML6070_test()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("UV TEST"));
  uv_sensor.begin(VEML6070_1_T); //setando o tempo para amostragem de luz(integration time), 600ms de espera de captura
                                //valores possiveis VEML6070_x_T sendo x = 1 até 4
  //uv_level = uv_sensor.readUV()/230;
  index_uv = uv_sensor.readUV();
  lcd.setCursor(0,1);
  lcd.print(index_uv);
  delay(2000);
}
//----------------------------------------------

void VEML6070_show()
{
  uv_level = uv_sensor.readUV();
  delay(50);
  index_uv = uv_level;
  delay(300);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("NIVEL UV"));
  if (uv_level >= 0 && uv_level < 689){
    lcd.setCursor(0,1);
    lcd.print(index_uv/230);
    lcd.println(F(" LOW"));
    //debug
    Serial.print(uv_level);
    //debug
    delay(2000);
  }
  if (uv_level >= 690 && uv_level < 1379) {
    lcd.setCursor(0,1);
    lcd.print(index_uv/230);
    lcd.print(F(" MOD"));
    delay(2000);
  }
  if (uv_level >= 1380 && uv_level < 1839) {
    lcd.setCursor(0,1);
    lcd.print(index_uv/230);
    lcd.print(F(" A+"));
    delay(2000);
  }
  if (uv_level >= 1840 && uv_level < 2529) {
    lcd.setCursor(0,1);
    lcd.print(index_uv/230);
    lcd.print(F(" A++"));
    delay(2000);
  }
  if (uv_level >= 2530 && uv_level < 2760) {
    lcd.setCursor(0,1);
    lcd.print(index_uv/230);
    lcd.print(F("A+++"));
    delay(2000);
  }
  return;
} 
//----------------------------------------------
