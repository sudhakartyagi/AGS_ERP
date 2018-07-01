#include<iostream>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include<QString>
#include<QVariant>

#include "ags_fee_head.h"
#include "ags_database.h"


ags_fee_head::ags_fee_head()
{

}

ags_fee_head::~ags_fee_head()
{
    delete m_feeHdModel;
}

void ags_fee_head::ags_set_fee_head(QString agsFeeHead)
{
    m_feeHead = agsFeeHead;
}

void ags_fee_head::ags_set_fee_amnt(QString agsFeeAmnt)
{
    m_feeAmnt = agsFeeAmnt;
}

void ags_fee_head::ags_set_fee_remarks(QString agsFeeRemarks)
{
    m_feeRmarks = agsFeeRemarks;
}

void ags_fee_head::ags_set_fee_app_class(QString agsFeeAppClass)
{
    m_feeAppClass = agsFeeAppClass;
}

void ags_fee_head::ags_set_fee_current_view_id(QString feeHeadId)
{
    m_feeCurrViewId = feeHeadId;
}

void ags_fee_head::ags_set_fee_app_months(int agsFlg, QString agsFeeAppMonths)
{
    if (agsFlg) { /* Add String */

        m_feeAppMoths += agsFeeAppMonths + ",";
    } else { /* Remove String */

        if (m_feeAppMoths.contains(agsFeeAppMonths)) {

            m_feeAppMoths.replace(agsFeeAppMonths, "");
            m_feeAppMoths.replace(",,", ",");
        }
    }
}

void ags_fee_head::ags_save_fee_head_into_db(void)
{
    if(ags_database::m_db.open())
    {
        std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("INSERT INTO fee_head (fee_head,fee_amount,applicable_class,applicable_months,remarks)"
                     "VALUES(:fee_head,:fee_amount,:applicable_class,:applicable_months,:remarks)");

         qry.bindValue(":fee_head",   m_feeHead);
         qry.bindValue(":fee_amount", m_feeAmnt);
         qry.bindValue(":applicable_class",m_feeAppClass);
         qry.bindValue(":applicable_months",m_feeAppMoths);
         qry.bindValue(":remarks",   m_feeRmarks);

         if( !qry.exec() ) {

            QString temp = qry.lastError().text();
            std::cout << "Sql Error";
            //std::cout << qry.lastError().text();
         } else {
             std::cout << "Inserted!";
         }
    } else {

        QString tempig  = ags_database::m_db.lastError().text();
        QStringList tempig2 = ags_database::m_db.drivers();
        std::cout << "Sql Error";
    }

    ags_database::m_db.close();
    m_feeAppMoths = "";
}


void ags_fee_head::ags_updt_fee_head_into_db(void)
{
    if(ags_database::m_db.open())
    {
         std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("UPDATE fee_head SET fee_head='" + m_feeHead + "', fee_amount='"+m_feeAmnt+"', applicable_class='"+m_feeAppClass+"', applicable_months='"+m_feeAppMoths+"', remarks='"+m_feeRmarks+"'"
                     "WHERE idfee_head='" + m_feeCurrViewId + "'");

         qry.bindValue(":fee_head",   m_feeHead);
         qry.bindValue(":fee_amount", m_feeAmnt);
         qry.bindValue(":applicable_class",m_feeAppClass);
         qry.bindValue(":applicable_months",m_feeAppMoths);
         qry.bindValue(":remarks",   m_feeRmarks);

         if( !qry.exec() ) {

            QString temp = qry.lastError().text();
            std::cout << "Sql Error";
            //std::cout << qry.lastError().text();
         } else {
             std::cout << "Inserted!";
         }
    } else {

        QString tempig  = ags_database::m_db.lastError().text();
        QStringList tempig2 = ags_database::m_db.drivers();
        std::cout << "Sql Error";
    }

    ags_database::m_db.close();
    m_feeAppMoths = "";
}

void ags_fee_head::ags_del_fee_head_from_db(void)
{
    if(ags_database::m_db.open())
    {
        QSqlQuery qry(ags_database::m_db);

        qry.prepare("DELETE FROM fee_head WHERE idfee_head ='" + m_feeCurrViewId + "'");

        if( !qry.exec() ) {

           QString temp = qry.lastError().text();
           std::cout << "Sql Error";
           //std::cout << qry.lastError().text();
        } else {
            std::cout << "Inserted!";
        }
    }

    ags_database::m_db.close();
}

QSqlQueryModel *ags_fee_head::getFeeHeadDbModel(void)
{
    if(ags_database::m_db.open())
    {
        m_feeHdModel = new QSqlQueryModel; /*memory mgt required*/
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fee_head");
        query->exec(); /*Error check later*/

        m_feeHdModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_feeHdModel;
}

QSqlQueryModel *ags_fee_head::getSelFeeHeadDbModel(QString feeHeadID)
{
    if(ags_database::m_db.open())
    {
        m_feeHdModel = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fee_head WHERE idfee_head ='" + feeHeadID + "'");
        query->exec(); /*Error check later*/

        m_feeHdModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_feeHdModel;
}
