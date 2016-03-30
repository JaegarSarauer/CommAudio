#include "sender.h"

Sender::Sender()
{

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
