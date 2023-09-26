void init_RTC ()
{

//inicializa o modulo RTC, se não encontrar, informa no log
  if (!DS1307_RTC.begin()) {
    Serial.println(F("Modulo RTC não encontrado"));
    
  }

  //Ajusta o modulo com o computador que está compilando
  //DS1307_RTC.adjust(DateTime(F(__DATE__), F(__TIME__))); 
  DS1307_RTC.adjust(DateTime(epochtime_ntp));

  now = DS1307_RTC.now();
  delay(100); 

  Serial.println("<<<RTC AJUSTADO COM O NTP>>>");
  get_time_RTC();

/*Serial.println(F("Hora do módulo RTC (inicio): "));

    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
*/
}

void get_time_RTC()
{

  now = DS1307_RTC.now();
  delay(100);

  Serial.println(F("Hora do módulo RTC (Incremento): "));

int _hour = now.hour();
if (_hour < 10){ HH = "0" + String(_hour); }
else { HH = String(_hour); }

int _minute = now.minute();
if (_minute < 10){ mm = "0" + String(_minute); }
else { mm = String(_minute); }

int _second = now.second();
if (_second < 10){ ss = "0" + String(_second); }
else { ss = String(_second); }

Formated_RTC_time = HH + ":" + mm + ":" + ss;

Serial.println(Formated_RTC_time);
Serial.println();

/*


    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
*/

}

void get_date_RTC()
{

now = DS1307_RTC.now();
delay(100);

int _day = now.day();
if (_day < 10) {DD = "0" + String(_day); }
else { DD = _day; }

int _month = now.month();
if (_month < 10) {MM = "0" + String(_month);}
else {MM = String(_month);} 

year = now.year();

Formated_RTC_date = DD + "/" + MM + "/" + String(year);

Serial.println("<<<Data Corrente RTC>>>");
Serial.println(Formated_RTC_date);
Serial.println();

}

void get_unixtime_RTC()
{

now = DS1307_RTC.now();
delay(100);

RTC_unixtime = now.unixtime();
RTC_unixtime += 10800;

Serial.println("<<<UNIX_TIME RTC>>>");
Serial.println(RTC_unixtime);
Serial.println();

}
