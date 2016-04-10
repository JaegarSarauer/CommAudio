#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while (audioPlayer->state() != QAudio::ActiveState) {}
    while (audioPlayer->state() != QAudio::IdleState) {}
    emit workFinished(QString("Song finished, playing next song."));
}
