#include "audiothread.h"
#include <QDebug>

//AudioThread::AudioThread() {

//}

void AudioThread::checkForEnding() {
    while(!audioFile->atEnd()) {}
    emit workFinished(QString("Song finished, playing next song."));
}
