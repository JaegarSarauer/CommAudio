#include "networkmanager.h"

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
    return true;
}
