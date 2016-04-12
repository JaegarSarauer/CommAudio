#ifndef MICROPHONEMANAGER_H
#define MICROPHONEMANAGER_H

#include <QObject>
#include <QAudioInput>
#include <QFile>
#include <QTimer>
#include <QDebug>
#include <QDir>

class MicrophoneManager : public QObject
{
    Q_OBJECT

public:

    MicrophoneManager(QObject *p) : parent(p) {}
    void RecordAudio();
    int RawToWavConvert(const char *rawfn, const char *wavfn, long frequency);

private slots:
    void stopRecording();
    void readDevice();

private:
    QObject *parent;
    QFile destinationFile;   // Class member
    QAudioInput* audio; // Class member

    QIODevice * audioDevice;
};

#endif // MICROPHONEMANAGER_H
