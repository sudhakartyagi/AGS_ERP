#ifndef AGS_MAIN_WINDOW_H
#define AGS_MAIN_WINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include"ags_database.h"


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

private:
    Ui::ags_main_window *m_agsMainWindow;
    ags_database m_db;
};

#endif // AGS_MAIN_WINDOW_H
