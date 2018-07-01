#ifndef AGS_FEE_MODULE_H
#define AGS_FEE_MODULE_H



#include <QtSql/QSqlQueryModel>



class ags_fee_module
{

    public:

        ags_fee_module();
        ~ags_fee_module();

        QSqlQueryModel *getStdDbModel(void);
        QSqlQueryModel *getFeeDbModel(QString stdId);

        int  get_all_applicable_fee(QString stdCls, QString curMonth);
        void insrt_fee_for_this_stds(void);

        void set_curr_std_id(QString stdID);
        void set_curr_std_unpd_mnth(QString undpMnth);

        void set_curr_std_curr_ball(int currBal);
        void set_curr_std_unpd_amnt(int unpdAmnt);

    private:

        QSqlQueryModel *m_stdDataModel;

        QString m_stdID;
        QString m_unpdMonth;

        int m_unpdAmnt;
        int m_currBal;
};

#endif // AGS_FEE_MODULE_H
