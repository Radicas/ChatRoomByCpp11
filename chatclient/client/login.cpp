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
    /*
     * 查询数据库，登录，跳转聊天界面
     * */
    conn->do_connect();

    QString usr_name = ui->login_name->toPlainText();
    QString usr_pwd = ui->login_pwd->toPlainText();
    QString send_msg = "<sql_l>"+usr_name+","+usr_pwd;
    connect(conn->get_sock(), SIGNAL(readyRead()), this, SLOT(read_data(usr_name)));
    conn->do_write(send_msg.toLatin1());
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

void Login::read_data(QString usr_name)
{
    QByteArray buf = conn->get_sock()->readAll();
    if(buf == "CHECK")
    {
        jump_chatroom(usr_name);
    }else if(buf == "WRONG")
    {
        QMessageBox::information(this, "登录信息", "登录失败，原因不明！！");
    }
}

void Login::jump_chatroom(QString usr_name)
{
    d.get_user_name(usr_name);
    d.show();
    this->hide();
    conn->do_disconnect();
}


