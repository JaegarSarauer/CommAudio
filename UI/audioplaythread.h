#ifndef AUDIOPLAYTHREAD_H
#define AUDIOPLAYTHREAD_H

#include <QObject>
#include "circularbuffer.h"

class AudioPlayThread : public QObject
{
    Q_OBJECT
public:
    AudioPlayThread(CircularBuffer * buf){
        buffer = buf;
    }
    void checkBuffer();

signals:
    void addMoreData();

private:
    CircularBuffer * buffer;

};

#endif // AUDIOPLAYTHREAD_H
