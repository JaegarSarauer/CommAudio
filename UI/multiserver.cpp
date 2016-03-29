#include "multiserver.h"
#include "ui_multiserver.h"
#include <QtDebug>
#include "networkmanager.h"
#include "receiver.h"
#include "networkaudioplayer.h"

NetworkManager netManager;

MultiServer::MultiServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiServer)
{
    ui->setupUi(this);
    audioManager = new AudioManager(this);
    QDir dir;
    ui->listMusicFiles->addItems(dir.entryList(QStringList("*.wav")));
    currentQueueIndex = -1;
}

MultiServer::~MultiServer()
{
    delete ui;
}

void MultiServer::on_pushButton_4_released()
{
    if (audioManager->isPaused()) {
        audioManager->playAudio();
    } else {
        playNextSong();
    }
}

void MultiServer::on_buttonStopAudio_released()
{
    audioManager->stopAudio();
}

void MultiServer::on_buttonPauseAudio_released()
{
    audioManager->pauseAudio();
}

void MultiServer::on_sliderSound_actionTriggered(int action)
{
    audioManager->setVolume((double)ui->sliderSound->sliderPosition() / 100);
}



void MultiServer::on_QueueAddButton_released()
{
    QList<QListWidgetItem *> selectedFile = ui->listMusicFiles->selectedItems();
    QListWidgetItem * index = selectedFile.front();
    ui->listQueueFiles->addItem(index->text());
}

void MultiServer::playNextSong() {
    qDebug() << "SO NICE";
    if (ui->listQueueFiles->count() <= 0) {
        updateStatusBar("No songs in queue.");
        return;
    }

    for (int i = 0; i < ui->listQueueFiles->count(); i++) {
        ui->listQueueFiles->item(i)->setBackgroundColor(Qt::white);
    }

    currentQueueIndex++;

    //go back to beginning of the list
    if (currentQueueIndex > ui->listQueueFiles->count() - 1) {
        currentQueueIndex = 0;
    }

    QListWidgetItem * current = ui->listQueueFiles->item(currentQueueIndex);
    current->setBackgroundColor(Qt::green);
    audioManager->setupAudioPlayer(new QFile(current->text()));
    QIODevice * device = audioManager->playAudio();
    /*AudioThread * deviceListener = new AudioThread(device);
    deviceListener->start();*/
    QThread *thread = new QThread( );
    AudioThread *deviceListener = new AudioThread(device);
    deviceListener->moveToThread(thread);
    connect( thread, SIGNAL(started()), deviceListener, SLOT(doWork()) );
    connect( deviceListener, SIGNAL(workFinished()), thread, SLOT(quit()) );
    connect( deviceListener, SIGNAL(workFinished()), this, SLOT(playNextSong()) );
    //automatically delete thread and deviceListener object when work is done:
    connect( thread, SIGNAL(finished()), deviceListener, SLOT(deleteLater()) );
    connect( thread, SIGNAL(finished()), thread, SLOT(deleteLater()) );
    thread->start();
}

void quit() {
    qDebug() << "We done";
}

void MultiServer::updateStatusBar(const QString msg) {
    ui->playingStatusBar->setText(msg);
}

void MultiServer::on_QueueRemoveButton_released()
{
    QList<QListWidgetItem *> indexes = ui->listQueueFiles->selectedItems();
    qDeleteAll(indexes.begin(), indexes.end());
}

void MultiServer::on_SendAudioButton_released()
{
    //qDebug() << "Send";
    //NetworkManager netManager;
   // netManager.startNetwork();
    //Receiver r;
    //r.startUDPReceiver(7000);
}

void MultiServer::on_StopSendingButton_released()
{
    qDebug() << "Stop";
    netManager.startNetwork();
    char host[20] = "192.168.0.10";
    netManager.connectViaTCP(host, 8000);
    netManager.setupUDPforP2P();
    Receiver r;
    r.startUDPReceiver(7000);
    QThread * thread = new QThread( );
    NetworkAudioPlayer * netPlayer = new NetworkAudioPlayer();
    netPlayer->setParameters();
    netPlayer->moveToThread(thread);

    connect (audioBuffer, &CircularBuffer::stopReading, netPlayer, &NetworkAudioPlayer::stopAudio);
    connect (audioBuffer, &CircularBuffer::startReading, netPlayer, &NetworkAudioPlayer::playAudio);

    thread->start();

}
