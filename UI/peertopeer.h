#ifndef PEERTOPEER_H
#define PEERTOPEER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDir>
#include "peertopeer.h"
#include "audiomanager.h"
#include "audiothread.h"

namespace Ui {
class PeerToPeer;
}

class PeerToPeer : public QMainWindow
{
    Q_OBJECT

public:
    explicit PeerToPeer(QWidget *parent = 0);
    ~PeerToPeer();

private:
    void AddStatusMessage(const QString msg);

private slots:
    void on_sliderSound_actionTriggered(int action);

    void on_buttonConnect_released();

    void on_DataSendingButton_released();

    void on_buttonStopAudio_released();

    void on_buttonPauseAudio_released();

    void on_QueueAddButton_released();

    //void on_QueueRemoveButton_released();

    void playNextSong();

    //void on_buttonDisconnect_released();

    void on_buttonPlay_released();

    //void successfulConnection(bool connected);

    //void on_SendAudioButton_released();

    //void on_StopSendingButton_released();

private:
    Ui::PeerToPeer *ui;
    bool isDataSending = true;
    AudioManager *audioManager;
    int currentQueueIndex;
    AudioThread *deviceListener;
    bool stopThreadLoop = false;
};

#endif // PEERTOPEER_H
