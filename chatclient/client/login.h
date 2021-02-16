#ifndef LOGIN_H
#define LOGIN_H

#include <QFrame>
#include <QByteArray>
#include "dialog.h"
#include "ui_login.h"
#include <QMessageBox>
#include "connect_server.h"

namespace Ui {
class Login;
}

class Login : public QFrame
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();
signals:
    void login_to_reg();

public slots:
    void show_this();
    void read_data();
private slots:
    void on_login_bton_clicked();

    void on_sign_up_bton_clicked();

private:
    Ui::Login *ui;
    Dialog d;
    connect_server *conn;
    void jump_chatroom();
};

#endif // LOGIN_H
