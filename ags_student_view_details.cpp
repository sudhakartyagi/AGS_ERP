#include "ags_database.h"
#include "ags_student_view_details.h"

#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>


ags_std_details::ags_std_details()
{

}


ags_std_details::~ags_std_details()
{
    delete m_stdDataModel;
}

void ags_std_details::set_std_name(QString stdName)
{
    m_stdName = stdName;
}

void ags_std_details::set_std_fath_name(QString stdFathName)
{
    m_stdFathName = stdFathName;
}

void ags_std_details::set_std_SR_num(QString stdSRNum)
{
    m_stdSRNum = stdSRNum;
}

void ags_std_details::set_std_class(QString stdClass)
{
    m_stdClass = stdClass;
}

void ags_std_details::set_std_curr_id(QString stdID)
{
    m_curStdId = stdID;
}

QSqlQueryModel *ags_std_details::getStdDbModel(void)
{
    if(ags_database::m_db.open())
    {
        m_stdDataModel   = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM ags_std_record");
        query->exec(); /*Error check later*/

        m_stdDataModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_stdDataModel;
}


QSqlQueryModel *ags_std_details::get_std_details(QString stdId)
{
    if(ags_database::m_db.open())
    {
        m_stdDataModel   = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT * FROM ags_std_record WHERE id_std_record='" + stdId + "'");
        query->exec(); /*Error check later*/

        m_stdDataModel->setQuery(*query);
    }

    ags_database::m_db.close();

    return m_stdDataModel;
}

void ags_std_details::ags_del_std_from_db(void)
{
    if(ags_database::m_db.open())
    {
        QSqlQuery qry(ags_database::m_db);

        qry.prepare("DELETE FROM ags_std_record WHERE id_std_record ='" + m_curStdId + "'");

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

QString ags_std_details::ags_get_current_std_id()
{
    return m_curStdId;
}
