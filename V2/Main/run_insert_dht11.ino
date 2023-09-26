void run_insert_dht11()
{

String INSERT_DHT11 = String("INSERT INTO ") + default_database + "." + table_DHT11
                        + " (temperatura, umidade, human_date, human_time, epoch) VALUES ("
                        + temperatura01_now + "," + umidade_now + "," + "'" +Formated_RTC_date+"','"+Formated_RTC_time
                        +"'," + RTC_unixtime +");";

//DEBUG
Serial.println("<<<QUERY INSERT DHT11>>>");
Serial.println(INSERT_DHT11);
Serial.println(); 

// Initiate the query class instance
  MySQL_Query query_mem_dht11 = MySQL_Query(&conn);

//Executa a query, verifica se os dados foram inseridos no banco
if (conn.connected())
{
  if ( !query_mem_dht11.execute(INSERT_DHT11.c_str()) )
  {
    Serial.println("<<<INSERT ERROR>>>");
    Serial.println();
  }
  else
  {
    Serial.println("<<<DATA QUERY INSERTED>>>");
    Serial.println();
  }
}
else
{
  Serial.println("<<<Disconectado do server, Query NÃO inserida");
  Serial.println();
}

}

