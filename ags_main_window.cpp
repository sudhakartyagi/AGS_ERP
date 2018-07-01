#include "ags_main_window.h"
#include "ags_database.h"
#include "ui_ags_main_window.h"
#include "ui_ags_add_std.h"

#include<QSqlQuery>
#include<QString>
#include<iostream>
#include<QMessageBox>

ags_main_window::ags_main_window(QWidget *parent) :
    QMainWindow(parent),
    m_agsMainWindow(new Ui::ags_main_window)
{
    m_agsMainWindow->setupUi(this);
    ags_database::ags_get_db_instance("AGS_db");
}

ags_main_window::~ags_main_window()
{
    delete m_agsMainWindow;
}

void ags_main_window::on_actionAdd_New_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(0);
}


/*************************************************/
/* Event handlers for Aadding new student record */
/*************************************************/

void ags_main_window::on_stdName_textEdited(const QString &stdName)
{
    m_newStd.ags_set_std_name(stdName);
}

void ags_main_window::on_stdMidName_textEdited(const QString &stdMidName)
{
    m_newStd.ags_set_std_mid_name(stdMidName);
}

void ags_main_window::on_stdLastName_textEdited(const QString &stdLastName)
{
    m_newStd.ags_set_std_last_name(stdLastName);
}

void ags_main_window::on_stdSRName_textEdited(const QString &stdSrNum)
{
    m_newStd.ags_set_std_sr_num(stdSrNum);
}

void ags_main_window::on_stdMobNum_textEdited(const QString &stdMobNum)
{
    m_newStd.ags_set_std_mob_num(stdMobNum);
}

void ags_main_window::on_stdDOB_userDateChanged(const QDate &stdDob)
{
    m_newStd.ags_set_std_dob(stdDob);
}

void ags_main_window::on_stdGndr_currentTextChanged(const QString &stdGndr)
{
    m_newStd.ags_set_std_gndr(stdGndr);
}



void ags_main_window::on_stdClass_currentTextChanged(const QString &stdClass)
{
    m_newStd.ags_set_std_class(stdClass);
}


void ags_main_window::on_stdCastRel_currentTextChanged(const QString &stdCastRel)
{
    m_newStd.ags_set_std_cast_rel(stdCastRel);
}


void ags_main_window::on_stdGFName_textEdited(const QString &stdGfName)
{
    m_newStd.ags_set_std_gf_name(stdGfName);
}

void ags_main_window::on_stdGMName_textEdited(const QString &stdGmName)
{
    m_newStd.ags_set_std_gm_name(stdGmName);
}

void ags_main_window::on_stdGFOcc_currentTextChanged(const QString &stdGfOcc)
{
    m_newStd.ags_set_std_gf_occ(stdGfOcc);
}

void ags_main_window::on_stdGMOcc_currentTextChanged(const QString &stdGmOcc)
{
    m_newStd.ags_set_std_gm_occ(stdGmOcc);
}

void ags_main_window::on_stdAddr_textEdited(const QString &stdAddr)
{
    m_newStd.ags_set_std_address(stdAddr);
}

void ags_main_window::on_stdLocality_2_currentTextChanged(const QString &stdLocality)
{
    m_newStd.ags_set_std_locality(stdLocality);
}

void ags_main_window::on_stdTransportFee_2_textEdited(const QString &stdTrnsFee)
{
    m_newStd.ags_set_std_transport_fee(stdTrnsFee);
}

void ags_main_window::on_stdConssn_textEdited(const QString &stdConsson)
{
    m_newStd.ags_set_std_concession(stdConsson);
}

