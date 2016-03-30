#ifndef MULTICLIENT_H
#define MULTICLIENT_H

#include <QMainWindow>

namespace Ui {
class MultiClient;
}

class MultiClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit MultiClient(QWidget *parent = 0);
    ~MultiClient();

private:
    Ui::MultiClient *ui;
};

#endif // MULTICLIENT_H
