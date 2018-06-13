#ifndef AGS_DATABASE_H
#define AGS_DATABASE_H



#include <QtSql/QSqlDatabase>



class ags_database
{

    public:

        ags_database();
        ~ags_database();

        static void ags_get_db_instance(QString agsDbName);
        static QSqlDatabase m_db;
};

#endif // AGS_DATABASE_H
