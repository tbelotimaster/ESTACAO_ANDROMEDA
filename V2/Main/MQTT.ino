void reconect_MQTT() {  //reconecta ao broker
  //Enquanto estiver desconectado
  while (!clientpub.connected()) {
    Serial.println(F("Tentando conectar ao servidor MQTT"));
         
    bool conectado = strlen(mqttUser) > 0 ?
                     clientpub.connect("ESP8266Client_estacao1", mqttUser, mqttPassword) :
                     clientpub.connect("ESP8266Client_estacao1");
 
    if(conectado) {
      Serial.println(F("MQTT Reconectado!"));
      //subscreve no tópico
      clientpub.subscribe(mqttTopicSub, 2); //nivel de qualidade: QoS 2
    } else {
      Serial.println(F("Falha durante a conexão.Code: "));
      Serial.println( String(clientpub.state()).c_str());
      Serial.println(F("Tentando novamente em 10 s"));
      //Aguarda 10 segundos 
      delay(10000);
    }
  }
}

//----------------------------------------------------------------------------------
void callback(char* topic, byte* payload, unsigned int length) {
 
  //armazena msg recebida em uma sring
  payload[length] = '\0';
  String strMSG = String((char*)payload);
   
  /* 
  //aciona saída conforme msg recebida 
  if (strMSG == "1"){         //se msg "1"
     digitalWrite(L1, LOW);  //coloca saída em LOW para ligar a Lampada - > o módulo RELE usado tem acionamento invertido. Se necessário ajuste para o seu modulo
  }else if (strMSG == "0"){   //se msg "0"
     digitalWrite(L1, HIGH);   //coloca saída em HIGH para desligar a Lampada - > o módulo RELE usado tem acionamento invertido. Se necessário ajuste para o seu modulo
  }
  */ 
  
}

//----------------------------------------------------
void init_MQTT()
{
  clientpub.setServer(mqttServer, mqttPort);
  clientpub.setCallback(callback);

  while (!clientpub.connected()) {
    Serial.println(F("Conectando ao Broker MQTT..."));
     
    if (clientpub.connect("ESP8266Client", mqttUser, mqttPassword )) {
      Serial.println(F("Conectado!"));
      Serial.println("");  
       
    } else {
      Serial.print(F("falha estado  "));
      Serial.print(clientpub.state());
      delay(2000); //espera 2 segundos
 
    }
  }
  
}
//-----------------------------------------------------
