#include "incomingconnthread.h"

void IncomingConnThread::checkForConnection() {
    while (socket == NULL) {}
    emit tcpConnected();
}
