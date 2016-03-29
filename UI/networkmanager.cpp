#include "networkmanager.h"

SOCKET udpSocket;
SOCKET tcpSocket;

bool NetworkManager::startNetwork()
{
    WSADATA wsaData;
    WORD wVersionRequested = MAKEWORD(2,2);
    int error;

    error = WSAStartup(wVersionRequested, &wsaData);
    if (error != 0)
    {
        //display error
        return false;
    }

    /*if ((tcpSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }

    if ((udpSocket = socket(PF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }*/

    if ((tcpSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }

    if ((udpSocket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }

    return true;
}

void NetworkManager::connectViaTCP(char * hostname, int port)
{
    struct hostent	*hp;

    // Store server's information
    memset((char *)&peer, 0, sizeof(peer));
    peer.sin_family = AF_INET;
    peer.sin_port = htons(port);

    if ((hp = gethostbyname(hostname)) == NULL)
    {
        //writeToScreen("Can't get server's IP address");
        return;
    }

    memcpy((char *)&peer.sin_addr, hp->h_addr, hp->h_length);
    if (connect(tcpSocket, (struct sockaddr *)&peer, sizeof(peer)) == -1)
    {
        //writeToScreen("Can't connect to server");
        return;
    }

    tcpConnected = true;
}

void NetworkManager::cleanUp()
{
    closesocket(udpSocket);
    closesocket(tcpSocket);
    WSACleanup();
}

void NetworkManager::setupUDPforP2P()
{
    struct sockaddr_in udpPeer;

    memset((char *)&udpPeer, 0, sizeof(udpPeer));
    udpPeer.sin_family = AF_INET;
    udpPeer.sin_port = htons(UDP_PORT);
    //udpPeer.sin_addr.s_addr = htonl(INADDR_ANY);
    udpPeer.sin_addr.s_addr = peer.sin_addr.s_addr; //does this work??

    if (bind(udpSocket, (struct sockaddr *)&udpPeer, sizeof(udpPeer)) == SOCKET_ERROR)
    {
        //writeToScreen("Can't bind name to socket");
        return;
    }
}
