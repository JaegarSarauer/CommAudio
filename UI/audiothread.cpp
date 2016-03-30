#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while(!audioDevice->atEnd()) {}
    emit workFinished(QString("Song finished, playing next song."));
}
