#ifndef MULTISERVER_H
#define MULTISERVER_H

#include <QMainWindow>
#include <QtMultimedia/QAudioOutput>
#include <QFile>
#include <QDir>
#include <QThread>
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
    void on_pushButton_4_released();

    void on_buttonStopAudio_released();

    void on_buttonPauseAudio_released();

    void on_sliderSound_actionTriggered(int action);

    void on_QueueAddButton_released();

    void on_QueueRemoveButton_released();

    void playNextSong();
    void updateStatusBar(QString msg);

private:
    Ui::MultiServer *ui;
    AudioManager *audioManager;
    int currentQueueIndex;
};

#endif // MULTISERVER_H

