void RTC_start() 
{
   rtc.begin();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F("CLOCK"));
    lcd.setCursor(0,1);
    lcd.print(F("SET OK"));
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(F(" HORA ->"));
    chamaHora();
    lcd.setCursor(1,1);
    lcd.print(Hor);                   // Imprime a Hora
    lcd.print(":");                   // Imprime o texto entre aspas
    lcd.print(Min);                   // Imprime o Minuto
    //lcd.print(":");                   // Imprime o texto entre aspas
    //lcd.print(Seg);                   // Imprime o Segundo
    delay(2000);
    return;
    
}
//------------------------------------------------------

void ajustarRTC()
{
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__))); //ajuste automatico da data e hora, conforme horario e data da compilação do cod
  //etc.adjust(DateTime(2021, 11, 29, 10, 23, 00)); //Opção 2: ajuste manual (Ano, Mes, Dia, Hora, Min, Seg)
}
//------------------------------------------------------

void chamaHora()
{
  nowrtc = rtc.now();
  Hor = rtc.now().hour();     // Chama o horário de Hor
  delay(100);
  Min = rtc.now().minute();   // Chama o minuto de Min
  delay(100);
  Seg = rtc.now().second();   // Chama os segundos de Seg
}
//--------------------------------------------------------

void chamaData()
{
  nowrtc = rtc.now();
  dia = rtc.now().day(); //chama o dia corrente
  delay(100);
  mes = rtc.now().month(); //chama o mes corrente
  delay(100);
  ano = rtc.now().year()-2000; //chama o ano corrente
}
//---------------------------------------------------------
