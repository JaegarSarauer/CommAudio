#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while (audio->state() != QAudio::ActiveState) {}
    while (audio->state() != QAudio::IdleState) {}
    //emit workFinished(QString("Song finished, playing next song."));
    qDebug() << "END THIS";
}
