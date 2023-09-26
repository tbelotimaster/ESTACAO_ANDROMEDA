void run_insert_yl83()
{

String INSERT_YL83 = String("INSERT INTO ") + default_database + "." + table_YL83
                        + " (chuva_flag, intensidade_valor, human_date, human_time, epoch) VALUES ("
                        + chuva_status + "," + rainAnalogVal + "," + "'" +Formated_RTC_date+"','"+Formated_RTC_time
                        +"'," + RTC_unixtime +");";

//DEBUG
Serial.println("<<<QUERY INSERT YL83>>>");
Serial.println(INSERT_YL83);
Serial.println();

// Initiate the query class instance
  MySQL_Query query_mem_yl83 = MySQL_Query(&conn);

//Executa a query, verifica se os dados foram inseridos no banco
if (conn.connected())
{
  if ( !query_mem_yl83.execute(INSERT_YL83.c_str()) )
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