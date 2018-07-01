#ifndef AGS_FEE_COLLECT_H
#define AGS_FEE_COLLECT_H



#include <QtSql/QSqlQueryModel>



class ags_fee_collect
{

    public:

         ags_fee_collect();
        ~ags_fee_collect();

        QSqlQueryModel *ags_get_std_db_model(void);
        QSqlQueryModel *ags_get_fee_db_model(QString stdId);
        QSqlQueryModel *ags_get_fee_details_model(QString stdClass, QString feeHead);

    private:

        QSqlQueryModel *m_stdDataModel;

};

#endif // AGS_FEE_COLLECT_H
