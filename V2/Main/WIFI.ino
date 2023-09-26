void conecta_wifi()
{
  /* Se ja estiver conectado, nada é feito. */
    if (WiFi.status() == WL_CONNECTED)
    {
        return;
    }
      
    /* refaz a conexão */
    WiFi.begin(SSID_REDE, SENHA_REDE);
      
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(100);
    }
  
    Serial.println(F("Conectado com sucesso a rede wi-fi \n"));
    Serial.println(SSID_REDE);
    Serial.println(WiFi.localIP());
    Serial.println("");
}

//--------------------------------------------------------------------
void init_wifi()
{
  Serial.println(F("---Wifi---"));
  Serial.println(F("Conectando-se a rede: "));
  Serial.println(SSID_REDE);
  Serial.println(F("\nAguarde..."));

  conecta_wifi();
  
}

//--------------------------------------------------------------------
void verifica_conexao_wifi()
{
  conecta_wifi();
}

//--------------------------------------------------------------------
