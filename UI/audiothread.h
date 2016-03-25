#ifndef AUDIOTHREAD_H
#define AUDIOTHREAD_H


#include <QObject>
#include <QIODevice>


class AudioThread : public QObject
{
    Q_OBJECT
public:
    AudioThread(QIODevice * aD) : audioDevice(aD) {}
    //AudioThread();
    ~AudioThread() {}

public slots:
    void doWork();

signals:
    void workFinished();

private:
    QIODevice * audioDevice;

};

#endif // AUDIOTHREAD_H
