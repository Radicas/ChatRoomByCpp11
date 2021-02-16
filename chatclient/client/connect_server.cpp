#include "connect_server.h"

connect_server::connect_server()
{
    sock = new QTcpSocket();
    ip_addr = new QHostAddress();
    port = 999;
    ip = "160.119.70.109";
    ip_addr->setAddress(ip);
}

connect_server::~connect_server()
{
    delete sock;
    delete ip_addr;
}

void connect_server::do_connect()
{
    sock->connectToHost(*ip_addr, port);

}

void connect_server::do_disconnect()
{
    sock->disconnectFromHost();
}

void connect_server::do_write(QString msg)
{
    sock->write(msg.toLatin1());
}

QTcpSocket* connect_server::get_sock()
{
    return sock;
}
