#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <WinSock2.h>
#include "globalobjects.h"
#include "networkmanager.h"

typedef struct _SOCKET_INFORMATION {
    OVERLAPPED Overlapped;
    SOCKET Socket;
    CHAR Buffer[DATA_BUFSIZE];
    int head = 0;
    int tail = 0;
    WSABUF DataBuf;
    DWORD Timeout;

} SOCKET_INFORMATION, *LPSOCKET_INFORMATION;

class Receiver
{

public:
    void startUDPReceiver(int port);
    void startTCPReceiver(int port);

private:


signals:
    void stopSending();
    void startSending();
    void peerDisconnected();
    void connected();

public slots:
};

#endif // RECEIVER_H
