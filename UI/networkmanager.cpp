#include <winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
#include "networkmanager.h"


SOCKET udpSocket;
SOCKET tcpSocket;
struct sockaddr_in udpPeer;

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

    /*if ((tcpSocket = WSASocket(AF_INET, SOCK_STREAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }

    if ((udpSocket = WSASocket(AF_INET, SOCK_DGRAM, 0, NULL, 0, WSA_FLAG_OVERLAPPED)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }*/

    return true;
}

bool NetworkManager::createMulticastServerSocket()
{
    struct ip_mreq stMreq;
    SOCKADDR_IN stLclAddr, stDstAddr;
    BOOL  fFlag = FALSE;

    if ((udpSocket = socket(AF_INET, SOCK_DGRAM, 0)) == INVALID_SOCKET)
    {
        //display error
        return false;
    }
    stLclAddr.sin_family = AF_INET;
    stLclAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    stLclAddr.sin_port = 0;
    if (bind(udpSocket, (struct sockaddr*) &stLclAddr, sizeof(stLclAddr)) == SOCKET_ERROR)
    {
        //display error
        return false;
    }

    stMreq.imr_multiaddr.s_addr = inet_addr("234.5.6.7");
    stMreq.imr_interface.s_addr = INADDR_ANY;
    if (setsockopt(udpSocket, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&stMreq, sizeof(stMreq)) == SOCKET_ERROR)
    {
        //display error
        return false;
    }

    /* Disable loopback */
    if (setsockopt(udpSocket, IPPROTO_IP, IP_MULTICAST_LOOP, (char *)&fFlag, sizeof(fFlag)) == SOCKET_ERROR)
    {
        //display error
        return false;
    }

    /* Assign our destination address */
    stDstAddr.sin_family = AF_INET;
    stDstAddr.sin_addr.s_addr = inet_addr("234.5.6.7");
    stDstAddr.sin_port = htons(7000);

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
    memset((char *)&udpPeer, 0, sizeof(udpPeer));
    udpPeer.sin_family = AF_INET;
    udpPeer.sin_port = htons(UDP_PORT);
    udpPeer.sin_addr.s_addr = htonl(INADDR_ANY);
    //udpPeer.sin_addr.s_addr = peer.sin_addr.s_addr; //does this work??

    if (bind(udpSocket, (struct sockaddr *)&udpPeer, sizeof(udpPeer)) == SOCKET_ERROR)
    {
        //writeToScreen("Can't bind name to socket");
        return;
    }
}
