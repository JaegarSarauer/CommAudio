#ifndef AUDIORECORDTHREAD_H
#define AUDIORECORDTHREAD_H

#include <QObject>
#include <QIODevice>

class AudioRecordThread : public QObject
{
    Q_OBJECT
public:
    AudioRecordThread(QIODevice * buf): buffer(buf), position(0) {}

private:
    QIODevice * buffer;
    long int position;
public slots:
    void checkMicrophone();
signals:
    void sendDataFromMic(char *, int);
};

#endif // AUDIORECORDTHREAD_H
