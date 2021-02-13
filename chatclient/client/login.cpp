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
    connect(conn->get_sock(), SIGNAL(readyRead()), this, SLOT(read_data()));
    QString usr_name = ui->login_name->toPlainText();
    QString usr_pwd = ui->login_pwd->toPlainText();
    QString send_msg = "<sql>"+usr_name+","+usr_pwd;
    conn->do_write(send_msg.toLatin1());
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

void Login::read_data()
{
    QByteArray buf = conn->get_sock()->readAll();

}
