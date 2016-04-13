#ifndef LOCALAUDIOMANAGER_H
#define LOCALAUDIOMANAGER_H

#include <QAudioFormat>
#include <QObject>
#include <QFile>
#include <QAudioOutput>
#include "wavheader.h"

class LocalAudioManager
{
public:
    LocalAudioManager(QObject * p) : parent(p) {
        audio = new QAudioOutput(QAudioFormat(), p);
    }

    QAudioOutput * playAudio();
    bool setupAudioPlayer(QFile * file);
    void setVolume(double volume);
    void stopAudio();
    void pauseAudio();
    void unpauseAudio();
    bool isPaused();
    bool isPlaying();

    ~LocalAudioManager();

private:
    bool PAUSED = false;
    bool PLAYING = false;
    QAudioFormat format;
    QAudioOutput *audio;
    QObject *parent;
    QFile *file;
    QIODevice *device;
    double constantVolume = 1.0;
};



#endif // LOCALAUDIOMANAGER_H