void ags_main_window::on_saveStdRecordBtn_clicked()
{
    QMessageBox errMsg;

    if (0==m_newStd.ags_save_std_data_into_db()) {

        errMsg.setText("Record not saved. Please check the SR number.");
    } else {

        errMsg.setText("Record saved successfully.");
    }

    errMsg.exec();

    /*m_agsMainWindow->stdName->clear();
    m_agsMainWindow->stdMidName->clear();
    m_agsMainWindow->stdLastName->clear();
    m_agsMainWindow->stdSRName->clear();
    m_agsMainWindow->stdMobNum->clear();
    m_agsMainWindow->stdTransportFee_2->clear();
    m_agsMainWindow->stdConssn->clear();
    m_agsMainWindow->stdGFName->clear();
    m_agsMainWindow->stdGMName->clear();
    m_agsMainWindow->stdAddr->clear();*/

}

void ags_main_window::on_canclSave_clicked()
{
    /*clean here the stacked view*/
}

/***********************************************/
/* This is the end of event handler from page 1*/
/***********************************************/

/*************************************************/
/* Event handlers for fee detail view            */
/*************************************************/

void ags_main_window::on_feeDetailView_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(1);

    /* Check if first day of month */
    QDate toDay = QDate::currentDate();
    int dayNum  = toDay.day();

    QString clsName = "";
    QString stdID   = "";

    if ( 01 == dayNum ) {

        if (04 == (toDay.month() - 1)) {

            for (int indx = 0; indx < m_agsMainWindow->stdClass->count(); indx++) {

                clsName = m_agsMainWindow->stdClass->itemText(indx);

                int aplFee = m_feeMod.get_all_applicable_fee(clsName, months.at(toDay.month() - 1));

                QStringList stdIds = m_newStd.get_all_std_ids_of_class(clsName);

                for (int idx = 0; idx < stdIds.size(); idx++) {

                    m_feeMod.set_curr_std_id(stdIds.at(idx));
                    m_feeMod.set_curr_std_unpd_amnt(aplFee);
                    m_feeMod.set_curr_std_unpd_mnth(months.at(toDay.month() - 1));
                    m_feeMod.set_curr_std_curr_ball(aplFee);

                    m_feeMod.insrt_fee_for_this_stds();
                }
            }

        } else {


        }

    }
}

void ags_main_window::on_searchBtn_clicked()
{
    m_agsMainWindow->stdsDataView->setModel(m_feeMod.getStdDbModel());
    m_agsMainWindow->stdsDataView->show();
}

void ags_main_window::on_stdsDataView_doubleClicked(const QModelIndex &index)
{
    if ( 0 == index.column() ) {

        QSqlQueryModel *feeDetailModel = m_feeMod.getFeeDbModel(index.data().toString());
        m_agsMainWindow->stdFeeHistory->setModel(feeDetailModel);
        m_agsMainWindow->stdFeeHistory->show();

        int rowCnt  = feeDetailModel->rowCount();
        QString curBal = feeDetailModel->data(feeDetailModel->index(rowCnt - 1, 5)).toString();

        m_agsMainWindow->amntToBePaid->setText(curBal);

    }
}

/***********************************************************/
/* This is the end of event handler from page 2 fee details*/
/***********************************************************/

/*************************************************/
/* Event handlers for fee policy view            */
/*************************************************/

void ags_main_window::on_actionFee_Policy_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(2);
    m_agsMainWindow->feeHeadView->setModel(m_feeHead.getFeeHeadDbModel());
    m_agsMainWindow->feeHeadView->show();
}

void ags_main_window::on_FeeHead_currentTextChanged(const QString &feeHead)
{
    m_feeHead.ags_set_fee_head(feeHead);
}

void ags_main_window::on_feeAmnt_textEdited(const QString &feeAmnt)
{
    m_feeHead.ags_set_fee_amnt(feeAmnt);
}

void ags_main_window::on_feeHeadAppClass_currentTextChanged(const QString &feeAppCls)
{
    m_feeHead.ags_set_fee_app_class(feeAppCls);
}

void ags_main_window::on_feeRemarks_textEdited(const QString &feeRemarks)
{
    m_feeHead.ags_set_fee_remarks(feeRemarks);
}

void ags_main_window::on_feeJan_clicked()
{
    if (m_agsMainWindow->feeJan->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jan");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jan");
    }
}

