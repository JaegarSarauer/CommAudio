#ifndef SENDER_H
#define SENDER_H

#include "networkmanager.h"

class Sender
{
public:
    Sender();
    void sendViaTCP();
    void sendViaUDP();
};

#endif // SENDER_H
