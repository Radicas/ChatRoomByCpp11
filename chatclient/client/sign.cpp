#include "sign.h"
#include "ui_sign.h"

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
    ip = "127.0.0.1";
    port = 999;
}

sign::~sign()
{
    delete ui;
}

void sign::on_go_login_clicked()
{
    //跳转登录界面
    emit reg_to_login();
    this->hide();
}

void sign::on_register_2_clicked()
{
    QString user_name = ui->usr_name->toPlainText();
    QString user_pwd = ui->usr_pwd->toPlainText();
    QString user_info = user_name+"\t"+user_pwd;
    sign_sock = new QTcpSocket();
    ip_addr = new QHostAddress();
    ip_addr->setAddress(ip);
    sign_sock->connectToHost(*ip_addr, port);
    sign_sock->write(user_info.toLatin1());
    sign_sock->disconnectFromHost();
    //查询数据库，判断是否注册，若注册就弹窗；未注册即注册
}

void sign::show_this()
{
    this->show();
}
