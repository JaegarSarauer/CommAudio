#ifndef NETWORKAUDIOPLAYER_H
#define NETWORKAUDIOPLAYER_H

#include <QObject>
#include <QAudioFormat>
#include <QAudioOutput>
#include <QIODevice>
#include "audiomanager.h"
#include "circularbuffer.h"
#include "networkmanager.h"

class NetworkAudioPlayer : public QObject
{
    Q_OBJECT
public:
    NetworkAudioPlayer();
    bool setup(QFile *);
    QAudioOutput * playAudio(NetworkManager * manager);

    void unpauseAudio();
    void sendAudio(NetworkManager * manager);
private:
    QAudioFormat format;
    QAudioOutput *audio;
    QIODevice * audioDevice;
    QAudioDeviceInfo deviceinfo;
    CircularBuffer * audioBuffer;
    NetworkManager * netManager;
    QFile * file;
    FILE * fp;
    AudioPlayThread * bufferListener;
    bool PAUSED = false;
    bool PLAYING = false;
signals:
    void finishedReading();
    void finishedWriting();
private slots:
    void loadDataIntoBuffer();
    void writeDataToDevice();
};

#endif // NETWORKAUDIOPLAYER_H
