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

private:
    QString ip = "23.254.142.59";
    int port = 666;
    Ui::Dialog *ui;
    QTcpSocket *sock;
    QHostAddress *ip_addr;
};
#endif // DIALOG_H
