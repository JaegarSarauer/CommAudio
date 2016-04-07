#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include "circularbuffer.h"
#include "networkmanager.h"

class Receiver
{

public:
    void startUDPReceiver(int port);
    void startTCPReceiver(int port);

private:


signals:
    void stopSending();
    void startSending();
    void peerDisconnected();
    void connected();

public slots:
};

#endif // RECEIVER_H
