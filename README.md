# Query Builder send to  Report Generator

*In this code, we are going to generate different queries using query builder and then send a reporter*

## Query Builder
*we use SQLEO Query* 
1. free
2. postgresql
3. linux
**Download**
**[link](https://sourceforge.net/projects/sqleo/)**
add jbdc for postgersql
**[link](https://jdbc.postgresql.org/download/postgresql-42.3.4.jar)**

## Repot Generator
 *use link* [Github](https://github.com/HOOSHANKAVOSHBORNA/REPORTGENERATOR)

## use 
1. *connect database to config.ini*

`QString  strKey("admin/");
  settings  =  new  QSettings("path",QSettings::IniFormat);
  m_db  =  QSqlDatabase::addDatabase("QPSQL","DBconnection");
  m_db.setHostName(settings->value(strKey  +  "Hostname", "r").toString());
  m_db.setDatabaseName(settings->value(strKey  +  "DataBaseName",  "r").toString());
  m_db.setUserName(settings->value(strKey  +  "UserName",  "r").toString());
  m_db.setPassword(settings->value(strKey  +  "Password",  "r").toString());`

2. *run SQLeo Query*

`QString  program  =  "java"; 
  QStringList  argoman;
  argoman<<"-jar";
  argoman<<"path";
  QProcess  *  myprocess  =  new  QProcess(qApp);
  myprocess  ->execute(program,argoman);
  myprocess->waitForFinished();`


3.*run ReportGenerator*
		*set query build*
`report->dataManager()->addModel("Test",customersModel,true);`			*set form xml*
`  report->loadFromFile(":/change_item_from_script.lrxml");`

	