void ags_main_window::on_feeFeb_clicked()
{
    if (m_agsMainWindow->feeFeb->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "feb");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "feb");
    }
}


void ags_main_window::on_feeMar_clicked()
{
    if (m_agsMainWindow->feeMar->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "mar");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "mar");
    }
}

void ags_main_window::on_feeApr_clicked()
{
    if (m_agsMainWindow->feeApr->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "apr");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "apr");
    }
}

void ags_main_window::on_feeMay_clicked()
{
    if (m_agsMainWindow->feeMay->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "may");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "may");
    }
}

void ags_main_window::on_feeJun_clicked()
{
    if (m_agsMainWindow->feeJun->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jun");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jun");
    }
}

void ags_main_window::on_feeJul_clicked()
{
    if (m_agsMainWindow->feeJul->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jul");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jul");
    }
}

void ags_main_window::on_feeAug_clicked()
{
    if (m_agsMainWindow->feeAug->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "aug");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "aug");
    }
}

void ags_main_window::on_feeSep_clicked()
{
    if (m_agsMainWindow->feeSep->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "sep");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "sep");
    }
}

void ags_main_window::on_feeOct_clicked()
{
    if (m_agsMainWindow->feeOct->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "oct");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "oct");
    }
}

void ags_main_window::on_feeNov_clicked()
{
    if (m_agsMainWindow->feeNov->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "nov");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "nov");
    }
}

void ags_main_window::on_feeDec_clicked()
{
    if (m_agsMainWindow->feeDec->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "dec");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "dec");
    }
}

void ags_main_window::on_AddFeeHead_clicked()
{
    m_feeHead.ags_save_fee_head_into_db();
    ags_refresh_fee_policy_contrls();

}

void ags_main_window::on_feeHeadView_doubleClicked(const QModelIndex &index)
{
    m_agsMainWindow->feeJanUpdt->setChecked(false);
    m_agsMainWindow->feeFebUpdt->setChecked(false);
    m_agsMainWindow->feeMarUpdt->setChecked(false);
    m_agsMainWindow->feeAprUpdt->setChecked(false);
    m_agsMainWindow->feeMayUpdt->setChecked(false);
    m_agsMainWindow->feeJunUpdt->setChecked(false);
    m_agsMainWindow->feeJulUpdt->setChecked(false);
    m_agsMainWindow->feeAugUpdt->setChecked(false);
    m_agsMainWindow->feeSepUpdt->setChecked(false);
    m_agsMainWindow->feeOctUpdt->setChecked(false);
    m_agsMainWindow->feeNovUpdt->setChecked(false);
    m_agsMainWindow->feeDecUpdt->setChecked(false);

    QSqlQueryModel *feeHeadModel = m_feeHead.getSelFeeHeadDbModel(index.data().toString());

    QString feeHead      = feeHeadModel->data(feeHeadModel->index(0,1)).toString();
    QString feeAmnt      = feeHeadModel->data(feeHeadModel->index(0,2)).toString();
    QString feeAppClass  = feeHeadModel->data(feeHeadModel->index(0,3)).toString();
    QString feeAppMonths = feeHeadModel->data(feeHeadModel->index(0,4)).toString();
    QString feeRemark    = feeHeadModel->data(feeHeadModel->index(0,5)).toString();

    m_agsMainWindow->feeHeadUpdt->setText(feeHead);
    m_agsMainWindow->feeAmntUpdt->setText(feeAmnt);
    m_agsMainWindow->feeAappClassUpdat->setText(feeAppClass);
    m_agsMainWindow->feeRemarksUpdt->setText(feeRemark);

    if (feeAppMonths.contains("jan")) {m_agsMainWindow->feeJanUpdt->setChecked(true);}
    if (feeAppMonths.contains("feb")) {m_agsMainWindow->feeFebUpdt->setChecked(true);}
    if (feeAppMonths.contains("mar")) {m_agsMainWindow->feeMarUpdt->setChecked(true);}
    if (feeAppMonths.contains("apr")) {m_agsMainWindow->feeAprUpdt->setChecked(true);}
    if (feeAppMonths.contains("may")) {m_agsMainWindow->feeMayUpdt->setChecked(true);}
    if (feeAppMonths.contains("jun")) {m_agsMainWindow->feeJunUpdt->setChecked(true);}
    if (feeAppMonths.contains("jul")) {m_agsMainWindow->feeJulUpdt->setChecked(true);}
    if (feeAppMonths.contains("aug")) {m_agsMainWindow->feeAugUpdt->setChecked(true);}
    if (feeAppMonths.contains("sep")) {m_agsMainWindow->feeSepUpdt->setChecked(true);}
    if (feeAppMonths.contains("oct")) {m_agsMainWindow->feeOctUpdt->setChecked(true);}
    if (feeAppMonths.contains("nov")) {m_agsMainWindow->feeNovUpdt->setChecked(true);}
    if (feeAppMonths.contains("dec")) {m_agsMainWindow->feeDecUpdt->setChecked(true);}

    m_feeHead.ags_set_fee_current_view_id(feeHeadModel->data(feeHeadModel->index(0,0)).toString());
}


