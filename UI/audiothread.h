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
    void checkForEnding();

signals:
    void workFinished(const QString msg);

private:
    QIODevice * audioDevice;

};

#endif // AUDIOTHREAD_H
