#ifndef CIRCULARBUFFER_H
#define CIRCULARBUFFER_H

#include <QObject>

class CircularBuffer : public QObject
{
    Q_OBJECT
public:
    CircularBuffer(int size, int blocks);
    bool cbWrite(const char * data, size_t length);
    char * cbRead(int blocksToRead);
    bool isEmpty();
    bool isFull();
    int getBlocksUnread();
    int getLastBytesWritten();
    ~CircularBuffer();
private:
    QByteArray * buffer;
    int readPos;
    int writePos;
    int blockSize;
    int numOfBlocks;
    int blocksUnread;
    bool reading;
    int bufferSize;
    int bytesWritten;
signals:
    void stopWriting();
    void startReading();
    void stopReading();
};

#endif // CIRCULARBUFFER_H
