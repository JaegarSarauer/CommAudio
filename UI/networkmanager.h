#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include "circularbuffer.h"
#include "winsock.h"

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
    void connectViaTCP(const char * hostname, int port);
    void cleanUp();
    bool setupUDPforP2P(const char * hostname, int port);
    bool createMulticastServerSocket(int port);
    bool createMulticastClientSocket(const char* serverAddr, int port);
    void startUDPReceiver(CircularBuffer *);
    void startTCPReceiver(int port);
    void sendMulticast(char * buf, int length);
    void sendP2P(char * buf, int length);

    static CircularBuffer * incBuffer;
    static SOCKET acceptSocket;
    bool tcpConnected;
private:
};

#endif // NETWORKMANAGER_H
