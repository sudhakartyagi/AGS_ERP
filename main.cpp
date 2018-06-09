#include "ags_login_scrn.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ags_login_scrn w;
    w.show();

    return a.exec();
}
