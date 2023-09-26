void BMP_init()
{
  if (!bmp180.begin()) //Se o BPM não for inicializado e/ou não encontrado
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BMP BAD"));
    lcd.setCursor(0,1);
    lcd.print(F("NOTFOUND"));
    delay(2000);
    Reseting();
  } else { //se ele for encontrado e/ou iniciado
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BMP180->"));
    lcd.setCursor(0,1);
    lcd.print(F("   OK   "));
  }
  return;
}
//----------------------------------------

void lerBMP()
{
  temperatura = bmp180.readTemperature();
  delay(100);
  altitude = bmp180.readAltitude();
  delay(100);
  pressao = bmp180.readPressure();
  return;
}
//-----------------------------------------

void BMP_screen()
{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("T:"));
  lcd.print(temperatura);
  lcd.write(0);//chama o char personalizado de graus celcius
  lcd.setCursor(0,1);
  lcd.print(F("P:"));
  lcd.print(pressao);
  lcd.print(F("h"));
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Alt:"));
  lcd.setCursor(0,1);
  lcd.print(altitude);
  lcd.print(F(" M"));
  delay(5000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("T:"));
  lcd.print(temperatura);
  lcd.write(0);//chama o char personalizado de graus celcius
  lcd.print(F("C"));
  lcd.setCursor(0,1);
  lcd.print(F("P:"));
  lcd.print(pressao);
  lcd.print(F("h"));
  return;
}
//-----------------------------------------
