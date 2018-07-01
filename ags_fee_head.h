#ifndef AGS_FEE_HEAD_H
#define AGS_FEE_HEAD_H



#include <QString>
#include <QDate>
#include <QSqlQueryModel>


class ags_fee_head
{

    public:

        ags_fee_head();
        ~ags_fee_head();

        void ags_set_fee_head(QString agsFeeHead);
        void ags_set_fee_amnt(QString agsFeeAmnt);
        void ags_set_fee_remarks(QString agsFeeRemarks);
        void ags_set_fee_app_class(QString agsFeeAppClass);

        void ags_set_fee_app_months(int agsFlg,QString agsFeeAppMonths);

        void ags_save_fee_head_into_db(void);
        void ags_updt_fee_head_into_db(void);
        void ags_del_fee_head_from_db(void);

        QSqlQueryModel *getFeeHeadDbModel(void);
        QSqlQueryModel *getSelFeeHeadDbModel(QString feeHeadID);

        void ags_set_fee_current_view_id(QString feeHeadId);

    private:

        QString m_feeHead;
        QString m_feeAmnt;
        QString m_feeRmarks;
        QString m_feeAppClass;
        QString m_feeAppMoths;
        QString m_feeCurrViewId;

        QSqlQueryModel *m_feeHdModel;
};

#endif // AGS_FEE_HEAD_H
