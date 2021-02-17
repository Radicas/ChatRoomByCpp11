#include "dialog.h"
#include "ui_dialog.h"
#include <string.h>
#include <QMessageBox>
#include <QByteArray>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    conn = new connect_server();
    conn->do_connect();
    connect(conn->get_sock(), SIGNAL(readyRead()), this, SLOT(read_data(usr_name)));
}

Dialog::~Dialog()
{
    delete ui;
    delete conn;
}

void Dialog::on_clear_in_clicked()
{
    ui->textBrowser->clear();
    ui->log->clear();
}

void Dialog::on_Send_clicked()
{
    QString origin_msg = ui->textEdit->toPlainText();
    QString send_msg = "<>"+usr_name+","+origin_msg;
    conn->do_write(send_msg);
}

void Dialog::on_disconnect_clicked()
{
    conn->do_disconnect();
}

void Dialog::read_data()
{

}

void Dialog::get_user_name(QString user_name)
{
    usr_name = user_name;
}
