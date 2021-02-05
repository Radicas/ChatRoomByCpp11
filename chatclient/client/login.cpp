#include "login.h"
#include "ui_login.h"
Login::Login(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_login_bton_clicked()
{
    /*
     * 查询数据库，登录，跳转聊天界面
     * */
    d.show();
    this->hide();
}

void Login::on_sign_up_bton_clicked()
{
    /*
     * 注册界面
     * */
}
