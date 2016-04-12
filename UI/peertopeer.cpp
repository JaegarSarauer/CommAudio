#include "peertopeer.h"
#include "ui_peertopeer.h"
#include <QtDebug>

QThread * audioSendThread;

/*
 * Constructor for the multiserver window class.
 */
PeerToPeer::PeerToPeer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PeerToPeer)
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
    networkManager = new NetworkManager();
    //networkManager->startNetwork();
    netAudioPlayer = NULL;
    //startP2P();
    //networkManager.startTCPReceiver(8321);

    /*socketThread = new QThread();
    socketListener = new IncomingConnThread((void*) NetworkManager::acceptSocket);
    socketListener->moveToThread(socketThread);

    connect(socketThread, SIGNAL(started()), socketListener, SLOT(checkForConnection()));
    connect(socketListener, SIGNAL(tcpConnected()), this, SLOT(startP2P()));
    connect(socketListener, SIGNAL(tcpConnected()), socketThread, SLOT(quit()));
    //connect (this, SIGNAL(connectionMade()), socketThread, SLOT(quit()));

    connect( socketThread, SIGNAL(finished()), socketListener, SLOT(deleteLater()) );
    connect( socketThread, SIGNAL(finished()), socketThread, SLOT(deleteLater()) );
    socketThread->start();*/
}

void PeerToPeer::startP2P(const char * ip, int port)
{
    CircularBuffer * incomingBuffer = new CircularBuffer(8192, 100);

    //start UDP receiver and sender
    // 1 UDP socket for each????
    if (!networkManager->setupUDPforP2P(ip, port))
    {
        return;
    }
    networkManager->startUDPReceiver(incomingBuffer);

    //start thread checking circular buffer
    QThread * playThread = new QThread();
    bufferListener = new AudioPlayThread(incomingBuffer);
    bufferListener->moveToThread(playThread);

    connect (playThread, SIGNAL(started()), bufferListener, SLOT(checkBuffer()));
    //connect( bufferListener, SIGNAL(bufferHasData()), audioManager, SLOT(writeDataToDevice()));
   // connect( audioManager, SIGNAL(finishedWriting()), bufferListener, SLOT(checkBuffer()));
    playThread->start();
}

/*
 * Destructor for the peer to peer window class.
 */
PeerToPeer::~PeerToPeer()
{
    delete audioManager;
    delete ui;
}

/*
 * This function is called when the user moves the sound slider, it'll adjust the local program sound.
 */
void PeerToPeer::on_sliderSound_actionTriggered(int action)
{
    audioManager->setVolume((double)ui->sliderSound->sliderPosition() / 100);
}

/*
 * Triggered on connect button clicked. It will check to see if the fields.
 */
void PeerToPeer::on_buttonConnect_released()
{
    if (ui->lineIPAddress->text().length() <= 0)
    {
        QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter an IP!"));
            return;
    }

    if (ui->linePort->text().length() <= 0) {
        QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter a port number!"));
        return;
    }

    std::string ip(ui->lineIPAddress->text().toUtf8().constData());
    int port = atoi(ui->linePort->text().toUtf8().constData());

    // ---- TODO ---- handle connecting to the peer here, use the above 2 strings as parameters for connection
    AddStatusMessage("Attempting to Connect...");

    //networkManager.connectViaTCP(ip.c_str(), 8321);
    networkManager->startNetwork();
    startP2P(ip.c_str(), port);
}

/*
 * When the user clicks the stop button, stop the audio, and stop the queue
 * thread from attempting to play the next song.
 */
void PeerToPeer::on_buttonStopAudio_released()
{
    stopThreadLoop = true;
    audioManager->stopAudio();
    currentQueueIndex--;
}

/*
 * When the user clicks the pause button, pause the audio playing.
 */
void PeerToPeer::on_buttonPauseAudio_released()
{
    if (audioManager->isPlaying())
        audioManager->pauseAudio();
}

/*
 * When the user clicks the queue add button, it'll add the selected items to the queue list to play.
 */
void PeerToPeer::on_QueueAddButton_released()
{
    QList<QListWidgetItem *> selectedFile = ui->listMusicFiles->selectedItems();
    QListWidgetItem * index = selectedFile.front();
    ui->listQueueFiles->addItem(index->text());
}

/*
 * This function will remove the selected songs from the queue list when
 * the user clicks the remove queue button.
 */
void PeerToPeer::on_QueueRemoveButton_released()
{
    QList<QListWidgetItem *> indexes = ui->listQueueFiles->selectedItems();
    qDeleteAll(indexes.begin(), indexes.end());
}

