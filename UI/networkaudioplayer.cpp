#include "networkaudioplayer.h"

NetworkAudioPlayer::NetworkAudioPlayer()
{
    second = false;
}

void NetworkAudioPlayer::setParameters()
{
    wav_hdr wavHeader;
    format.setSampleRate(wavHeader.SamplesPerSec);
    format.setChannelCount(wavHeader.NumOfChan);
    format.setSampleSize(wavHeader.bitsPerSample);

    format.setCodec("audio/pcm");
    format.setByteOrder(QAudioFormat::LittleEndian);
    format.setSampleType(QAudioFormat::UnSignedInt);
    audio = new QAudioOutput(format);
    audio->setVolume(1.0);
    audio->setBufferSize(DATA_BUFSIZE * 0.1 * MAX_BLOCKS);
    audioDevice = audio->start();
    connect (audioDevice, SIGNAL(aboutToClose()), this, SLOT(appendAudioData));
    connect (audioBuffer, SIGNAL(stopReading()), this, SLOT(stopAudio));
}

void NetworkAudioPlayer::playAudio()
{
    EnterCriticalSection(&bufferAccess);
    char * data = audioBuffer->cbRead(0.1 * MAX_BLOCKS);
    LeaveCriticalSection(&bufferAccess);
    outputBuffer[0].setData(data);
    second = true;
    audioDevice->write(outputBuffer[0].buffer());
}

void NetworkAudioPlayer::appendAudioData()
{
    EnterCriticalSection(&bufferAccess);
    char * data = audioBuffer->cbRead(0.1 * MAX_BLOCKS);
    LeaveCriticalSection(&bufferAccess);

    if (second)
    {
        outputBuffer[1].setData(data);
        audioDevice->write(outputBuffer[1].buffer());
        second = false;
    } else {
        outputBuffer[0].setData(data);
        audioDevice->write(outputBuffer[0].buffer());
        second = true;
    }
}

void NetworkAudioPlayer::stopAudio()
{
    disconnect(audioDevice, SIGNAL(aboutToClose()));
}
