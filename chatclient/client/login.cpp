#include "login.h"

Login::Login(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    conn = new connect_server();
}

Login::~Login()
{
    delete ui;
    delete conn;
}

void Login::on_login_bton_clicked()
{
    conn->do_connect();
    /*
     * 查询数据库，登录，跳转聊天界面
     * */
    d.show();
    this->hide();
    conn->do_disconnect();
}

void Login::on_sign_up_bton_clicked()
{
    /*
     * 注册界面
     * */
    emit login_to_reg();
    this->hide();
}

void Login::show_this()
{
    this->show();
}
