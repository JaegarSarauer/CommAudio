#include "audioplaythread.h"

void AudioPlayThread::checkBuffer() {
    while(buffer->isFull()) {
    }
    emit addMoreData();
}
