#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <WinSock2.h>
#include "globalobjects.h"

#define UDP_PORT    7000

extern SOCKET udpSocket;
extern SOCKET tcpSocket;

class NetworkManager
{
public:
    //NetworkManager();
    bool startNetwork();
    void connectViaTCP(char * hostname, int port);
    void cleanUp();
    void setupUDPforP2P();

    bool tcpConnected;
private:
    struct sockaddr_in peer;
};

#endif // NETWORKMANAGER_H