void ags_main_window::on_updateFeeHead_clicked()
{
    m_feeHead.ags_updt_fee_head_into_db();
    ags_refresh_fee_policy_contrls();
}

void ags_main_window::on_feeHeadUpdt_textEdited(const QString &feeHead)
{
    m_feeHead.ags_set_fee_head(feeHead);
}

void ags_main_window::on_feeAmntUpdt_textEdited(const QString &feeAmnt)
{
    m_feeHead.ags_set_fee_amnt(feeAmnt);
}

void ags_main_window::on_feeRemarksUpdt_textEdited(const QString &feeRemarks)
{
    m_feeHead.ags_set_fee_remarks(feeRemarks);
}

void ags_main_window::on_feeAappClassUpdat_textEdited(const QString &feeAppCls)
{
    m_feeHead.ags_set_fee_app_class(feeAppCls);
}

void ags_main_window::on_feeJanUpdt_clicked()
{
    if (m_agsMainWindow->feeJanUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jan");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jan");
    }
}

void ags_main_window::on_feeFebUpdt_clicked()
{
    if (m_agsMainWindow->feeFebUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "feb");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "feb");
    }
}

void ags_main_window::on_feeMarUpdt_clicked()
{
    if (m_agsMainWindow->feeMarUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "mar");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "mar");
    }
}

void ags_main_window::on_feeAprUpdt_clicked()
{
    if (m_agsMainWindow->feeAprUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "apr");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "apr");
    }
}

void ags_main_window::on_feeMayUpdt_clicked()
{
    if (m_agsMainWindow->feeMayUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "may");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "may");
    }
}

void ags_main_window::on_feeJunUpdt_clicked()
{
    if (m_agsMainWindow->feeJunUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jun");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jun");
    }
}

void ags_main_window::on_feeJulUpdt_clicked()
{
    if (m_agsMainWindow->feeJulUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "jul");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "jul");
    }
}

void ags_main_window::on_feeAugUpdt_clicked()
{
    if (m_agsMainWindow->feeAugUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "aug");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "aug");
    }
}

void ags_main_window::on_feeSepUpdt_clicked()
{
    if (m_agsMainWindow->feeSepUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "sep");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "sep");
    }
}

void ags_main_window::on_feeOctUpdt_clicked()
{
    if (m_agsMainWindow->feeOctUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "oct");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "oct");
    }
}

void ags_main_window::on_feeNovUpdt_clicked()
{
    if (m_agsMainWindow->feeNovUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "nov");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "nov");
    }
}

void ags_main_window::on_feeDecUpdt_clicked()
{
    if (m_agsMainWindow->feeDecUpdt->isChecked()) {

        m_feeHead.ags_set_fee_app_months(1, "dec");
    } else {

        m_feeHead.ags_set_fee_app_months(0, "dec");
    }
}

