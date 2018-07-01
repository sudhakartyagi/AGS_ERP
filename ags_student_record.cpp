#include<iostream>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QSqlError>
#include<QList>
#include<QString>
#include<QStringList>
#include<QVariant>

#include "ags_student_record.h"
#include "ags_database.h"


ags_student_record::ags_student_record()
{

}

ags_student_record::~ags_student_record()
{
    delete m_stdDataModel;
}

void ags_student_record::ags_set_std_name(QString agsName)
{
    m_stdName = agsName;
}


void ags_student_record::ags_set_std_mid_name(QString agsMidName)
{
    m_stdMidName = agsMidName;
}


void ags_student_record::ags_set_std_last_name(QString agsLastName)
{
    m_stdLastName = agsLastName;
}



void ags_student_record::ags_set_std_sr_num(QString agsSrNum)
{
    m_stdSrNum = agsSrNum;
}



void ags_student_record::ags_set_std_class(QString agsClass)
{
    m_stdClass = agsClass;
}



void ags_student_record::ags_set_std_cast_rel(QString agsCastRel)
{
    m_stdCastRel = agsCastRel;
}




void ags_student_record::ags_set_std_dob(QDate agsDob)
{
    m_stdDtOfBrth = agsDob;
}



void ags_student_record::ags_set_std_gndr(QString agsGndr)
{
    m_stdGender = agsGndr;
}



void ags_student_record::ags_set_std_gf_name(QString agsGFName)
{
    m_stdGFathName = agsGFName;
}



void ags_student_record::ags_set_std_gm_name(QString agsGMName)
{
    m_stdGMothName = agsGMName;
}



void ags_student_record::ags_set_std_gf_occ(QString agsGFOcc)
{
    m_stdGFathOcc = agsGFOcc;
}



void ags_student_record::ags_set_std_gm_occ(QString agsGMOcc)
{
    m_stdGMOthcc = agsGMOcc;
}



void ags_student_record::ags_set_std_mob_num(QString agsMobNum)
{
    m_stdMobNum = agsMobNum;
}



void ags_student_record::ags_set_std_address(QString agsAddr)
{
    m_stdAddr = agsAddr;
}



void ags_student_record::ags_set_std_locality(QString agsLocality)
{
    m_stdLocality = agsLocality;
}



void ags_student_record::ags_set_std_transport_fee(QString agsTrnsFee)
{
    m_stdTrnsFee = agsTrnsFee;
}


void ags_student_record::ags_set_std_concession(QString agsConssn)
{
    m_stdConssn = agsConssn;
}


QString ags_student_record::ags_get_dspl_name(void)
{
    return m_stdName + m_stdMidName + m_stdLastName;
}


int ags_student_record::ags_save_std_data_into_db(void)
{
    if(ags_database::m_db.open())
    {
        std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("SELECT * FROM ags_std_record WHERE std_sr_num ='" + m_stdSrNum + "'");
         qry.exec(); /*Error check later*/

         if  (0 < qry.size()) {return 0;}

         qry.prepare("INSERT INTO ags_std_record (std_name,std_mid_name,std_last_name,"
                                         "std_sr_num,std_mob_num,std_dob,std_gndr, "
                                         "std_class,std_cast_rel,std_gf_name, "
                                         "std_gf_occ,std_gm_name,std_gm_occ,std_address, "
                                         "std_locality, std_transport_fee, std_concession)"
                     "VALUES(:std_name,:std_mid_name,:std_last_name,"
                            ":std_sr_num,:std_mob_num,:std_dob,:std_gndr, "
                            ":std_class,:std_cast_rel,:std_gf_name,:std_gf_occ, "
                            ":std_gm_name,:std_gm_occ,:std_address,:std_locality,:std_transport_fee,:std_concession)");

         qry.bindValue(":std_name",     m_stdName);
         qry.bindValue(":std_mid_name", m_stdMidName);
         qry.bindValue(":std_last_name",m_stdLastName);
         qry.bindValue(":std_sr_num",   m_stdSrNum);
         qry.bindValue(":std_mob_num",  m_stdMobNum);
         qry.bindValue(":std_dob",      m_stdDtOfBrth.toString());
         qry.bindValue(":std_gndr",     m_stdGender);
         qry.bindValue(":std_class",    m_stdClass);
         qry.bindValue(":std_cast_rel", m_stdCastRel);
         qry.bindValue(":std_gf_name",  m_stdGFathName);
         qry.bindValue(":std_gf_occ",   m_stdGFathOcc);
         qry.bindValue(":std_gm_name",  m_stdGMothName);
         qry.bindValue(":std_gm_occ",   m_stdGMOthcc);
         qry.bindValue(":std_address",  m_stdAddr);
         qry.bindValue(":std_locality", m_stdLocality);
         qry.bindValue(":std_transport_fee",  m_stdTrnsFee);
         qry.bindValue(":std_concession", m_stdConssn);

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
    return 1;
}

void ags_student_record::ags_updt_std_details_into_db(QString stdID)
{
    if(ags_database::m_db.open())
    {
         std::cout << "Opened!";

         QSqlQuery qry(ags_database::m_db);

         qry.prepare("UPDATE ags_std_record SET std_name='" + m_stdName + "', std_sr_num='"+m_stdSrNum+"', std_mob_num='"+m_stdMobNum+"', std_dob='"+m_stdDtOfBrth.toString()+"', std_gndr='"+m_stdGender+"', std_class='"+m_stdClass+"', std_cast_rel='"+m_stdCastRel+"', std_gf_name='"+m_stdGFathName+"', std_gm_name='"+m_stdGMothName+"', std_transport_fee='"+m_stdTrnsFee+"', std_concession='"+m_stdConssn+"'"
                     "WHERE id_std_record='" + stdID + "'");

         qry.bindValue(":std_name",     m_stdName);
         qry.bindValue(":std_sr_num",   m_stdSrNum);
         qry.bindValue(":std_mob_num",  m_stdMobNum);
         qry.bindValue(":std_dob",      m_stdDtOfBrth.toString());
         qry.bindValue(":std_gndr",     m_stdGender);
         qry.bindValue(":std_class",    m_stdClass);
         qry.bindValue(":std_cast_rel", m_stdCastRel);
         qry.bindValue(":std_gf_name",  m_stdGFathName);
         qry.bindValue(":std_gm_name",  m_stdGMothName);
         qry.bindValue(":std_transport_fee",  m_stdTrnsFee);
         qry.bindValue(":std_concession", m_stdConssn);

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

QSqlQueryModel *ags_student_record::get_all_std_db_model(void)
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

QStringList ags_student_record::get_all_std_ids_of_class(QString stdCls)
{
    int stdInCls = 0;
    int indx     = 0;

    QStringList stdIDs;

    if(ags_database::m_db.open())
    {
        m_stdDataModel   = new QSqlQueryModel;
        QSqlQuery* query = new QSqlQuery(ags_database::m_db);

        query->prepare("SELECT FROM ags_std_record WHERE std_class ='" + stdCls + "'");
        query->exec(); /*Error check later*/

        do {
            stdIDs.insert(indx, query->value(4).toString());
            indx++;
        } while (query->next());

        stdInCls = query->size();
    }

    ags_database::m_db.close();

    return stdIDs;
}



