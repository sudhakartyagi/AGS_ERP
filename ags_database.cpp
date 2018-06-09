#include "ags_database.h"
#include <iostream>


ags_database::ags_database()
{

}


ags_database::~ags_database()
{
}


void ags_database::ags_setup_db(QString agsDbName)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");

    m_db.setDatabaseName(agsDbName);

    if (!m_db.open()) {

        std::cout << "Error: connection with database fail";
    } else {

        std::cout << "Database: connection ok";
    }
}


