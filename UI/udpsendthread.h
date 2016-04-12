#ifndef UDPSENDTHREAD_H
#define UDPSENDTHREAD_H

#include <QObject>
#include <winsock.h>

class UDPSendThread : public QObject
{
    Q_OBJECT
public:
    UDPSendThread(SOCKET sock, struct sockaddr_in dest) : socket(sock), destination(dest){}

public slots:
    void send(char * buf, int length);

private:
    SOCKET socket;
    struct sockaddr_in destination;
};

#endif // UDPSENDTHREAD_H
