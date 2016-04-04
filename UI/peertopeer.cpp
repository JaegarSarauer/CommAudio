#include "peertopeer.h"
#include "ui_peertopeer.h"

PeerToPeer::PeerToPeer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PeerToPeer)
{
    ui->setupUi(this);
    audioManager = new AudioManager(this);
    QDir dir;
    ui->listMusicFiles->addItems(dir.entryList(QStringList("*.wav")));
    currentQueueIndex = -1;
}

PeerToPeer::~PeerToPeer()
{
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
    if (ui->lineIPAddress->text().length() <= 0) {
        QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter an IP!"));
            return;
        }

        if (ui->linePort->text().length() <= 0) {
            QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter a port number!"));
            return;
        }

        std::string IP(ui->lineIPAddress->text().toUtf8().constData());
        int port = atoi(ui->linePort->text().toUtf8().constData());

        // ---- TODO ---- handle connecting to the peer here, use the above 2 strings as parameters for connection

        AddStatusMessage("Attempting to Connect...");
}


/*
 * When the user clicks the data sending button, this button will trigger on
 * and off for sending data.
 */
void PeerToPeer::on_DataSendingButton_released()
{
    // ---- TODO ---- Add starting and stopping of data here.
    if (isDataSending)
        ui->DataSendingButton->setText("Start Sending Data");
    else
        ui->DataSendingButton->setText("Stop Sending Data");
    isDataSending = !isDataSending;
}

/*
 * This function will add a status message to the status bar.
 */
void PeerToPeer::AddStatusMessage(const QString msg) {
    if (!stopThreadLoop)
        ui->StatusBar->addItem(QString(msg));
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

void PeerToPeer::on_QueueAddButton_released()
{
    QList<QListWidgetItem *> selectedFile = ui->listMusicFiles->selectedItems();
    QListWidgetItem * index = selectedFile.front();
    ui->listQueueFiles->addItem(index->text());
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
    QIODevice * device = audioManager->playAudio();

    QThread *audioThread = new QThread( );
    deviceListener = new AudioThread(device);
    deviceListener->moveToThread(audioThread);

    connect( audioThread, SIGNAL(started()), deviceListener, SLOT(checkForEnding()) );
    //connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(AddStatusMessage(QString)) );
    //connect( deviceListener, SIGNAL(workFinished(const QString)), this, SLOT(playNextSong()) );
    //automatically delete thread and deviceListener object when work is done:
    connect( audioThread, SIGNAL(finished()), deviceListener, SLOT(deleteLater()) );
    connect( audioThread, SIGNAL(finished()), audioThread, SLOT(deleteLater()) );
    audioThread->start();
}

