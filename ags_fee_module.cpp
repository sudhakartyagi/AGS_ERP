#include "ags_database.h"
#include "ags_fee_module.h"
#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>



ags_fee_module::ags_fee_module()
{

}


ags_fee_module::~ags_fee_module()
{
    delete m_stdDataModel;
}

QSqlQueryModel *ags_fee_module::getStdDbModel(void)
{
    m_stdDataModel = new QSqlQueryModel;
    QSqlQuery* query = new QSqlQuery(ags_database::m_db);

    query->prepare("SELECT * FROM ags_std_record");
    query->exec(); /*Error check later*/

    m_stdDataModel->setQuery(*query);

    return m_stdDataModel;
}

QSqlQueryModel *ags_fee_module::getFeeDbModel(QString stdId)
{
    m_stdDataModel   = new QSqlQueryModel;
    QSqlQuery* query = new QSqlQuery(ags_database::m_db);

    query->prepare("SELECT * FROM fee_details WHERE student_id='" + stdId + "'");
    query->exec(); /*Error check later*/

    m_stdDataModel->setQuery(*query);

    return m_stdDataModel;
}