/*
 * This function catches a click on the play audio button. If the button is clicked,
 * it will play the audio from where it left off if its paused, if not, it will play
 * the next song in the list.
 */
void PeerToPeer::on_buttonPlay_released()
{
    if (audioManager->isPaused()) {
        audioManager->playAudio();
    } else {
        playNextSong();
    }
}

/*
 * This function will add a status message to the status bar.
 */
void PeerToPeer::AddStatusMessage(const QString msg) {
    if (!stopThreadLoop)
        ui->StatusBar->addItem(QString(msg));
}

/*
 * This function will be called by the network layer to notify the application layer
 * with a confirmation message on a successful connection.
 * param bool connected = if true, successful connection, else, connection failed.
 */
// ---- TODO ---- call this function on successful connection
void PeerToPeer::successfulConnection(bool connected) {
    if (connected)
        AddStatusMessage("Connection Successful!");
    else
        AddStatusMessage("Unable to connect to peer.");
}

/*
 * This function will disconnect the user when they click the disconnect button.
 */
void PeerToPeer::on_buttonDisconnect_released()
{
    // ---- TODO ---- disconnect this peer here.
    AddStatusMessage("Disconnected from peer.");
}

void PeerToPeer::on_SendMicrophone_released()
{
    if (isMicrophoneSending) {
        //were no longer sending microphone data
        emit stopMicrophoneRecording();
        if (!isDataSending)
            emit on_DataSendingButton_released();
        ui->SendMicrophone->setText("Start Recording Microphone");
    } else {
        //were are now sending microphone data
        mic = new MicrophoneManager(this);
        mic->RecordAudio();
        connect(this, SIGNAL(stopMicrophoneRecording()), mic, SLOT(stopRecording()));
        if (isDataSending)
            emit on_DataSendingButton_released();
        ui->SendMicrophone->setText("Stop Recording Microphone");
    }
    isMicrophoneSending = !isMicrophoneSending;
}

/*
 * When the user clicks the data sending button, this button will trigger on
 * and off for sending data.
 */
void PeerToPeer::on_DataSendingButton_released()
{
    if (ui->listQueueFiles->count() <= 0) {
        AddStatusMessage("No songs in queue.");
        return;
    }

    // ---- TODO ---- Add starting and stopping of data here.
    if (isDataSending)
        ui->DataSendingButton->setText("Stop Sending Data");
    else
        ui->DataSendingButton->setText("Start Sending Data");
    isDataSending = !isDataSending;

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

    if (audioSendThread && audioSendThread->isRunning())
    {
        audioSendThread->terminate();
        delete audioSendThread;
        audioSendThread = NULL;
    }
    audioSendThread = new QThread();

    if (netAudioPlayer == NULL)
    {
        netAudioPlayer = new NetworkAudioPlayer();

    }
    netAudioPlayer->setup(new QFile(current->text()));
    netAudioPlayer->moveToThread(audioSendThread);
    //QAudioOutput * audioOut = netAudioPlayer->playAudio(netManager);

    connect(audioSendThread, SIGNAL(started()), netAudioPlayer, SLOT(playAudio()));
    connect(netAudioPlayer, SIGNAL(audioStarted(QAudioOutput*)), this, SLOT(checkQueue(QAudioOutput*)));
    connect(netAudioPlayer, SIGNAL(sendToClient(char*,int)), this, SLOT(sendData(char*, int)));
    audioSendThread->start();
}

void PeerToPeer::sendData(char * buffer, int length)
{
    networkManager->sendMulticast(buffer, length);
}

void PeerToPeer::checkQueue(QAudioOutput * audioOut)
{
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
 * This function will play the next song in the list. It is auto triggered if it finds the
 * currently playing song has finished.
 */
void PeerToPeer::playNextSong() {
    if (stopThreadLoop) {
        disconnect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(AddStatusMessage(QString)) );
        disconnect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(playNextSong()) );
        stopThreadLoop = false;
        return;
    }

    if (ui->listQueueFiles->count() <= 0) {
        AddStatusMessage("No songs in queue.");
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
    QAudioOutput * audio = audioManager->playAudio();

    QThread * queueThread = new QThread();
    deviceListener = new AudioThread(audio);
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

void PeerToPeer::on_OpenPathButton_released()
{
    ui->listMusicFiles->addItems(QFileDialog::getOpenFileNames(this, tr("Open Wav files."),
                                                    QDir::currentPath() + "/MusicFiles",
                                                    tr("Wav Files (*.wav)")));
}
