#include "ags_student_record.h"

ags_student_record::ags_student_record()
{

}

void ags_student_record::ags_set_std_name(QString agsName,
                                          QString agsMidName,
                                          QString agsLastName)
{
    m_stdName = agsName + agsMidName + agsLastName;
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


