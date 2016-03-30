#include "circularbuffer.h"
#include <QByteArray>

CircularBuffer::CircularBuffer(int size, int blocks)
{
    blockSize = size;
    numOfBlocks = blocks;
    buffer = new QByteArray(blockSize * numOfBlocks, '\0');
    readPos = 0;
    writePos = 0;
    reading = false;
    blocksUnread = 0;
}

QByteArray * CircularBuffer::cbRead(int blocksToRead)
{
    int oldReadPos = readPos;
    blocksUnread += blocksToRead;
    readPos += blockSize * blocksToRead;
    if (readPos == blockSize * numOfBlocks)
    {
        readPos = 0;
    }
    return &buffer[oldReadPos];
}

bool CircularBuffer::cbWrite(const char * data)
{
    if (strlen(data) > blockSize)
    {
        //error
        return false;
    }
    if (blocksUnread == numOfBlocks) // buffer full
    {
        //error
        return false;
    }
    else
    {
        buffer->insert(writePos, data);
        blocksUnread++;
        writePos += blockSize;
        if (writePos == blockSize * numOfBlocks) //reached the end
        {
            writePos = 0;
        }
        return true;
    }
}

bool CircularBuffer::isEmpty()
{
    return (readPos == writePos && blocksUnread == 0);
}

bool CircularBuffer::isFull()
{
    return blocksUnread == numOfBlocks;
}

int CircularBuffer::getBlocksUnread()
{
    return blocksUnread;
}

CircularBuffer::~CircularBuffer()
{
    if (buffer != NULL)
    {
        delete buffer;
    }
}


