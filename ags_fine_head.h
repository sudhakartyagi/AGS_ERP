#ifndef AGS_FINE_HEAD_H
#define AGS_FINE_HEAD_H



#include <QString>
#include <QDate>
#include <QSqlQueryModel>


class ags_fine_head
{

    public:

        ags_fine_head();
        ~ags_fine_head();

        void ags_set_fine_head(QString agsFineHead);
        void ags_set_fine_amnt(QString agsFineAmnt);
        void ags_set_fine_remarks(QString agsFineRemarks);
        void ags_set_fine_due_date(QString agsFineDueDate);

        void ags_save_fine_head_into_db(void);
        void ags_updt_fine_head_into_db(void);
        void ags_del_fine_head_from_db(void);

        QSqlQueryModel *get_fine_head_db_model(void);
        QSqlQueryModel *get_sel_fine_head_db_model(QString fineHeadID);

        void ags_set_fine_current_view_id(QString fineHeadId);

        void ags_refresh_fine_updt_policy_contrls(void);
    private:

        QString m_fineHead;
        QString m_fineAmnt;
        QString m_fineRmarks;
        QString m_fineDueDate;

        QString m_fineCurrViewId;

        QSqlQueryModel *m_fineHdModel;
};

#endif // AGS_FINE_HEAD_H

