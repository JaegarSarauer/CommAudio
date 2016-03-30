#include "peertopeer.h"
#include "ui_peertopeer.h"

PeerToPeer::PeerToPeer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PeerToPeer)
{
    ui->setupUi(this);
}

PeerToPeer::~PeerToPeer()
{
    delete ui;
}

/*
 * This function is called when the user moves the sound slider, it'll adjust the local program sound.
 */
void PeerToPeer::on_sliderSound_actionTriggered(int action)
{
    audioManager->setVolume((double)ui->sliderSound->sliderPosition() / 100);
}

/*
 * Triggered on connect button clicked. It will check to see if the fields.
 */
void PeerToPeer::on_buttonConnect_released()
{
    if (ui->lineIPAddress->text().length() <= 0) {
        QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter an IP!"));
            return;
        }

        if (ui->linePort->text().length() <= 0) {
            QMessageBox::information(this, tr("Peer to Peer Audio"), tr("Enter a port number!"));
            return;
        }

        std::string IP(ui->lineIPAddress->text().toUtf8().constData());
        int port = atoi(ui->linePort->text().toUtf8().constData());

        // ---- TODO ---- handle connecting to the peer here, use the above 2 strings as parameters for connection

        AddStatusMessage("Attempting to Connect...");
}


/*
 * When the user clicks the data sending button, this button will trigger on
 * and off for sending data.
 */
void PeerToPeer::on_DataSendingButton_released()
{
    // ---- TODO ---- Add starting and stopping of data here.
    if (isDataSending)
        ui->DataSendingButton->setText("Start Sending Data");
    else
        ui->DataSendingButton->setText("Stop Sending Data");
    isDataSending = !isDataSending;
}

/*
 * This function will add a status message to the status bar.
 */
void PeerToPeer::AddStatusMessage(const QString msg) {
    if (!stopThreadLoop)
        ui->StatusBar->addItem(QString(msg));
}