void ags_main_window::on_deleteFeeHead_clicked()
{
    m_feeHead.ags_del_fee_head_from_db();
    ags_refresh_fee_policy_contrls();
}

void ags_main_window::ags_refresh_fee_policy_contrls(void)
{
    m_agsMainWindow->feeHeadView->setModel(m_feeHead.getFeeHeadDbModel());
    m_agsMainWindow->feeHeadView->show();

    //m_agsMainWindow->feeHeadUpdt->clear();
    m_agsMainWindow->feeAmntUpdt->clear();
    m_agsMainWindow->feeRemarksUpdt->clear();
    m_agsMainWindow->feeAappClassUpdat->clear();
    m_agsMainWindow->feeJanUpdt->setChecked(false);
    m_agsMainWindow->feeFebUpdt->setChecked(false);
    m_agsMainWindow->feeMarUpdt->setChecked(false);
    m_agsMainWindow->feeAprUpdt->setChecked(false);
    m_agsMainWindow->feeMayUpdt->setChecked(false);
    m_agsMainWindow->feeJunUpdt->setChecked(false);
    m_agsMainWindow->feeJulUpdt->setChecked(false);
    m_agsMainWindow->feeAugUpdt->setChecked(false);
    m_agsMainWindow->feeSepUpdt->setChecked(false);
    m_agsMainWindow->feeOctUpdt->setChecked(false);
    m_agsMainWindow->feeNovUpdt->setChecked(false);
    m_agsMainWindow->feeDecUpdt->setChecked(false);
}


/***********************************************************/
/* This is the end of event handler from page 3 fee policy*/
/***********************************************************/

/*************************************************/
/* Event handlers for fine policy view            */
/*************************************************/

void ags_main_window::on_actionFine_Policy_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(3);
    m_agsMainWindow->fineHeadView->setModel(m_fineHead.get_fine_head_db_model());
    m_agsMainWindow->fineHeadView->show();
}

void ags_main_window::on_fineHead_currentTextChanged(const QString &fineHead)
{
    m_fineHead.ags_set_fine_head(fineHead);
}

void ags_main_window::on_fineAmnt_textEdited(const QString &fineAmnt)
{
    m_fineHead.ags_set_fine_amnt(fineAmnt);
}

void ags_main_window::on_fineDueDate_textEdited(const QString &fineDueDate)
{
    m_fineHead.ags_set_fine_due_date(fineDueDate);
}

void ags_main_window::on_fineRemarks_textEdited(const QString &fineRemarks)
{
    m_fineHead.ags_set_fine_remarks(fineRemarks);
}

void ags_main_window::on_fineAdd_clicked()
{
    m_fineHead.ags_save_fine_head_into_db();
    ags_refresh_fine_policy_contrls();
}

void ags_main_window::ags_refresh_fine_policy_contrls(void)
{
    m_agsMainWindow->fineHeadView->setModel(m_fineHead.get_fine_head_db_model());
    m_agsMainWindow->fineHeadView->show();

    m_agsMainWindow->fineAmnt->clear();
    m_agsMainWindow->fineRemarks->clear();
    m_agsMainWindow->fineDueDate->clear();
}


void ags_main_window::on_fineHeadView_doubleClicked(const QModelIndex &index)
{
    QSqlQueryModel *fineHeadModel = m_fineHead.get_sel_fine_head_db_model(index.data().toString());

    QString fineHead    = fineHeadModel->data(fineHeadModel->index(0,1)).toString();
    QString fineAmnt    = fineHeadModel->data(fineHeadModel->index(0,2)).toString();
    QString fineDueDate = fineHeadModel->data(fineHeadModel->index(0,3)).toString();
    QString fineRemark  = fineHeadModel->data(fineHeadModel->index(0,4)).toString();

    m_agsMainWindow->fineHeadUpdt->setText(fineHead);
    m_agsMainWindow->fineAmntUpdt->setText(fineAmnt);
    m_agsMainWindow->fineDueDateUpdt->setText(fineDueDate);
    m_agsMainWindow->fineRemarksUpdt->setText(fineRemark);

    m_fineHead.ags_set_fine_current_view_id(fineHeadModel->data(fineHeadModel->index(0,0)).toString());
}

