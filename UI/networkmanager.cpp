#include <winsock2.h>
#include <WS2tcpip.h>
#include <windows.h>
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

SOCKET udpSocket;
SOCKET tcpSocket;
struct sockaddr_in udpPeer, tcpPeer;
SOCKET tcpAcceptSocket;
BOOL serverRunning = false;
int uPort, tPort;
HANDLE hWriteFile, hServerLogFile;
WSAEVENT udpEvent, tcpEvent;

DWORD WINAPI udpThread(LPVOID lpParameter);
DWORD WINAPI startUDPServer(LPVOID n);
void CALLBACK udpRoutine(DWORD, DWORD, LPOVERLAPPED, DWORD);
DWORD WINAPI tcpThread(LPVOID lpParameter);
DWORD WINAPI startTCPServer(LPVOID n);
void CALLBACK tcpRoutine(DWORD, DWORD, LPOVERLAPPED, DWORD);
void sendViaTCP();
void sendViaUDP();


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
    memset((char *)&tcpPeer, 0, sizeof(tcpPeer));
    tcpPeer.sin_family = AF_INET;
    tcpPeer.sin_port = htons(port);

    if ((hp = gethostbyname(hostname)) == NULL)
    {
        //writeToScreen("Can't get server's IP address");
        return;
    }

    memcpy((char *)&tcpPeer.sin_addr, hp->h_addr, hp->h_length);
    if (connect(tcpSocket, (struct sockaddr *)&tcpPeer, sizeof(tcpPeer)) == -1)
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

/*---------------------------------------------------------------------------------
--	FUNCTION: sendViaTCP
--
--	DATE:		Feb 14, 2016
--
--	REVISIONS:	Feb 14, 2016
--
--	DESIGNER:	Gabriella Cheung
--
--	PROGRAMMER:	Gabriella Cheung
--
--	INTERFACE:	void sendViaTCP(char * hostname, int port, int packetSize, int repetition, HANDLE file, HANDLE logFile)
--
--	PARAMETERS:	char *hostname - hostname of server
--				int port - port of server
--				int packetSize - size of packet to send
--				int repetition - number of packets to send
--				HANDLE file - handle for file for data to read from
--				HANDLE logFile - handle for client log file.
--
--	RETURNS:	void
--
--	NOTES:
--	This function handles the process of sending packets to the server using TCP.
--  First it creates a TCP socket, then it tries to establish a connection with
--  the server. If the connection was established successfully, it goes in a loop
--  where it gets the data from the getData method and sends the packet using the
--  WSASend method until all the packets to be sent has been sent. Finally it prints
--  out the details of the data transfer to the screen before closing the socket.
--
---------------------------------------------------------------------------------*/
void sendViaTCP()
{
    char *sbuf;
    char message[256];

    sbuf = (char*)malloc(DATA_BUFSIZE);

    // transmit data
    if (send(tcpSocket, sbuf, strlen(sbuf), 0) == -1)
    {
        //sprintf(message, "error: %d", WSAGetLastError());
        //writeToScreen(message);
    }
}

/*---------------------------------------------------------------------------------
--	FUNCTION: sendViaUDP
--
--	DATE:		Feb 14, 2016
--
--	REVISIONS:	Feb 14, 2016
--
--	DESIGNER:	Gabriella Cheung
--
--	PROGRAMMER:	Gabriella Cheung
--
--	INTERFACE:	void sendViaUDP(char * hostname, int port, int packetSize, int repetition, HANDLE file, HANDLE logFile)
--
--	PARAMETERS:	char *hostname - hostname of server
--				int port - port of server
--				int packetSize - size of packet to send
--				int repetition - number of packets to send
--				HANDLE file - handle for file for data to read from
--				HANDLE logFile - handle for client log file.
--
--	RETURNS:	void
--
--	NOTES:
--	This function handles the process of sending packets to the server using UDP.
--  First it creates a UDP socket, then in a loop it gets the data from the getData
--  method and sends the packet using the WSASendTo method until all the packets
--  has been sent. Finally it prints out the details of the data transfer to the
--	 screen before closing the socket.
--
---------------------------------------------------------------------------------*/
void sendViaUDP()
{
    char *sbuf;

    int server_len = sizeof(udpPeer);

    sbuf = (char*)malloc(DATA_BUFSIZE);

    // transmit data
    if (sendto(udpSocket, sbuf, strlen(sbuf), 0, (struct sockaddr *)&udpPeer, server_len) == -1)
    {
        //sprintf(message, "error: %d", WSAGetLastError());
        //writeToScreen(message);
    }
}

