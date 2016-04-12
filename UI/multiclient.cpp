#include "multiclient.h"
#include "ui_multiclient.h"


MultiClient::MultiClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiClient)
{
    ui->setupUi(this);
    audioManager = new AudioManager(this);
}

MultiClient::~MultiClient()
{
    delete ui;
}

void MultiClient::on_buttonPlay_released()
{
}




void MultiClient::on_buttonConnect_released()
{
    CircularBuffer * incomingBuffer;
    if (!netManager->startNetwork())
    {
        return;
    }
    std::string serverAddr = ui->lineIPAddress->text().toStdString();
    int port = ui->linePort->text().toInt();
    if (!netManager->createMulticastClientSocket(serverAddr.c_str(), port))
    {
        return;
    }

    QThread * playThread = new QThread();
    audioManager->setupAudioPlayerNoFile(NetworkManager::incBuffer);
    //incomingBuffer = audioManager->getAudioBuffer();
    //netManager->startUDPReceiver(incomingBuffer); //pass in circular buffer here
    netManager->startUDPReceiver(NULL);

    bufferListener = new AudioPlayThread(NetworkManager::incBuffer);
    bufferListener->moveToThread(playThread);

    connect (playThread, SIGNAL(started()), bufferListener, SLOT(checkBuffer()));
    connect( bufferListener, SIGNAL(bufferHasData()), audioManager, SLOT(writeDataToDevice()));
    connect( audioManager, SIGNAL(finishedWriting()), bufferListener, SLOT(checkBuffer()));
    playThread->start();
}
