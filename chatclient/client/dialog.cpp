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
    //connect(sock, SIGNAL(readyRead()), this, SLOT(read_data()));
}

Dialog::~Dialog()
{
    delete ui;
    delete sock;
    delete ip_addr;
}

void Dialog::on_clear_in_clicked()
{
    ui->ip->clear();
    ui->port->clear();
    ui->textBrowser->clear();
}

void Dialog::on_connect_clicked()
{
    ip = ui->ip->toPlainText();
    port = ui->port->toPlainText().toInt();
    sock = new QTcpSocket();
    ip_addr = new QHostAddress();
    ip_addr->setAddress(ip);
    sock->connectToHost(*ip_addr, port);
}

void Dialog::on_Send_clicked()
{
    send_text = ui->textEdit->toPlainText();
    if(send_text!="")
    {
        if(sock->write(send_text.toLatin1())!=-1)
        {
            ui->textBrowser->append(send_text);
        }else
        {
            ui->log->setText("write error");
        }
    }
}