void ags_main_window::on_fineUpdt_clicked()
{
    m_fineHead.ags_updt_fine_head_into_db();
    ags_refresh_fine_updt_policy_contrls();
}

void ags_main_window::on_fineDel_clicked()
{
    m_fineHead.ags_del_fine_head_from_db();
    ags_refresh_fine_updt_policy_contrls();
}

void ags_main_window::ags_refresh_fine_updt_policy_contrls(void)
{
    m_agsMainWindow->fineHeadView->setModel(m_fineHead.get_fine_head_db_model());
    m_agsMainWindow->fineHeadView->show();

    m_agsMainWindow->fineHeadUpdt->clear();
    m_agsMainWindow->fineAmntUpdt->clear();
    m_agsMainWindow->fineRemarksUpdt->clear();
    m_agsMainWindow->fineDueDateUpdt->clear();
}

void ags_main_window::on_fineHeadUpdt_textEdited(const QString &fineHead)
{
    m_fineHead.ags_set_fine_head(fineHead);
}

void ags_main_window::on_fineAmntUpdt_textEdited(const QString &fineAmnt)
{
    m_fineHead.ags_set_fine_amnt(fineAmnt);
}

void ags_main_window::on_fineDueDateUpdt_textEdited(const QString &fineDueDate)
{
    m_fineHead.ags_set_fine_due_date(fineDueDate);
}

void ags_main_window::on_fineRemarksUpdt_textEdited(const QString &fineRemarks)
{
    m_fineHead.ags_set_fine_remarks(fineRemarks);
}


/*************************************************/
/* Event handlers for student detail view            */
/*************************************************/


void ags_main_window::on_stdDetailsByName_textEdited(const QString &stdName)
{
    m_stdDetails.set_std_name(stdName);
}


void ags_main_window::on_stdDetailsByFathName_textEdited(const QString &stdFathName)
{
    m_stdDetails.set_std_fath_name(stdFathName);
}


void ags_main_window::on_stdDetailsBySRNum_textEdited(const QString &stdSrNum)
{
    m_stdDetails.set_std_SR_num(stdSrNum);
}


void ags_main_window::on_stdSrchByClass_currentTextChanged(const QString &stdClass)
{
    m_stdDetails.set_std_class(stdClass);
}


