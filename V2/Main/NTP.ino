void init_NTP()
{

    //Inicializa o client NTP
    ntpClient.begin();
    Serial.println(F("<<<Cliente NTP a.ntp.br conectado.>>>"));
    Serial.println();
    
}

void lerHORA()
{

//varianeis locais de escrita ao MQTT
  char MsgTIME_NTP[8];

  ntpClient.update();
  delay(50);

  //hora atual formatada
  hora_ntp = ntpClient.getFormattedTime().c_str();

  //UNIX time (epoch) atual
  epochtime_ntp = ntpClient.getEpochTime();

//DEBUG
Serial.println("<<<<Data atual NTP>>>>");
Serial.println(hora_ntp);
Serial.println("epoch NTP");
Serial.println(epochtime_ntp);


//Realiza a publicação dos valores ao MQTT
  sprintf(MsgTIME_NTP,"%u",hora_ntp);
  clientpub.publish("casa/timentp", MsgTIME_NTP);

}

//----------------------------------------------------------------------
