#include "udpsendthread.h"

void UDPSendThread::send(char * buf, int length)
{
    if (sendto(socket, buf, length, 0, (struct sockaddr*)&destination, sizeof(destination)) == -1)
    {
        //sprintf(message, "error: %d", WSAGetLastError());
        //writeToScreen(message);
    }
}