void ags_main_window::on_stdDetailsView_doubleClicked(const QModelIndex &index)
{
    if ( 0 == index.column() ) {

        QSqlQueryModel *stdDetailModel = m_stdDetails.get_std_details(index.data().toString());

        QString stdName     = stdDetailModel->data(stdDetailModel->index(0,1)).toString();
        QString stdMidName  = stdDetailModel->data(stdDetailModel->index(0,2)).toString();
        QString stdLastName = stdDetailModel->data(stdDetailModel->index(0,3)).toString();
        QString stdSrNum    = stdDetailModel->data(stdDetailModel->index(0,4)).toString();
        QString stdMobNum   = stdDetailModel->data(stdDetailModel->index(0,5)).toString();
        QDate   stdDob      = stdDetailModel->data(stdDetailModel->index(0,6)).toDate();
        QString stdGndr     = stdDetailModel->data(stdDetailModel->index(0,7)).toString();
        QString stdClass    = stdDetailModel->data(stdDetailModel->index(0,8)).toString();
        QString stdCastRel  = stdDetailModel->data(stdDetailModel->index(0,9)).toString();
        QString stdGfName   = stdDetailModel->data(stdDetailModel->index(0,10)).toString();
        QString stdGfOcc    = stdDetailModel->data(stdDetailModel->index(0,11)).toString();
        QString stdGmName   = stdDetailModel->data(stdDetailModel->index(0,12)).toString();
        QString stdGmOcc    = stdDetailModel->data(stdDetailModel->index(0,13)).toString();
        QString stdAddr     = stdDetailModel->data(stdDetailModel->index(0,14)).toString();
        QString stdLocality = stdDetailModel->data(stdDetailModel->index(0,15)).toString();
        QString stdTransFee = stdDetailModel->data(stdDetailModel->index(0,16)).toString();
        QString stdConcessn = stdDetailModel->data(stdDetailModel->index(0,17)).toString();

        m_agsMainWindow->stdNameUpdt->setText(stdName + " " + stdMidName + " " + stdLastName);
        m_newStd.ags_set_std_name(stdName);
        m_agsMainWindow->stdGFNameUpdt->setText(stdGfName);
        m_newStd.ags_set_std_gf_name(stdGfName);
        m_agsMainWindow->stdGMNameUpdt->setText(stdGmName);
        m_newStd.ags_set_std_gm_name(stdGmName);
        m_agsMainWindow->stdDOBUpdt->setDate(stdDob);
        m_newStd.ags_set_std_dob(stdDob);
        m_agsMainWindow->stdGndrUpdt->setCurrentText(stdGndr);
        m_newStd.ags_set_std_gndr(stdGndr);
        m_agsMainWindow->stdSRNameUpdt->setText(stdSrNum);
        m_newStd.ags_set_std_sr_num(stdSrNum);
        m_agsMainWindow->stdMobNumUpdt->setText(stdMobNum);
        m_newStd.ags_set_std_mob_num(stdMobNum);
        m_agsMainWindow->stdClassUpdt->setCurrentText(stdClass);
        m_newStd.ags_set_std_class(stdClass);
        m_agsMainWindow->stdCastRelUpdt->setCurrentText(stdCastRel);
        m_newStd.ags_set_std_cast_rel(stdCastRel);
        m_agsMainWindow->stdTransportFeeUpdt->setText(stdTransFee);
        m_newStd.ags_set_std_transport_fee(stdTransFee);
        m_agsMainWindow->stdConcessionUpdt->setText(stdConcessn);
        m_newStd.ags_set_std_concession(stdConcessn);

        m_stdDetails.set_std_curr_id(stdDetailModel->data(stdDetailModel->index(0,0)).toString());
    }
}

void ags_main_window::on_stdNameUpdt_textEdited(const QString &stdName)
{
    m_newStd.ags_set_std_name(stdName);
}

void ags_main_window::on_stdGMNameUpdt_textEdited(const QString &stdGfName)
{
    m_newStd.ags_set_std_gm_name(stdGfName);
}

void ags_main_window::on_stdGFNameUpdt_textEdited(const QString &stdGmName)
{
    m_newStd.ags_set_std_gf_name(stdGmName);
}

void ags_main_window::on_stdCastRelUpdt_currentTextChanged(const QString &stdCastRel)
{
    m_newStd.ags_set_std_cast_rel(stdCastRel);
}

void ags_main_window::on_stdClassUpdt_currentTextChanged(const QString &stdClass)
{
    m_newStd.ags_set_std_class(stdClass);
}

void ags_main_window::on_stdMobNumUpdt_textEdited(const QString &stdMobNum)
{
    m_newStd.ags_set_std_mob_num(stdMobNum);
}

void ags_main_window::on_stdSRNameUpdt_textEdited(const QString &stdSrNum)
{
    m_newStd.ags_set_std_sr_num(stdSrNum);
}

void ags_main_window::on_stdDOBUpdt_userDateChanged(const QDate &stdDob)
{
    m_newStd.ags_set_std_dob(stdDob);
}

void ags_main_window::on_stdGndrUpdt_currentTextChanged(const QString &stdGndr)
{
    m_newStd.ags_set_std_gndr(stdGndr);
}

void ags_main_window::on_updtStdBtn_clicked()
{
    m_newStd.ags_updt_std_details_into_db(m_stdDetails.ags_get_current_std_id());
    ags_reset_std_view_cntrls();
    m_agsMainWindow->stdDetailsView->setModel(m_stdDetails.getStdDbModel());
    m_agsMainWindow->stdDetailsView->show();
}

