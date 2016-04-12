#include "audiomanager.h"
#include <iostream>
#include <QDebug>

QIODevice *device;
QThread *playThread;

bool AudioManager::setupAudioPlayer(QFile * f) {
    file = f;
    wav_hdr wavHeader;
    file->open(QIODevice::ReadOnly);
    int bytesRead = file->read((char*)&wavHeader, sizeof(wav_hdr));
   // file->close();
    if (bytesRead <= 0)
        return false;

    qDebug() << "SALSA " << wavHeader.SamplesPerSec << " " << wavHeader.NumOfChan << " " << wavHeader.bitsPerSample;

    format.setSampleRate(wavHeader.SamplesPerSec);
    format.setChannelCount(wavHeader.NumOfChan);
    format.setSampleSize(wavHeader.bitsPerSample);

    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    audio = new QAudioOutput(format, parent);
    audio->setVolume(constantVolume);
    audio->setBufferSize(DATA_BUFSIZE * 10);

    return true;
}

bool AudioManager::setupAudioPlayerNoFile() {
    /*format.setSampleRate(44100);
    format.setChannelCount(2);
    format.setSampleSize(16);

    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);

    audio = new QAudioOutput(format, parent);
    audio->setVolume(constantVolume);
    audio->setBufferSize(40960);

    audioBuf = new CircularBuffer(DATA_BUFSIZE, MAX_BLOCKS);*/
    return true;
}

void AudioManager::loadDataIntoBuffer()
{
    char tempBuf[DATA_BUFSIZE];
    if(!audioBuf->isFull())
    {
        int bytesRead = file->read((char*)&tempBuf, sizeof(tempBuf));
        if (bytesRead <= 0)
        {
            emit finishedReading();
            //file->close();
        }
        audioBuf->cbWrite(tempBuf, bytesRead);
        //emit finishedLoading();
    }
}

void AudioManager::writeDataToDevice() {
    qDebug() << "WHAT NOW";
    if (PAUSED)
        return;
    if (audio == NULL) {
        file->close();
        emit finishedReading();
        qDebug() << "WHAT NOW!!!!!!!";
        return;
    }
    int freeSpace = audio->bytesFree();
    if (freeSpace < DATA_BUFSIZE)
    {
        if (!PAUSED)
            emit finishedWriting();
        return;
    } else {
        char * data = audioBuf->cbRead(1);
        int length = audioBuf->getLastBytesWritten();
        device->write(data, length);
        emit finishedWriting();
    }
    //if (file != NULL) {
        if(!file->atEnd())
        {
           loadDataIntoBuffer();
        } else if (!PAUSED){
            file->close();
            //signal to peer2peer to load next file?????
        }
    //}
}

QAudioOutput *AudioManager::playAudio() {
    //if (!PLAYING && !PAUSED)
    //    return NULL;
    if (!PAUSED) {
        qDebug() << "this is";
        if (!playThread)
        {

            playThread = new QThread( );
        } else {
            if (playThread->isRunning())
            {
                //stop thread
                playThread->terminate();
                delete playThread;
                playThread = NULL;
                playThread = new QThread();
            }
        }
            device = audio->start();
        bufferListener = new AudioPlayThread(audioBuf);
        bufferListener->moveToThread(playThread);

        connect( playThread, SIGNAL(started()), this, SLOT(loadDataIntoBuffer()) );
        connect( playThread, SIGNAL(started()), bufferListener, SLOT(checkBuffer()) );
        connect( this, SIGNAL(finishedWriting()), bufferListener, SLOT(checkBuffer()) );
        connect( this, SIGNAL(killPlayThread()), bufferListener, SLOT(forceKill()) );
        connect( bufferListener, SIGNAL(bufferHasData()), this, SLOT(writeDataToDevice()));

        //connect (audio, SIGNAL(stateChanged(QAudio::State)), this, SLOT(checkDeviceStatus(QAudio::State)));

        //connect( this, SIGNAL(finishedReading()), bufferListener, SLOT(forceKill()) );

        //connect(bufferListener, SIGNAL(finished()), playThread, SLOT(quit()));

        //automatically delete thread and deviceListener object when work is done:
        //connect( playThread, SIGNAL(finished()), bufferListener, SLOT(deleteLater()) );
        //connect( playThread, SIGNAL(finished()), playThread, SLOT(deleteLater()) );
        playThread->start();

    } else {
        unpauseAudio();
    }
    PLAYING = true;
    PAUSED = false;
    return audio;
}

/*void AudioManager::checkSongFinished(QAudio::State state)
{
    if (state == QAudio::StoppedState && file->atEnd())
    {
        //kill thread!!!!

    }
}*/

void AudioManager::setVolume(double volume) {
    constantVolume = volume;
    audio->setVolume(volume);
}

bool AudioManager::stopAudio() {
    PAUSED = false;
    PLAYING = false;
    emit finishedWriting();
    if (audio == NULL)
        return false;
    //delete audioBuf;
    qDebug() << "WHAT1";
    //audio->deleteLater();
    audio->destroyed();
    //delete audio;
    qDebug() << "WHAT2";
    audio = NULL;
    qDebug() << "WHAT3";
    if (playThread != NULL) {
        emit killPlayThread();
        playThread->terminate();
        //delete playThread;
        playThread = NULL;
    }
    qDebug() << "WHAT32";
    //delete bufferListener;
    //bufferListener = NULL;

    //audio->stop();
    //file->close();
    return true;
}

void AudioManager::pauseAudio() {
    PAUSED = true;
    qDebug() << "pause audio func 22";
    audio->suspend();
    qDebug() << "pause audio func";
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
        audio = NULL;
        emit killPlayThread();
        //playThread->terminate();
        //delete playThread;
        //playThread = NULL;
}

CircularBuffer * AudioManager::getAudioBuffer()
{
    return audioBuf;
}
