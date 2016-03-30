#include "multiclient.h"
#include "ui_multiclient.h"

MultiClient::MultiClient(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MultiClient)
{
    ui->setupUi(this);
}

MultiClient::~MultiClient()
{
    delete ui;
}
