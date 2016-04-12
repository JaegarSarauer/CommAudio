#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while (audioPlayer != NULL && audioPlayer->state() != QAudio::ActiveState) {
        qDebug() << "WON ONE 1";
    }
    while (audioPlayer != NULL && (audioPlayer->state() != QAudio::IdleState && audioPlayer->state() != QAudio::StoppedState)) {

        qDebug() << "TWO 2 TWO";
    }
    qDebug() << "JLJLKL";
    emit workFinished(QString("Song finished, playing next song."));
}
