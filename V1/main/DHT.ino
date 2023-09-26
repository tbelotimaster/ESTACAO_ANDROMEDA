/* void DHT_test()
{

byte temp; //Define variavel local para a leitura de teste da temperatura
byte umid; //Define variavel local para a leitura de teste da umidade
  
    dht.begin();//inicia o sensor, esse metodo não aceita converção para bool, não se pode testar com if
    temp = dht.readTemperature();
    umid = dht.readHumidity();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("TEST DHT"));
    delay(350);
    if (isnan(temp) || isnan(umid)) //(ISNAN = is not a number) se as leituras não forem numericas, houve algum erro 
    {
        lcd.setCursor(0,1);
        lcd.print(F("  BAD!  "));
        delay(1000);
        flag_dht_status = 1;
        return;
    } else { //caso contrario, se as leituras forem numericas
      lcd.setCursor(0,1);
      lcd.print(F("   OK   "));
      delay(1000);
      
    }
}

//------------------------------------------------
void trocar_DHT()
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(F(" TROCAR "));
   lcd.setCursor(0,1);
   lcd.print(F("  DHT  "));
   //faz o led do pino 13 blikar 2x
  digitalWrite(statusled, HIGH);
  delay(500);
  digitalWrite(statusled, LOW);
  delay(300);
  digitalWrite(statusled, HIGH);
  delay(500);
  digitalWrite(statusled, LOW);
  // colocar um som de buzzer aqui de reprovação
  delay(5000);
      
}

//-------------------------------------------------
void temp_umid()
{
  
  temperatura = dht.readTemperature();//recebe a temperatura
  delay(300);
  umidade = dht.readHumidity();//recebe a umidade
  delay(300);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("TEMP:"));
  lcd.setCursor(5,0);
  lcd.print(temperatura);
  lcd.setCursor(7,0);
  lcd.write(0);//chama o char personalizado de graus celcius
  lcd.setCursor(0,1);
  lcd.print(F("UMID:"));
  lcd.setCursor(5,1);
  lcd.print(umidade);
  lcd.setCursor(7,1);
  lcd.print(F("%"));
  

}

//--------------------------------------------------
*/
