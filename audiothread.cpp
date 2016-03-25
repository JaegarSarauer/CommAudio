#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::doWork() {
    while(!audioDevice->atEnd()) {
        qDebug() << "Not at end";
    }
    emit workFinished();
}
