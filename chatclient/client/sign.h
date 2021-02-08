#ifndef SIGN_H
#define SIGN_H
#include <QTcpSocket>
#include <QDialog>
#include <QHostAddress>


namespace Ui {
class sign;
}

class sign : public QDialog
{
    Q_OBJECT

public:
    explicit sign(QWidget *parent = nullptr);
    ~sign();
signals:
    void reg_to_login();

public slots:
    void show_this();

private slots:
    void on_go_login_clicked();

    void on_register_2_clicked();

private:
    Ui::sign *ui;
    QTcpSocket *sign_sock;
    QHostAddress *ip_addr;
    QString ip;
    int port;
};

#endif // SIGN_H
