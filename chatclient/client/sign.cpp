#include "sign.h"
#include "ui_sign.h"

sign::sign(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::sign)
{
    ui->setupUi(this);
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
    //查询数据库，判断是否注册，若注册就弹窗；未注册即注册
}

void sign::show_this()
{
    this->show();
}
