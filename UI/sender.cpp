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
void sendViaTCP(char * hostname, int port)
{
    int err, server_len;
    struct hostent	*hp;
    struct sockaddr_in server;
    char *sbuf;
    HANDLE hFile = NULL, hLogFile;
    char message[256];

    sbuf = (char*)malloc(PACKETSIZE);

    // transmit data
    server_len = sizeof(server);

    getData(hFile, sbuf, PACKETSIZE);
    if (send(sd, sbuf, strlen(sbuf), 0) == -1)
    {
        sprintf(message, "error: %d", WSAGetLastError());
        writeToScreen(message);
    }
}
