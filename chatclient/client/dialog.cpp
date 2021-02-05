#include "dialog.h"
#include "ui_dialog.h"
#include <string.h>
#include <QMessageBox>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_clear_in_clicked()
{
    ui->ip->clear();
    ui->port->clear();
    ui->textBrowser->clear();
}

void Dialog::on_connect_clicked()
{
    QString ip = ui->ip->toPlainText();
    QString port = ui->port->toPlainText();
}

void Dialog::on_Send_clicked()
{

}