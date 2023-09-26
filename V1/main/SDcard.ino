void initSD()
{
  if (SD.begin(pinoCS)){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("MEM CARD"));
    lcd.setCursor(0,1);
    lcd.print(F("   OK   "));
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("MEM CARD"));
    lcd.setCursor(0,1);
    lcd.print(F("NOTFOUND"));
    //colocar um barulho de buzzzer aqui
    return;
  }
}
//-------------------------------------

/*
void gravalogDHT()
{
  logFile = SD.open("logfile.txt", FILE_WRITE);
  if (logFile)
  {
    chamaHora();
    chamaData();
    logFile.print(String(Hor) + ":" + String(Min) + ":" + String(Seg) + " | ");
    logFile.print(String(dia) + "/" + String(mes) + "/" + String(ano) + " | ");
    logFile.print("Temperatura: ");
    logFile.print(temperatura);
    logFile.print("ºC, ");
    logFile.print("Umidade: ");
    logFile.print(umidade);
    logFile.println("%");
    logFile.close();
    digitalWrite(statusled, HIGH);
    delay(50);
    digitalWrite(statusled, LOW);
        
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BAD FILE"));
    lcd.setCursor(0,1);
    lcd.print(F("RESETING"));
    delay(3000);
    Reseting();
  }
}
*/

//-------------------------------------

void gravalogLDR()
{
  logFile = SD.open("logfile.txt", FILE_WRITE);
  if (logFile)
  {
    logFile.print("LDR Puro: ");
    logFile.print(LDR);
    logFile.print("Res, ");
    logFile.print("Radiancia: ");
    logFile.print(rad);
    logFile.println("WM2");
    logFile.close();
    digitalWrite(statusled, HIGH);
    delay(50);
    digitalWrite(statusled, LOW);
        
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BAD FILE"));
    lcd.setCursor(0,1);
    lcd.print(F("RESETING"));
    delay(3000);
    Reseting();
  }
}

//--------------------------------------

void gravaLOG_BMP()
{
  logFile = SD.open("logfile.txt", FILE_WRITE);
  if (logFile)
  {
    logFile.print(F("Temperatura: "));
    logFile.print(temperatura);
    logFile.print(F("ºC, "));
    logFile.print(F("Altitude: "));
    logFile.print(altitude);
    logFile.print(F("Mts, "));
    logFile.print(F("Pressao"));
    logFile.print(pressao);
    logFile.println(F("HPa"));
    logFile.close();
    digitalWrite(statusled, HIGH);
    delay(50);
    digitalWrite(statusled, LOW);
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BAD FILE"));
    lcd.setCursor(0,1);
    lcd.print(F("RESETING"));
    delay(3000);
    Reseting();
  }
}

//--------------------------------------

void gravaLOGDATA()
{
  //logDATA = SD.open("LOGDATA.txt", FILE_WRITE);
  chamaData();
  logDATA = SD.open(String(dia) + "-" + String(mes) + "-" + String(ano) + ".txt", FILE_WRITE);
  if (logDATA)
  {
    chamaHora();
    logDATA.print(String(Hor) + ":" + String(Min) + ":" + String(Seg) + ";");
    //logDATA.print(String(dia) + "/" + String(mes) + "/" + String(ano) + ";");
    logDATA.print(temperatura);
    logDATA.print(";");
    //logDATA.print(umidade); //retirada a umidade de leitura, por fazer parte do DHT
    //logDATA.print(";");
    logDATA.print(altitude);
    logDATA.print(";");
    logDATA.print(pressao);
    logDATA.print(";");
    logDATA.print(LDR);
    logDATA.print(";");
    logDATA.print(rad);
    logDATA.print(";");
    logDATA.print(uv_level);
    logDATA.print(";");
    logDATA.println(uv_level/230);
    logDATA.close();
    digitalWrite(statusled, HIGH);
    delay(50);
    digitalWrite(statusled, LOW);
  } else {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("BAD FILE"));
    lcd.setCursor(0,1);
    lcd.print(F("RESETING"));
    delay(3000);
    Reseting();
  }
}

//----------------------------------------
