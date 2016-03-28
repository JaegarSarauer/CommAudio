/********************************************************************************
** Form generated from reading UI file 'multiserver.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MULTISERVER_H
#define UI_MULTISERVER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MultiServer
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_10;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout_8;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_8;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *lineEdit_2;
    QGroupBox *groupBox_9;
    QVBoxLayout *verticalLayout_11;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_5;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton;
    QPushButton *buttonStopAudio;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_4;
    QPushButton *buttonPauseAudio;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_6;
    QSlider *sliderSound;
    QFrame *frame;
    QVBoxLayout *verticalLayout_13;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QListWidget *listMusicFiles;
    QHBoxLayout *horizontalLayout;
    QPushButton *QueueAddButton;
    QPushButton *QueueRemoveButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listQueueFiles;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *StopSendingButton;
    QPushButton *SendAudioButton;
    QLabel *playingStatusBar;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MultiServer)
    {
        if (MultiServer->objectName().isEmpty())
            MultiServer->setObjectName(QStringLiteral("MultiServer"));
        MultiServer->resize(951, 529);
        centralWidget = new QWidget(MultiServer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_3 = new QHBoxLayout(centralWidget);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout_5 = new QHBoxLayout(widget);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_2 = new QFrame(widget);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_14 = new QVBoxLayout(frame_2);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setSpacing(10);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        groupBox_6 = new QGroupBox(frame_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        groupBox_6->setMaximumSize(QSize(16777215, 200));
        groupBox_6->setLayoutDirection(Qt::LeftToRight);
        groupBox_6->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayout_10 = new QVBoxLayout(groupBox_6);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(-1, 0, -1, -1);
        groupBox_7 = new QGroupBox(groupBox_6);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setMaximumSize(QSize(16777215, 60));
        verticalLayout_8 = new QVBoxLayout(groupBox_7);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(-1, 5, -1, -1);
        lineEdit = new QLineEdit(groupBox_7);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        verticalLayout_8->addWidget(lineEdit);


        verticalLayout_10->addWidget(groupBox_7);

        groupBox_8 = new QGroupBox(groupBox_6);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setMaximumSize(QSize(16777215, 60));
        verticalLayout_9 = new QVBoxLayout(groupBox_8);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(-1, 5, -1, -1);
        lineEdit_2 = new QLineEdit(groupBox_8);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        verticalLayout_9->addWidget(lineEdit_2);


        verticalLayout_10->addWidget(groupBox_8);

        groupBox_9 = new QGroupBox(groupBox_6);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        verticalLayout_11 = new QVBoxLayout(groupBox_9);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(-1, 5, -1, -1);
        lineEdit_3 = new QLineEdit(groupBox_9);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        verticalLayout_11->addWidget(lineEdit_3);


        verticalLayout_10->addWidget(groupBox_9);


        verticalLayout_7->addWidget(groupBox_6);


        verticalLayout_12->addLayout(verticalLayout_7);

        groupBox_4 = new QGroupBox(frame_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_5 = new QVBoxLayout(groupBox_4);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        buttonStopAudio = new QPushButton(groupBox_4);
        buttonStopAudio->setObjectName(QStringLiteral("buttonStopAudio"));

        horizontalLayout_4->addWidget(buttonStopAudio);

        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_4->addWidget(pushButton_5);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton_4 = new QPushButton(groupBox_4);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        buttonPauseAudio = new QPushButton(groupBox_4);
        buttonPauseAudio->setObjectName(QStringLiteral("buttonPauseAudio"));

        horizontalLayout_2->addWidget(buttonPauseAudio);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout_2);

        groupBox_5 = new QGroupBox(groupBox_4);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMaximumSize(QSize(16777215, 50));
        verticalLayout_6 = new QVBoxLayout(groupBox_5);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        sliderSound = new QSlider(groupBox_5);
        sliderSound->setObjectName(QStringLiteral("sliderSound"));
        sliderSound->setMaximum(100);
        sliderSound->setPageStep(1);
        sliderSound->setValue(100);
        sliderSound->setOrientation(Qt::Horizontal);

        verticalLayout_6->addWidget(sliderSound);


        verticalLayout_5->addWidget(groupBox_5);


        verticalLayout_12->addWidget(groupBox_4);


        verticalLayout_14->addLayout(verticalLayout_12);


        horizontalLayout_5->addWidget(frame_2);

        frame = new QFrame(widget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_13 = new QVBoxLayout(frame);
        verticalLayout_13->setSpacing(6);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(-1, 0, -1, -1);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_3 = new QGroupBox(frame);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(-1, 0, -1, -1);
        groupBox_2 = new QGroupBox(groupBox_3);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        listMusicFiles = new QListWidget(groupBox_2);
        listMusicFiles->setObjectName(QStringLiteral("listMusicFiles"));

        verticalLayout_2->addWidget(listMusicFiles);


        verticalLayout_4->addWidget(groupBox_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        QueueAddButton = new QPushButton(groupBox_3);
        QueueAddButton->setObjectName(QStringLiteral("QueueAddButton"));

        horizontalLayout->addWidget(QueueAddButton);

        QueueRemoveButton = new QPushButton(groupBox_3);
        QueueRemoveButton->setObjectName(QStringLiteral("QueueRemoveButton"));

        horizontalLayout->addWidget(QueueRemoveButton);


        verticalLayout_4->addLayout(horizontalLayout);

        groupBox = new QGroupBox(groupBox_3);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listQueueFiles = new QListWidget(groupBox);
        listQueueFiles->setObjectName(QStringLiteral("listQueueFiles"));

        verticalLayout->addWidget(listQueueFiles);


        verticalLayout_4->addWidget(groupBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        StopSendingButton = new QPushButton(groupBox_3);
        StopSendingButton->setObjectName(QStringLiteral("StopSendingButton"));

        horizontalLayout_6->addWidget(StopSendingButton);

        SendAudioButton = new QPushButton(groupBox_3);
        SendAudioButton->setObjectName(QStringLiteral("SendAudioButton"));

        horizontalLayout_6->addWidget(SendAudioButton);


        verticalLayout_4->addLayout(horizontalLayout_6);

        playingStatusBar = new QLabel(groupBox_3);
        playingStatusBar->setObjectName(QStringLiteral("playingStatusBar"));

        verticalLayout_4->addWidget(playingStatusBar);


        verticalLayout_3->addWidget(groupBox_3);


        verticalLayout_13->addLayout(verticalLayout_3);


        horizontalLayout_5->addWidget(frame);

        horizontalLayout_5->setStretch(1, 100);

        horizontalLayout_3->addWidget(widget);

        MultiServer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MultiServer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 951, 21));
        MultiServer->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MultiServer);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MultiServer->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MultiServer);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MultiServer->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MultiServer);

        QMetaObject::connectSlotsByName(MultiServer);
    } // setupUi

    void retranslateUi(QMainWindow *MultiServer)
    {
        MultiServer->setWindowTitle(QApplication::translate("MultiServer", "Peer To Peer", 0));
        groupBox_6->setTitle(QApplication::translate("MultiServer", "Connection Controls", 0));
        groupBox_7->setTitle(QApplication::translate("MultiServer", "IP Address", 0));
        groupBox_8->setTitle(QApplication::translate("MultiServer", "Port", 0));
        groupBox_9->setTitle(QApplication::translate("MultiServer", "Path To Save Audio", 0));
        groupBox_4->setTitle(QApplication::translate("MultiServer", "Sound Controls", 0));
        pushButton->setText(QApplication::translate("MultiServer", "Rewind", 0));
        buttonStopAudio->setText(QApplication::translate("MultiServer", "Stop", 0));
        pushButton_5->setText(QApplication::translate("MultiServer", "Fast Forward", 0));
        pushButton_4->setText(QApplication::translate("MultiServer", "Play", 0));
        buttonPauseAudio->setText(QApplication::translate("MultiServer", "Pause", 0));
        groupBox_5->setTitle(QApplication::translate("MultiServer", "Sound", 0));
        groupBox_3->setTitle(QApplication::translate("MultiServer", "Send Controls", 0));
        groupBox_2->setTitle(QApplication::translate("MultiServer", "Music Files", 0));
        QueueAddButton->setText(QApplication::translate("MultiServer", "Insert In Queue", 0));
        QueueRemoveButton->setText(QApplication::translate("MultiServer", "Remove From Queue", 0));
        groupBox->setTitle(QApplication::translate("MultiServer", "Music Queue", 0));
        StopSendingButton->setText(QApplication::translate("MultiServer", "Stop Sending", 0));
        SendAudioButton->setText(QApplication::translate("MultiServer", "Send Microphone Audio", 0));
        playingStatusBar->setText(QApplication::translate("MultiServer", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class MultiServer: public Ui_MultiServer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MULTISERVER_H
