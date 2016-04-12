#ifndef MICROPHONEMANAGER_H
#define MICROPHONEMANAGER_H

#include <QObject>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QDir>
#include <QBuffer>
#include <QThread>
#include "audiorecordthread.h"
#include "networkmanager.h"

class MicrophoneManager : public QObject
{
    Q_OBJECT

public:

    MicrophoneManager(QObject *p, NetworkManager* netManager) : parent(p), networkManager(netManager){}
    void RecordAudio();
    int RawToWavConvert(const char *rawfn, const char *wavfn, long frequency);

private slots:
    void stopRecording();
    void sendData(char * data, int length);

private:
    QObject *parent;
    QFile destinationFile;   // Class member
    QAudioInput* audio; // Class member

    QIODevice * audioDevice;
    QBuffer *buffer;
    NetworkManager * networkManager;
};

#endif // MICROPHONEMANAGER_H
