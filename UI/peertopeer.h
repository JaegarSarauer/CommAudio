#ifndef PEERTOPEER_H
#define PEERTOPEER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDir>
#include "peertopeer.h"
#include <QFile>
#include <QDir>
#include <QThread>
#include <QMessageBox>
#include <QFileDialog>
#include "audiomanager.h"
#include "audiothread.h"
#include "microphonemanager.h"
#include "networkmanager.h"
#include "incomingconnthread.h"

namespace Ui {
class PeerToPeer;
}

class PeerToPeer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PeerToPeer(QWidget *parent = 0);
    ~PeerToPeer();

private slots:
    void on_sliderSound_actionTriggered(int action);

    void on_buttonConnect_released();

    void on_DataSendingButton_released();

    void on_buttonStopAudio_released();

    void on_buttonPauseAudio_released();

    void on_QueueAddButton_released();

    void playNextSong();

    void AddStatusMessage(const QString msg);

    void on_QueueRemoveButton_released();

    void successfulConnection(bool connected);

    void on_buttonDisconnect_released();

    void on_buttonPlay_released();

    void on_SendMicrophone_released();

    void on_OpenPathButton_released();
    void startP2P();

signals:
    void stopMicrophoneRecording();

private:
    MicrophoneManager *mic;
    Ui::PeerToPeer *ui;
    bool isDataSending = true;
    AudioManager *audioManager;
    int currentQueueIndex;
    AudioThread *deviceListener;
    bool stopThreadLoop = false;
    bool isMicrophoneSending = false;
    QThread *audioThread;
    QThread *socketThread;
    NetworkManager networkManager;
    IncomingConnThread * socketListener;
    AudioPlayThread * bufferListener;
};

#endif // PEERTOPEER_H
