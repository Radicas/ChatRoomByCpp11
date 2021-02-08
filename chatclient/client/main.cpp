#include "login.h"
#include "sign.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    sign s;
    //QObject::connect(&s, SIGNAL(reg_to_login()), &l, SIGNAL(show()));
    QObject::connect(&l, SIGNAL(login_to_reg()), &s, SIGNAL(show_this()));
    l.show();
    return a.exec();
}
