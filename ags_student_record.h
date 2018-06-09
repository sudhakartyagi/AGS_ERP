#ifndef AGS_STUDENT_RECORD_H
#define AGS_STUDENT_RECORD_H



#include <QString>
#include <QDate>



class ags_student_record
{

    public:

        ags_student_record();

        void ags_set_std_name(QString agsName, QString agsMidName, QString agsLastName);
        void ags_set_std_sr_num(QString agsSrNum);
        void ags_set_std_mob_num(QString agsMobNum);
        void ags_set_std_dob(QDate agsDob);
        void ags_set_std_cast_rel(QString agsCastRel);
        void ags_set_std_gndr(QString agsGndr);
        void ags_set_std_gf_name(QString agsGFName);
        void ags_set_std_gm_name(QString agsGMName);
        void ags_set_std_gf_occ(QString agsGFOcc);
        void ags_set_std_gm_occ(QString agsGMOcc);
        void ags_set_std_class(QString agsClass);

    private:
        QString m_stdName;
        QString m_stdMidName;
        QString m_stdLastName;

        QString m_stdClass;

        QString m_stdSrNum;
        QString m_stdMobNum;

        QDate m_stdDtOfBrth;

        QString m_stdGender;
        QString m_stdCastRel;

        QString m_stdGFathName;
        QString m_stdGMothName;

        QString m_stdGFathOcc;
        QString m_stdGMOthcc;
};

#endif // AGS_STUDENT_RECORD_H
