#include "circularbuffer.h"
#include <QByteArray>

CircularBuffer::CircularBuffer(int size, int blocks)
{
    blockSize = size;
    numOfBlocks = blocks;
    buffer = new QByteArray(blockSize * numOfBlocks, '\0');
    bufferSize = buffer->size();
    readPos = 0;
    writePos = 0;
    reading = false;
    blocksUnread = 0;
}

char * CircularBuffer::cbRead(int blocksToRead)
{
    int oldReadPos = readPos;
    blocksUnread -= blocksToRead;
    readPos += blockSize * blocksToRead;
    if (readPos == blockSize * numOfBlocks)
    {
        readPos = 0;
    }
    //return &buffer[oldReadPos];
    return &(buffer->data()[oldReadPos]);
}

bool CircularBuffer::cbWrite(const char * data, size_t length)
{
    /*size_t datalen = strlen(data);
    if (datalen > blockSize )
    {
        //error
        return false;
    }
    /*if (blocksUnread == numOfBlocks) // buffer full
    {
        //error
        return false;
    }
    else
    {*/
        buffer->insert(writePos, data, length);
        blocksUnread++;
        writePos += blockSize;
        if (writePos == blockSize * numOfBlocks) //reached the end
        {
            writePos = 0;
        }
        return true;
    //}
}

bool CircularBuffer::isEmpty()
{
    return (blocksUnread == 0);
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


