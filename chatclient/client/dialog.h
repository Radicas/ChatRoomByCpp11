#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTcpSocket>
#include <QHostAddress>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT    //默认是private的

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_clear_in_clicked();

    void on_connect_clicked();

    void on_Send_clicked();

    void on_disconnect_clicked();

    void read_data();

private:
    Ui::Dialog *ui;
    QString ip, send_text,recv_text;
    int port;
    QTcpSocket *sock;
    QHostAddress *ip_addr;
};
#endif // DIALOG_H
