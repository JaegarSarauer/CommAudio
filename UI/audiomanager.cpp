#include "audiomanager.h"

bool AudioManager::setupAudioPlayer(QFile * f) {
    file = f;
    wav_hdr wavHeader;
    file->open(QIODevice::ReadOnly);
    int bytesRead = file->read((char*)&wavHeader, sizeof(wav_hdr));
    //file->close();
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
    audioBuf = new CircularBuffer(4096, 100);
    return true;
}

void AudioManager::loadDataIntoBuffer()
{
    char tempBuf[4096];
    int bytesRead = file->read((char*)&tempBuf, sizeof(tempBuf));
    if (bytesRead <= 0)
    {
        //probably need to do more here
        return;
        //emit finished signal
    }
    audioBuf->cbWrite(tempBuf);
    emit finishedLoading();
}

void AudioManager::writeDataToDevice() {
    if (device == nullptr)
    {
        device = audio->start();
    }
    QByteArray * data = audioBuf->cbRead(1);
    device->write(data->data(), 4096);
}

QIODevice *AudioManager::playAudio() {
    if (!PAUSED) {
        //file->open(QIODevice::ReadOnly);
        //device = file;
        //audio->start(device);
        QThread *playThread = new QThread( );
        bufferListener = new AudioPlayThread(audioBuf);
        bufferListener->moveToThread(playThread);

        connect( playThread, SIGNAL(started()), this, SLOT(loadDataIntoBuffer()) );
        connect( this, SIGNAL(finishedLoading()), bufferListener, SLOT(checkBuffer()) );
        connect( this, SIGNAL(finishedLoading()), this, SLOT(writeDataToDevice()));
        connect( bufferListener, SIGNAL(addMoreData()), this, SLOT(loadDataIntoBuffer()) );

        //automatically delete thread and deviceListener object when work is done:
        //connect( audioThread, SIGNAL(finished()), deviceListener, SLOT(deleteLater()) );
        //connect( audioThread, SIGNAL(finished()), audioThread, SLOT(deleteLater()) );
        playThread->start();

    } else {
        unpauseAudio();
    }
    PLAYING = true;
    PAUSED = false;
    return device;
}

void AudioManager::setVolume(double volume) {
    constantVolume = volume;
    audio->setVolume(volume);
}

void AudioManager::stopAudio() {
    audio->stop();
    file->close();
    delete audio;
    PAUSED = false;
    PLAYING = false;
}

void AudioManager::pauseAudio() {
    PAUSED = true;
    audio->suspend();
}

void AudioManager::unpauseAudio() {
    audio->resume();
}

bool AudioManager::isPaused() {
    return PAUSED;
}

bool AudioManager::isPlaying() {
    return PLAYING;
}

AudioManager::~AudioManager()
{

}
