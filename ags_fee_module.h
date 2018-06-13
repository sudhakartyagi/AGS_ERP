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

    private:

        QSqlQueryModel *m_stdDataModel;

};

#endif // AGS_FEE_MODULE_H
