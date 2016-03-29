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
    //reading = true;
    if (blocksUnread == 0)
    {
        reading = false;
        emit stopReading();
    }
    if (blocksToRead > blocksUnread) {
        blocksToRead = blocksUnread;
    }
    QByteArray * readBlock = new QByteArray(buffer->mid(readPos, blockSize));
    //qstrncpy(readBlock, buffer[readPos], blockSize);
    //qstrcpy(readBlock, buffer->mid(readPos, blockSize));
    if (readBlock->length() != 0)
    {
        blocksUnread += blocksToRead;
        readPos += blockSize * blocksToRead;
        if (readPos == blockSize * numOfBlocks)
        {
            readPos = 0;
        }
    }
    return readBlock;
}

bool CircularBuffer::cbWrite(char * data)
{
    if (strlen(data) > blockSize)
    {
        //error
        return false;
    }
    if ((readPos > writePos) && (writePos + blockSize > readPos))
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
        if (blocksUnread > (0.2 * numOfBlocks) && !reading)
        {
            emit startReading();
            reading = true;
        }
        if ((readPos > writePos) && (writePos + (blockSize * 0.8 * numOfBlocks) >= readPos)) //getting close to overwriting data
        {
            emit stopWriting();
        }
        return true;
    }
}

bool CircularBuffer::isEmpty()
{
    return (readPos == writePos);
}

CircularBuffer::~CircularBuffer()
{
    if (buffer != NULL)
    {
        delete buffer;
    }
}


