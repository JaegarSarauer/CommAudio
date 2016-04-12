#include "audioplaythread.h"
#include <QDebug>

AudioPlayThread::AudioPlayThread(CircularBuffer * buf)
{
    buffer = buf;
    stopChecking = false;
}

void AudioPlayThread::checkBuffer() {
    while (buffer->getBlocksUnread() == 0)
    {
    }
    emit bufferHasData();
}
