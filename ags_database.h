#ifndef AGS_DATABASE_H
#define AGS_DATABASE_H



#include <QtSql/QSqlDatabase>



class ags_database
{

    public:

        ags_database();
        ~ags_database();

        void ags_setup_db(QString agsDbName);
        void ags_get_glbl_qry_obj(void);

    private:

        QSqlDatabase m_db;
};

#endif // AGS_DATABASE_H
