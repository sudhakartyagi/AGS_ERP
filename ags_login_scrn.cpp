#include "ags_login_scrn.h"
#include "ags_main_window.h"
#include "ui_ags_login_scrn.h"

ags_login_scrn::ags_login_scrn(QWidget *parent) : QMainWindow(parent),
    m_agsLoginScrn(new Ui::ags_login_scrn)
{
    m_agsLoginScrn->setupUi(this);
}

ags_login_scrn::~ags_login_scrn()
{
    delete m_agsLoginScrn;
}

void ags_login_scrn::on_pushButton_clicked()
{
    this->close();
    ags_main_window *agsMainWnd = new ags_main_window();
    agsMainWnd->show();
}
