#ifndef MULTISERVER_H
#define MULTISERVER_H

#include <QMainWindow>
#include <QtMultimedia/QAudioOutput>
#include <QFile>
#include <QDir>
#include <QThread>
#include <QMessageBox>
#include "audiomanager.h"
#include "audiothread.h"

namespace Ui {
class MultiServer;
}

class MultiServer : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiServer(QWidget *parent = 0);
    ~MultiServer();

private slots:
    void on_buttonStopAudio_released();

    void on_buttonPauseAudio_released();

    void on_QueueAddButton_released();

    void on_QueueRemoveButton_released();

    void playNextSong();

    void AddStatusMessage(QString msg);

    void on_buttonDisconnect_released();

    void on_buttonPlay_released();

    void successfulConnection(bool connected);

private:
    bool isDataSending = true;
    Ui::MultiServer *ui;
    AudioManager *audioManager;
    int currentQueueIndex;
    AudioThread *deviceListener;
    bool stopThreadLoop = false;
};

#endif // MULTISERVER_H

