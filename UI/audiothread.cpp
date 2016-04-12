#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while (audioPlayer != NULL && audioPlayer->state() != QAudio::ActiveState) {}
    while (audioPlayer != NULL && audioPlayer->state() != QAudio::IdleState && audioPlayer->state() != QAudio::StoppedState) {}
    qDebug() << "JLJLKL";
    emit workFinished(QString("Song finished, playing next song."));
}
