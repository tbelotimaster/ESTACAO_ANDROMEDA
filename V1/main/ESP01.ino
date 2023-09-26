/*
void connectWIFI()
{
  
  WiFi.begin(ssid, password);
    if (WiFi.status() != WL_CONNECTED)
    {
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("WIFI"));
      lcd.setCursor(0,1);
      lcd.print(F("CONN OK"));
      delay(500);
      //debug
      Serial.println(WiFi.localIP());
      //debug
      delay(2000);
      return;
    } else {
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(F("WIFI"));
      lcd.setCursor(0,1);
      lcd.print(F("CONN BAD"));
      delay(2000);
      return;
    }
} */

//------------------------------------------
