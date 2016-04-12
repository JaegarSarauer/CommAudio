#include "multiserver.h"
#include "ui_multiserver.h"

/*
 * Constructor for the multiserver window class.
 */
MultiServer::MultiServer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiServer)
{
    ui->setupUi(this);
    if (!QDir(QDir::currentPath() + "/MusicFiles").exists())
        QDir().mkdir(QDir::currentPath() + "/MusicFiles");
    audioManager = new AudioManager(this);
    QDir dir = (QDir::currentPath() + "/MusicFiles/");
    QStringList locals = dir.entryList(QStringList("*.wav"));
    for (int i = 0; i < locals.length(); i++)
        ui->listMusicFiles->addItem(QDir::currentPath() + "/MusicFiles/" + locals.at(i));
    currentQueueIndex = -1;
    netAudioPlayer = new NetworkAudioPlayer();
}

/*
 * Destructor for the multi server window class.
 */
MultiServer::~MultiServer()
{
    delete ui;
}

/*void MultiServer::on_sliderSound_actionTriggered(int action)
{
    audioManager->setVolume((double)ui->sliderSound->sliderPosition() / 100);
}*/

void MultiServer::on_QueueAddButton_released()
{
    QList<QListWidgetItem *> selectedFile = ui->listMusicFiles->selectedItems();
    if (selectedFile.size() < 1)
        return;
    QListWidgetItem * index = selectedFile.front();
    ui->listQueueFiles->addItem(index->text());
}

/*
 * This function will play the next song in the list. It is auto triggered if it finds the
 * currently playing song has finished.
 */
void MultiServer::playNextSong() {
    if (stopThreadLoop) {
        disconnect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(AddStatusMessage(QString)) );
        disconnect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(playNextSong()) );
        stopThreadLoop = false;
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
    /*audioManager->setupAudioPlayer(new QFile(current->text()));
    QIODevice * device = audioManager->playAudio();

    QThread *audioThread = new QThread( );
    deviceListener = new AudioThread(device);
    deviceListener->moveToThread(audioThread);

    connect( audioThread, SIGNAL(started()), deviceListener, SLOT(checkForEnding()) );
    connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(AddStatusMessage(QString)) );
    connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(playNextSong()) );
    //automatically delete thread and deviceListener object when work is done:
    connect( audioThread, SIGNAL(finished()), deviceListener, SLOT(deleteLater()) );
    connect( audioThread, SIGNAL(finished()), audioThread, SLOT(deleteLater()) );
    audioThread->start();*/

    netAudioPlayer->setup(new QFile(current->text()));
    QAudioOutput * audioOut = netAudioPlayer->playAudio(netManager);

    QThread * queueThread = new QThread();
    deviceListener = new AudioThread(audioOut);
    deviceListener->moveToThread(queueThread);
    connect( queueThread, SIGNAL(started()), deviceListener, SLOT(checkForEnding()) );
    connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(AddStatusMessage(QString)) );
    connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(playNextSong()) );
    connect( deviceListener, SIGNAL(workFinished(const QString)), queueThread, SLOT(quit()) );
    //automatically delete thread and deviceListener object when work is done:
    connect( queueThread, SIGNAL(finished()), deviceListener, SLOT(deleteLater()) );
    connect( queueThread, SIGNAL(finished()), queueThread, SLOT(deleteLater()) );
    queueThread->start();
}

/*
 * This function will add a status message to the status bar.
 */
void MultiServer::AddStatusMessage(const QString msg) {
    if (!stopThreadLoop)
        ui->StatusBar->addItem(QString(msg));
}

/*
 * This function will remove the selected songs from the queue list when
 * the user clicks the remove queue button.
 */
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


/*
 * This function will be called by the network layer to notify the application layer
 * with a confirmation message on a successful connection.
 * param bool connected = if true, successful connection, else, connection failed.
 */
// ---- TODO ---- call this function on successful connection
void MultiServer::successfulConnection(bool connected) {
    if (connected)
        AddStatusMessage("Connection Successful!");
    else
        AddStatusMessage("Unable to connect to peer.");
}

void MultiServer::on_BroadcastButton_released()
{
    if (isDataSending) {
        ui->BroadcastButton->setText("Broadcast");
        isDataSending = false;
        return;
    } else {
        if (isMicrophoneSending) {
            emit stopMicrophoneRecording();
            isMicrophoneSending = false;
        }
        ui->BroadcastButton->setText("Stop Broadcasting");
        isDataSending = true;
    }

    if (ui->listQueueFiles->count() <= 0) {
        AddStatusMessage("No songs in queue.");
        return;
    }

    if (!netManager->startNetwork())
    {
        return;
    }
    int port = ui->linePort->text().toInt();
    if (!netManager->createMulticastServerSocket(port))
    {
        return;
    }

    playNextSong();

}

void MultiServer::on_SendMicrophone_released()
{
    if (isMicrophoneSending) {
        //were no longer sending microphone data
        emit stopMicrophoneRecording();
        ui->SendMicrophone->setText("Start Recording Microphone");
    } else {
        //we are now sending microphone data
        mic = new MicrophoneManager(this);
        mic->RecordAudio();
        connect(this, SIGNAL(stopMicrophoneRecording()), mic, SLOT(stopRecording()));
        if (isDataSending)
            emit on_BroadcastButton_released();
        ui->SendMicrophone->setText("Stop Recording Microphone");
    }
    isMicrophoneSending = !isMicrophoneSending;
}
