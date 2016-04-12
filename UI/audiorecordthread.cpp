#include "audiorecordthread.h"

void AudioRecordThread::checkMicrophone()
{
    int blockSize = buffer->size() - position;
    if (blockSize <= 7000)
    {
        return;
    }
    QByteArray ba;

    buffer->seek(position);
    ba = buffer->read(blockSize);
    position +=blockSize;
    emit sendDataFromMic(ba.data(), blockSize);
}
