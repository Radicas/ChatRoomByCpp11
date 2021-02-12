#ifndef CONNECT_SERVER_H
#define CONNECT_SERVER_H

#include <QTcpSocket>
#include <QHostAddress>

class connect_server
{
public:
    connect_server();
    ~connect_server();
    void do_connect();
    void do_disconnect();
private:
    QTcpSocket *sock;
    QHostAddress *ip_addr;
    QString ip;
    int port;
};

#endif // CONNECT_SERVER_H
