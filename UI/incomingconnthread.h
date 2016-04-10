#ifndef INCOMINGCONNTHREAD_H
#define INCOMINGCONNTHREAD_H

#include <QObject>

class IncomingConnThread : public QObject
{
    Q_OBJECT
public:
    IncomingConnThread(void * s) : socket(s) {}
    ~IncomingConnThread(){}

public slots:
    void checkForConnection();

signals:
    void tcpConnected();

private:
    void * socket;

};

#endif // INCOMINGCONNTHREAD_H
