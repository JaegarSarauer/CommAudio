#include "localaudiomanager.h"


bool LocalAudioManager::setupAudioPlayer(QFile * f) {
    file = f;
    wav_hdr wavHeader;
    file->open(QIODevice::ReadOnly);
    int bytesRead = file->read((char*)&wavHeader, sizeof(wav_hdr));
    file->close();
    if (bytesRead <= 0)
        return false;

    format.setSampleRate(wavHeader.SamplesPerSec);
    format.setChannelCount(wavHeader.NumOfChan);
    format.setSampleSize(wavHeader.bitsPerSample);

    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    audio = new QAudioOutput(format, parent);
    audio->setVolume(constantVolume);
    return true;
}

QAudioOutput *LocalAudioManager::playAudio() {
    if (!PAUSED) {
        file->open(QIODevice::ReadOnly);
        device = file;
        audio->start(device);
    } else {
        unpauseAudio();
    }
    PLAYING = true;
    PAUSED = false;
    return audio;
}

void LocalAudioManager::setVolume(double volume) {
    constantVolume = volume;
    audio->setVolume(volume);
}


void LocalAudioManager::stopAudio() {
    audio->stop();
    file->close();
    delete audio;
    PAUSED = false;
    PLAYING = false;
}

void LocalAudioManager::pauseAudio() {
    PAUSED = true;
    audio->suspend();
}

void LocalAudioManager::unpauseAudio() {
    audio->resume();
}

bool LocalAudioManager::isPaused() {
    return PAUSED;
}

bool LocalAudioManager::isPlaying() {
    return PLAYING;
}
