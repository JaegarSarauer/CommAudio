#include "startwindow.h"
#include "ui_startwindow.h"
#include "multiserver.h"

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::on_pushButton_clicked()
{
   if (ui->radioMultiClient->isChecked()) {
       //run multicast client
   } else if (ui->radioMultiServer->isChecked()) {
       //run multicast server
       MultiServer *ms = new MultiServer(this);
       ms->setAttribute(Qt::WA_DeleteOnClose);
       ms->show();
   } else if (ui->radioPeer->isChecked()) {
       //run peer to peer
   }
   destroy(true, false);
}