void ags_main_window::on_viewStdDetails_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(5);
    m_agsMainWindow->stdDetailsView->setModel(m_stdDetails.getStdDbModel());
    m_agsMainWindow->stdDetailsView->show();
}

void ags_main_window::on_deleteStdBtn_clicked()
{
    m_stdDetails.ags_del_std_from_db();
    ags_reset_std_view_cntrls();
    m_agsMainWindow->stdDetailsView->setModel(m_stdDetails.getStdDbModel());
    m_agsMainWindow->stdDetailsView->show();
}

void ags_main_window::ags_reset_std_view_cntrls()
{
    m_agsMainWindow->stdName->clear();
    m_agsMainWindow->stdSRName->clear();
    m_agsMainWindow->stdClass->clear();
    m_agsMainWindow->stdGFName->clear();

    m_agsMainWindow->stdNameUpdt->clear();
    m_agsMainWindow->stdSRNameUpdt->clear();
    m_agsMainWindow->stdMobNumUpdt->clear();
    m_agsMainWindow->stdGFNameUpdt->clear();
    m_agsMainWindow->stdGMNameUpdt->clear();
}

void ags_main_window::on_stdTransportFeeUpdt_textEdited(const QString &stdTrnsFee)
{
    m_newStd.ags_set_std_transport_fee(stdTrnsFee);
}

void ags_main_window::on_stdDetailsSearchBtn_clicked()
{
    m_agsMainWindow->stdDetailsView->setModel(m_stdDetails.getStdDbModel());
    m_agsMainWindow->stdDetailsView->show();
    ags_reset_std_view_cntrls();
}


void ags_main_window::on_stdConcessionUpdt_textEdited(const QString &stdConssn)
{
    m_newStd.ags_set_std_transport_fee(stdConssn);
}


/*************************************************/
/* End of event handlers for student detail view */
/*************************************************/

/*************************************************/
/* Event handlers for fee collect module         */
/*************************************************/

void ags_main_window::on_searchStdBtn_clicked()
{
    m_agsMainWindow->stdFeeHistoryView->setModel(m_newStd.get_all_std_db_model());
    m_agsMainWindow->stdFeeHistoryView->show();
}

void ags_main_window::on_stdFeeHistoryView_doubleClicked(const QModelIndex &index)
{
    if (0 == index.column()) {

        QSqlQueryModel *stdDetailModel = m_stdDetails.get_std_details(index.data().toString());

        QString stdName     = stdDetailModel->data(stdDetailModel->index(0,1)).toString();
        QString stdMidName  = stdDetailModel->data(stdDetailModel->index(0,2)).toString();
        QString stdLastName = stdDetailModel->data(stdDetailModel->index(0,3)).toString();
        QString stdSrNum    = stdDetailModel->data(stdDetailModel->index(0,4)).toString();
        QString stdClass    = stdDetailModel->data(stdDetailModel->index(0,8)).toString();
        QString stdGfName   = stdDetailModel->data(stdDetailModel->index(0,10)).toString();
        QString stdTransFee = stdDetailModel->data(stdDetailModel->index(0,16)).toString();
        QString stdConcessn = stdDetailModel->data(stdDetailModel->index(0,17)).toString();

        m_agsMainWindow->stdNameEdit->setText(stdName + " " + stdMidName + " " + stdLastName);
        m_agsMainWindow->fathsNameEdit->setText(stdGfName);
        m_agsMainWindow->srNumEdit->setText(stdSrNum);
        m_agsMainWindow->classEdit->setText(stdClass);
        m_agsMainWindow->transportFeeEdit->setText(stdTransFee);
        m_agsMainWindow->conssnEdit->setText(stdConcessn);

        m_stdDetails.set_std_curr_id(stdDetailModel->data(stdDetailModel->index(0,0)).toString());
    }
}



