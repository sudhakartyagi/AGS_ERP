#ifndef AGS_MAIN_WINDOW_H
#define AGS_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include"ags_database.h"
#include"ags_student_record.h"
#include"ags_fee_module.h"

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

private:
    Ui::ags_main_window *m_agsMainWindow;
    ags_database *m_db;
    ags_student_record m_newStd;
    ags_fee_module     m_feeMod;
};

#endif // AGS_MAIN_WINDOW_H
