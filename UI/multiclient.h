#ifndef MULTICLIENT_H
#define MULTICLIENT_H

#include <QMainWindow>
#include <QAudio>

namespace Ui {
class MultiClient;
}

class MultiClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiClient(QWidget *parent = 0);
    ~MultiClient();

private slots:
    void on_buttonPlay_released();
    //void handleStateChanged(QAudio::State ok);

private:
    Ui::MultiClient *ui;
};

#endif // MULTICLIENT_H
