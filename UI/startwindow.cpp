#include "startwindow.h"
#include "ui_startwindow.h"
#include "multiserver.h"
#include "multiclient.h"
#include "peertopeer.h"

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
       MultiClient *ms = new MultiClient(this);
       ms->setAttribute(Qt::WA_DeleteOnClose);
       ms->show();
   } else if (ui->radioMultiServer->isChecked()) {
       MultiServer *ms = new MultiServer(this);
       ms->setAttribute(Qt::WA_DeleteOnClose);
       ms->show();
   } else if (ui->radioPeer->isChecked()) {
       PeerToPeer *ms = new PeerToPeer(this);
       ms->setAttribute(Qt::WA_DeleteOnClose);
       ms->show();
   }
   destroy(true, false);
}
