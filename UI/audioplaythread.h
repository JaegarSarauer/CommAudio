#ifndef AUDIOPLAYTHREAD_H
#define AUDIOPLAYTHREAD_H

#include <QObject>
#include "circularbuffer.h"

class AudioPlayThread : public QObject
{
    Q_OBJECT
public:
    AudioPlayThread(CircularBuffer * buf);
    //AudioPlayThread();

signals:
    void addMoreData();
    void finished();
    void bufferHasData();

public slots:
    void checkBuffer();

private:
    CircularBuffer * buffer;
    bool stopChecking;
};

#endif // AUDIOPLAYTHREAD_H
