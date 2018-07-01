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

void ags_fee_module::set_curr_std_id(QString stdID)
{
    m_stdID = stdID;
}

void ags_fee_module::set_curr_std_unpd_mnth(QString undpMnth)
{
    m_unpdMonth = undpMnth;
}

void ags_fee_module::set_curr_std_unpd_amnt(int unpdAmnt)
{
    m_unpdAmnt = unpdAmnt;
}

void ags_fee_module::set_curr_std_curr_ball(int currBal)
{
    m_currBal = currBal;
}

QSqlQueryModel *ags_fee_module::getStdDbModel(void)
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


QSqlQueryModel *ags_fee_module::getFeeDbModel(QString stdId)
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

int ags_fee_module::get_all_applicable_fee(QString stdCls, QString curMonth)
{
    int aplFee = -1;

    if(ags_database::m_db.open())
    {
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fee_head WHERE applicable_class ='" + stdCls + "'");
        query->exec(); /*Error check later*/

        do {

            if (query->value(4).toString().contains(curMonth)) {

                aplFee = aplFee + query->value(2).toInt();
            }

        } while ((query->next()));
    }

    ags_database::m_db.close();

    return aplFee;
}

void ags_fee_module::insrt_fee_for_this_stds(void)
{
    if(ags_database::m_db.open())
    {
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("INSERT INTO fee_unpaid (student_id,unpaid_amnt,unpaid_mnth,current_bal)"
                       "VALUES(:student_id,:unpaid_amnt,:unpaid_mnth,:current_bal)");

        query->bindValue(":student_id",  m_stdID);
        query->bindValue(":unpaid_amnt", m_unpdAmnt);
        query->bindValue(":unpaid_mnth", m_unpdMonth);
        query->bindValue(":current_bal", m_currBal);

        query->exec();
    }

    ags_database::m_db.close();

}

