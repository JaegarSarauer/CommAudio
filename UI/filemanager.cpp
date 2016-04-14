#include "filemanager.h"


FileManager::FileManager(NetworkManager *nManager)
{
    networkManager = nManager;
}

bool FileManager::requestFile(const char * fileName)
{
    //send file name to netmanager
    fp = fopen(fileName, "wb");




    return fp == NULL? false : true;
}

void FileManager::writeToFile(char * data, int length)
{
    fwrite(data, 1, length, fp);
    if (length > DATA_BUFSIZE)
    {
        fclose(fp);
        fp = NULL;
    }
}

void FileManager::checkBuffer()
{
    while(NetworkManager::tcpBuffer->getBlocksUnread() > 0)
    {
        writeToFile(NetworkManager::tcpBuffer->cbRead(1), NetworkManager::tcpBuffer->getLastBytesWritten());
    }
}
