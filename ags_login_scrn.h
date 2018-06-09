#ifndef AGS_LOGIN_SCRN_H
#define AGS_LOGIN_SCRN_H

#include <QMainWindow>

namespace Ui {
class ags_login_scrn;
}

class ags_login_scrn : public QMainWindow
{
    Q_OBJECT

public:
    explicit ags_login_scrn(QWidget *parent = 0);
    ~ags_login_scrn();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ags_login_scrn *m_agsLoginScrn;
};

#endif // AGS_LOGIN_SCRN_H
