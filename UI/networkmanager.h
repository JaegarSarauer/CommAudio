#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "circularbuffer.h"

#define UDP_PORT        7000
#define TCP_PORT        8000
#define DATA_BUFSIZE    8196
#define MAXLEN          256
#define MAX_BLOCKS      100

class NetworkManager
{
public:
    //NetworkManager();
    bool startNetwork();
    void connectViaTCP(char * hostname, int port);
    void cleanUp();
    void setupUDPforP2P();
    bool createMulticastServerSocket(int port);
    void startUDPReceiver(int port);
    void startTCPReceiver(int port);
    void sendMulticast(char * buf, int length);

    bool tcpConnected;
private:
};

#endif // NETWORKMANAGER_H
