#include "ags_database.h"
#include <iostream>
#include <QtSql/QSqlDatabase>


QSqlDatabase ags_database::m_db;


ags_database::ags_database()
{

}


ags_database::~ags_database()
{

}



/*No need to delete the memory associated with this pointer*/
void ags_database::ags_get_db_instance(QString agsDbName)
{
    m_db = QSqlDatabase::addDatabase("QMYSQL");
    m_db.setHostName("localhost");
    m_db.setUserName("lotar");
    m_db.setPassword("lotar");
    m_db.setDatabaseName(agsDbName);
}


