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
#include "audiomanager.h"
#include "audiothread.h"
#include "microphonemanager.h"

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
};

#endif // PEERTOPEER_H
