void lerLDR()
{
  LDR = analogRead(LDRpin);
  tensao = LDR*(3.3/4095.0);
  tensao2 = tensao*(5.5/3.3);
  rad = 4464.9*exp(-17.73*tensao2);
  
}

//-------------------------------------------------------

void LDR_test ()
{

float ldr_val;

ldr_val = analogRead(LDRpin);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("TEST LDR"));
    delay(100);
    if (isnan(ldr_val))//(ISNAN = is not a number) se as leituras não forem numericas, houve algum erro 
    {
        lcd.setCursor(0,1);
        lcd.print(F("  BAD!  "));
        delay(1000);
        flag_ldr_status = 1;
        return;
    } else { //caso contrario, se as leituras forem numericas
      lcd.setCursor(0,1);
      lcd.print(F("   OK   "));
      delay(1000);
      
    }
  
}

//-------------------------------------------------------
void trocar_LDR()
{
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print(F(" TROCAR "));
   lcd.setCursor(0,1);
   lcd.print(F("  LDR  "));
   //faz o led do pino 13 blikar 2x
  digitalWrite(statusled, HIGH);
  delay(500);
  digitalWrite(statusled, LOW);
  delay(300);
  digitalWrite(statusled, HIGH);
  delay(500);
  digitalWrite(statusled, LOW);
  // colocar um som de buzzer aqui de reprovação
  delay(2000);
      
}
//---------------------------------------------------------

void mostra_LDR()
{
  LDR = analogRead(LDRpin);
  tensao = LDR*(3.3/4095.0);
  tensao2 = tensao*(5.5/3.3);
  rad = 4464.9*exp(-17.73*tensao2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(F("Res:"));
  lcd.setCursor(5,0);
  lcd.print(LDR);
  lcd.setCursor(0,1);
  lcd.print(F("Rad:"));
  lcd.setCursor(5,1);
  lcd.print(rad);
    
}

//---------------------------------------------------------
