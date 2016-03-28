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
    bool second;
signals:
public slots:
    void playAudio();
    void appendAudioData();
    void stopAudio();

};

#endif // NETWORKAUDIOPLAYER_H
