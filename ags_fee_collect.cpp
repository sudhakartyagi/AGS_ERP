#include "ags_database.h"
#include "ags_fee_collect.h"

#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QDate>



ags_fee_collect::ags_fee_collect()
{

}


ags_fee_collect::~ags_fee_collect()
{
    delete m_stdDataModel;
}


QSqlQueryModel *ags_fee_collect::ags_get_std_db_model(void)
{
    if(ags_database::m_db.open())
    {
        m_stdDataModel = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM ags_std_record");
        query->exec(); /*Error check later*/

        m_stdDataModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_stdDataModel;
}


QSqlQueryModel *ags_fee_collect::ags_get_fee_db_model(QString stdId)
{
    if(ags_database::m_db.open())
    {
        m_stdDataModel   = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fee_details WHERE student_id='" + stdId + "'");
        query->exec(); /*Error check later*/

        m_stdDataModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_stdDataModel;
}


QSqlQueryModel *ags_fee_collect::ags_get_fee_details_model(QString stdClass, QString feeHead)
{
    //QArrayData monthName = {"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov"};
    if(ags_database::m_db.open())
    {
        m_stdDataModel   = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fee_head WHERE fee_head='" + feeHead + "AND applicable_class='" + stdClass+ "'");
        query->exec(); /*Error check later*/

        //QDate currDate = QDate::currentDate();
        //int   feeMonth = currDate.month();

        if (query->value(3).toString().contains("")) {


        }
        m_stdDataModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_stdDataModel;
}


