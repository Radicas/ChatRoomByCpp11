#include "sign.h"
#include "ui_sign.h"

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
    conn = new connect_server();
}

sign::~sign()
{
    delete ui;
    delete conn;
}

void sign::on_go_login_clicked()
{
    //跳转登录界面
    emit reg_to_login();
    this->hide();
}

void sign::on_register_2_clicked()
{
    //查询数据库，判断是否注册，若注册就弹窗；未注册即注册
    conn->do_connect();
    QString usr_name = ui->usr_name->toPlainText();
    QString usr_pwd = ui->usr_pwd->toPlainText();
    QString send_msg = "<sql>"+usr_name+","+usr_pwd;
    conn->do_write(send_msg);
    /*
     *
     * */
    conn->do_disconnect();
}

void sign::show_this()
{
    this->show();
}

void sign::read_data()
{
    QByteArray buf = conn->get_sock()->readAll();

}
