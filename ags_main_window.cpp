#include "ags_main_window.h"
#include "ags_database.h"
#include "ui_ags_main_window.h"
#include "ui_ags_add_std.h"

ags_main_window::ags_main_window(QWidget *parent) :
    QMainWindow(parent),
    m_agsMainWindow(new Ui::ags_main_window)
{
    m_agsMainWindow->setupUi(this);
    m_db.ags_setup_db("Ags_db");
}

ags_main_window::~ags_main_window()
{
    delete m_agsMainWindow;
}

void ags_main_window::on_actionAdd_New_triggered()
{
    m_agsMainWindow->agsStackedWidgt->setCurrentIndex(0);
}
