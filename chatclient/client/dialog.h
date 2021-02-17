#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>
#include "connect_server.h"
QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT    //默认是private的

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QString  get_user_name(QString user_name);

private slots:
    void on_clear_in_clicked();

    void on_Send_clicked();

    void on_disconnect_clicked();

    void read_data();

private:
    QString usr_name;
    Ui::Dialog *ui;
    QString send_text,recv_text;
    connect_server* conn;
};
#endif // DIALOG_H
