#ifndef AGS_STUDENT_RECORD_H
#define AGS_STUDENT_RECORD_H


#include <qsqlquerymodel.h>
#include <QString>
#include <QDate>



class ags_student_record
{

    public:

        ags_student_record();
        ~ags_student_record();

        void ags_set_std_name(QString agsName);
        void ags_set_std_mid_name(QString agsMidName);
        void ags_set_std_last_name(QString agsLastName);
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
        void ags_set_std_transport_fee(QString agsTrnsFee);
        void ags_set_std_concession(QString agsConssn);

        void ags_set_std_address(QString agsAddr);
        void ags_set_std_locality(QString agsLocality);

        int ags_save_std_data_into_db(void);
        void ags_updt_std_details_into_db(QString stdID);
        QSqlQueryModel *get_all_std_db_model(void);

        QString ags_get_dspl_name(void);

        QStringList get_all_std_ids_of_class(QString stdCls);

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

        QString m_stdAddr;
        QString m_stdLocality;

        QString m_stdTrnsFee;
        QString m_stdConssn;

        QSqlQueryModel *m_stdDataModel;
};

#endif // AGS_STUDENT_RECORD_H
