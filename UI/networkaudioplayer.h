#ifndef NETWORKAUDIOPLAYER_H
#define NETWORKAUDIOPLAYER_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QBuffer>
#include <QIODevice>
#include "audiomanager.h"
#include "globalobjects.h"
#include "receiver.h"

class NetworkAudioPlayer : public QObject
{
public:
    NetworkAudioPlayer();
    void setParameters();
private:
    QAudioFormat format;
    QAudioOutput *audio;
    QBuffer outputBuffer[2];
    QIODevice * audioDevice;
    QAudioDeviceInfo deviceinfo;
    bool second;
signals:
public slots:
    void playAudio();
    void appendAudioData(qint64 bytesWritten);
    void stopAudio();

};

#endif // NETWORKAUDIOPLAYER_H
