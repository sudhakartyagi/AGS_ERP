#include<iostream>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include<QString>
#include<QVariant>

#include "ags_fine_head.h"
#include "ags_database.h"


ags_fine_head::ags_fine_head()
{

}

ags_fine_head::~ags_fine_head()
{
    delete m_fineHdModel;
}

void ags_fine_head::ags_set_fine_head(QString agsFineHead)
{
    m_fineHead = agsFineHead;
}

void ags_fine_head::ags_set_fine_amnt(QString agsFineAmnt)
{
    m_fineAmnt = agsFineAmnt;
}

void ags_fine_head::ags_set_fine_remarks(QString agsFineRemarks)
{
    m_fineRmarks = agsFineRemarks;
}

void ags_fine_head::ags_set_fine_due_date(QString agsFineDueDate)
{
    m_fineDueDate = agsFineDueDate;
}

void ags_fine_head::ags_set_fine_current_view_id(QString fineHeadId)
{
    m_fineCurrViewId = fineHeadId;
}

void ags_fine_head::ags_save_fine_head_into_db(void)
{
    if(ags_database::m_db.open())
    {
        std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("INSERT INTO fine_policy (fine_head,fine_amount,fine_due_date,remarks)"
                     "VALUES(:fine_head,:fine_amount,:fine_due_date,:remarks)");

         qry.bindValue(":fine_head",     m_fineHead);
         qry.bindValue(":fine_amount",   m_fineAmnt);
         qry.bindValue(":fine_due_date", m_fineDueDate);
         qry.bindValue(":remarks",       m_fineRmarks);

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
}


void ags_fine_head::ags_updt_fine_head_into_db(void)
{
    if(ags_database::m_db.open())
    {
         std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("UPDATE fine_policy SET fine_head='" + m_fineHead + "', fine_amount='"+m_fineAmnt+"', fine_due_date='"+m_fineDueDate+"', remarks='"+m_fineRmarks+"'"
                     "WHERE idfine_policy='" + m_fineCurrViewId + "'");

         qry.bindValue(":fine_head",     m_fineHead);
         qry.bindValue(":fine_amount",   m_fineAmnt);
         qry.bindValue(":fine_due_date", m_fineDueDate);
         qry.bindValue(":remarks",       m_fineRmarks);

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
}

void ags_fine_head::ags_del_fine_head_from_db(void)
{
    if(ags_database::m_db.open())
    {
        QSqlQuery qry(ags_database::m_db);

        qry.prepare("DELETE FROM fine_policy WHERE idfine_policy ='" + m_fineCurrViewId + "'");

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

QSqlQueryModel *ags_fine_head::get_fine_head_db_model(void)
{
    if(ags_database::m_db.open())
    {
        m_fineHdModel = new QSqlQueryModel; /*memory mgt required*/
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fine_policy");
        query->exec(); /*Error check later*/

        m_fineHdModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_fineHdModel;
}

QSqlQueryModel *ags_fine_head::get_sel_fine_head_db_model(QString fineHeadID)
{
    if(ags_database::m_db.open())
    {
        m_fineHdModel = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM fine_policy WHERE idfine_policy ='" + fineHeadID + "'");
        query->exec(); /*Error check later*/

        m_fineHdModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_fineHdModel;
}

