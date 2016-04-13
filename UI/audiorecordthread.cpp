#include "audiorecordthread.h"

void AudioRecordThread::checkMicrophone()
{
    char data[MAX_LEN];
    int blockSize = buffer->size() - position;
    if (blockSize <= MAX_LEN)
    {
        return;
    }

    buffer->seek(position);
    buffer->read(data,MAX_LEN);
    position +=MAX_LEN;
    emit sendDataFromMic(data, MAX_LEN);
}
