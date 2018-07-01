#ifndef AGS_STD_DETAILS_H
#define AGS_STD_DETAILS_H



#include <QtSql/QSqlQueryModel>



class ags_std_details
{

    public:

        ags_std_details();
        ~ags_std_details();

        QSqlQueryModel *getStdDbModel(void);
        QSqlQueryModel *get_std_details(QString stdId);

        QString ags_get_current_std_id(void);
        void ags_del_std_from_db(void);

        void set_std_name(QString stdName);
        void set_std_fath_name(QString stdFathName);
        void set_std_SR_num(QString stdSRNum);
        void set_std_class(QString stdClass);
        void set_std_curr_id(QString stdID);

    private:

        QSqlQueryModel *m_stdDataModel;

        QString m_stdName;
        QString m_stdFathName;
        QString m_stdSRNum;
        QString m_stdClass;

        QString m_curStdId;

};

#endif // AGS_STD_DETAILS_H
