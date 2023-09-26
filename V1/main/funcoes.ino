//função para fazer o reset via software, usando ponteiro de memoria para o inicio da RAM
void(* resetFunc)(void) = 0; //declarando a função de reset no endereço 0
//fim da função de reset

//----------------------------

void Reseting() //faz um reset com a animação via software
{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("RESETING"));
    lcd.setCursor(0,1);
    lcd.print(F("."));
    delay(500);
    lcd.setCursor(1,1);
    lcd.print(F("..."));
    delay(500);
    lcd.setCursor(4,1);
    lcd.print(F("...."));
    delay(1000);
    resetFunc();
}

//----------------------------

void Splash()
{
  //splash screen no LCD 8x2

lcd.clear();
lcd.setCursor(0,0);
lcd.print(F("ESTACAO"));
lcd.setCursor(0,1);
lcd.print(F("VER1.0"));
//colocar um beep no buzer futuramente
delay(3000); //aguarda 3 segundos

}

//------------------------------

void Home()
{
  
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("  HOME  "));
  lcd.setCursor(0,1);
  lcd.print(F("OPCAO1&2"));
  return;
}

//----------------------------------
