#ifndef AGS_MAIN_WINDOW_H
#define AGS_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include"ags_database.h"
#include"ags_student_record.h"
#include"ags_fee_module.h"
#include"ags_fee_head.h"
#include"ags_fine_head.h"
#include"ags_student_view_details.h"

namespace Ui {
class ags_main_window;
}

class ags_main_window : public QMainWindow
{
    Q_OBJECT

public:
    explicit ags_main_window(QWidget *parent = 0);
            ~ags_main_window();

private slots:
    void on_actionAdd_New_triggered();

    void on_stdName_textEdited(const QString &arg1);

    void on_stdMidName_textEdited(const QString &arg1);

    void on_stdSRName_textEdited(const QString &arg1);

    void on_stdLastName_textEdited(const QString &arg1);

    void on_stdMobNum_textEdited(const QString &arg1);

    void on_stdDOB_userDateChanged(const QDate &date);

    void on_stdGndr_currentTextChanged(const QString &arg1);

    void on_stdClass_currentTextChanged(const QString &arg1);

    void on_stdCastRel_currentTextChanged(const QString &arg1);

    void on_stdGFName_textEdited(const QString &arg1);

    void on_stdGMName_textEdited(const QString &arg1);

    void on_stdGFOcc_currentTextChanged(const QString &arg1);

    void on_stdGMOcc_currentTextChanged(const QString &arg1);

    void on_stdAddr_textEdited(const QString &arg1);

    void on_stdLocality_2_currentTextChanged(const QString &arg1);

    void on_saveStdRecordBtn_clicked();

    void on_canclSave_clicked();

    void on_feeDetailView_triggered();

    void on_searchBtn_clicked();

    void on_stdsDataView_doubleClicked(const QModelIndex &index);

    void on_feeAmnt_textEdited(const QString &arg1);

    void on_feeRemarks_textEdited(const QString &arg1);


    void on_feeJan_clicked();

    void on_feeFeb_clicked();

    void on_feeMar_clicked();

    void on_feeApr_clicked();

    void on_feeMay_clicked();

    void on_feeJun_clicked();

    void on_feeJul_clicked();

    void on_feeAug_clicked();

    void on_feeSep_clicked();

    void on_feeOct_clicked();

    void on_feeNov_clicked();

    void on_feeDec_clicked();

    void on_AddFeeHead_clicked();

    void on_FeeHead_currentTextChanged(const QString &arg1);

    void on_feeHeadView_doubleClicked(const QModelIndex &index);

    void on_actionFee_Policy_triggered();

    void on_feeHeadAppClass_currentTextChanged(const QString &arg1);

    void on_updateFeeHead_clicked();

    void on_feeHeadUpdt_textEdited(const QString &arg1);

    void on_feeAmntUpdt_textEdited(const QString &arg1);

    void on_feeRemarksUpdt_textEdited(const QString &arg1);

    void on_feeJanUpdt_clicked();

    void on_feeFebUpdt_clicked();

    void on_feeMarUpdt_clicked();

    void on_feeAprUpdt_clicked();

    void on_feeMayUpdt_clicked();

    void on_feeJunUpdt_clicked();

    void on_feeJulUpdt_clicked();

    void on_feeAugUpdt_clicked();

    void on_feeSepUpdt_clicked();

    void on_feeOctUpdt_clicked();

    void on_feeNovUpdt_clicked();

    void on_feeDecUpdt_clicked();

    void on_deleteFeeHead_clicked();

    void on_feeAappClassUpdat_textEdited(const QString &arg1);

    void on_actionFine_Policy_triggered();

    void on_fineHead_currentTextChanged(const QString &arg1);

    void on_fineAmnt_textEdited(const QString &arg1);

    void on_fineDueDate_textEdited(const QString &arg1);

    void on_fineRemarks_textEdited(const QString &arg1);

    void on_fineAdd_clicked();


    void on_fineHeadView_doubleClicked(const QModelIndex &index);

    void on_fineUpdt_clicked();

    void on_fineDel_clicked();

    void on_fineHeadUpdt_textEdited(const QString &arg1);

    void on_fineAmntUpdt_textEdited(const QString &arg1);

    void on_fineDueDateUpdt_textEdited(const QString &arg1);

    void on_fineRemarksUpdt_textEdited(const QString &arg1);

    void on_stdDetailsByName_textEdited(const QString &arg1);

    void on_stdDetailsByFathName_textEdited(const QString &arg1);

    void on_stdDetailsBySRNum_textEdited(const QString &arg1);

    void on_stdSrchByClass_currentTextChanged(const QString &arg1);

    void on_stdDetailsView_doubleClicked(const QModelIndex &index);

    void on_stdNameUpdt_textEdited(const QString &arg1);

    void on_stdGMNameUpdt_textEdited(const QString &arg1);

    void on_stdGFNameUpdt_textEdited(const QString &arg1);

    void on_stdCastRelUpdt_currentTextChanged(const QString &arg1);

    void on_stdClassUpdt_currentTextChanged(const QString &arg1);

    void on_stdMobNumUpdt_textEdited(const QString &arg1);

    void on_stdSRNameUpdt_textEdited(const QString &arg1);

    void on_stdDOBUpdt_userDateChanged(const QDate &date);

    void on_stdGndrUpdt_currentTextChanged(const QString &arg1);

    void on_updtStdBtn_clicked();

    void on_viewStdDetails_triggered();

    void on_deleteStdBtn_clicked();
    void ags_reset_std_view_cntrls();

    void on_stdTransportFeeUpdt_textEdited(const QString &arg1);

    void on_stdTransportFee_2_textEdited(const QString &arg1);

    void on_stdConssn_textEdited(const QString &arg1);

    void on_stdDetailsSearchBtn_clicked();

    void on_stdConcessionUpdt_textEdited(const QString &arg1);

    void on_searchStdBtn_clicked();

    void on_stdFeeHistoryView_doubleClicked(const QModelIndex &index);

private:

    Ui::ags_main_window *m_agsMainWindow;
    ags_database *m_db;
    ags_student_record m_newStd;
    ags_fee_module     m_feeMod;
    ags_fee_head       m_feeHead;
    ags_fine_head      m_fineHead;
    ags_std_details    m_stdDetails;

    void ags_refresh_fee_policy_contrls(void);
    void ags_refresh_fine_policy_contrls(void);
    void ags_refresh_fine_updt_policy_contrls(void);

    QStringList months = {"jan", "feb", "mar", "apr","may","jun","jul","aug","sep","oct","nov","dec"};
};

#endif // AGS_MAIN_WINDOW_H
