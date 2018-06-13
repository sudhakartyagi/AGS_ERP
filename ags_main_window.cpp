#include "ags_main_window.h"
#include "ags_database.h"
#include "ui_ags_main_window.h"
#include "ui_ags_add_std.h"

#include<QSqlQuery>
#include<QString>
#include<iostream>

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

void ags_main_window::on_saveStdRecordBtn_clicked()
{
    m_newStd.ags_save_std_data_into_db();
}

void ags_main_window::on_canclSave_clicked()
{
    /*clean here the stacked view*/
}

/***********************************************/
/* This is the end of event handler from page 1*/
/***********************************************/



void ags_main_window::on_feeDetailView_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(1);
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

