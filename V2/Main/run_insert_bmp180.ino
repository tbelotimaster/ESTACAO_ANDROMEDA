void run_insert_bmp180()
{
//Query para executar a inserção dos valores do sensores no banco, na tabela correspondente
//  String INSERT_BMP180 = String("INSERT INTO ") + default_database + "." + table_BMP180
//                        + " (temperatura, press_rel, press_abs, human_date, human_time, utc_time) VALUES ("
//                        + bmp_temp + "," + pressao_relativa + "," + pressao + ",'" +Formated_RTC_date+"','"+Formated_RTC_time
//                        +"'," + RTC_unixtime +");";

String INSERT_BMP180 = String("INSERT INTO ") + default_database + "." + table_BMP180
                        + " (temperatura, press_rel, press_abs, human_date, human_time, epoch) VALUES ("
                        + bmp_temp + "," + pressao_relativa + "," + pressao + ",'" +Formated_RTC_date+"','"+Formated_RTC_time
                        +"'," + RTC_unixtime +");";

//DEBUG
Serial.println("<<<QUERY INSERT BMP180>>>");
Serial.println(INSERT_BMP180);
Serial.println(); 

  // Initiate the query class instance
  MySQL_Query query_mem_bmp180 = MySQL_Query(&conn);


//Executa a query, verifica se os dados foram inseridos no banco
if (conn.connected())
{
  if ( !query_mem_bmp180.execute(INSERT_BMP180.c_str()) )
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