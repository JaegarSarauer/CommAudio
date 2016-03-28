/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QFrame *frame;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QPushButton *pushButton;
    QFrame *frame_2;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioMultiClient;
    QRadioButton *radioMultiServer;
    QRadioButton *radioPeer;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(230, 246);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(StartWindow->sizePolicy().hasHeightForWidth());
        StartWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(StartWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_3 = new QGridLayout(frame);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        label = new QLabel(frame);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 50));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 5, 0, 1, 1);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setMinimumSize(QSize(200, 0));
        frame_2->setMaximumSize(QSize(200, 100));
        frame_2->setLayoutDirection(Qt::LeftToRight);
        frame_2->setFrameShape(QFrame::WinPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_4 = new QGridLayout(frame_2);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, -1, 0, -1);
        radioMultiClient = new QRadioButton(frame_2);
        radioMultiClient->setObjectName(QStringLiteral("radioMultiClient"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(radioMultiClient->sizePolicy().hasHeightForWidth());
        radioMultiClient->setSizePolicy(sizePolicy2);
        radioMultiClient->setMaximumSize(QSize(150, 16777215));
        radioMultiClient->setChecked(true);

        verticalLayout->addWidget(radioMultiClient);

        radioMultiServer = new QRadioButton(frame_2);
        radioMultiServer->setObjectName(QStringLiteral("radioMultiServer"));
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(radioMultiServer->sizePolicy().hasHeightForWidth());
        radioMultiServer->setSizePolicy(sizePolicy3);
        radioMultiServer->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout->addWidget(radioMultiServer);

        radioPeer = new QRadioButton(frame_2);
        radioPeer->setObjectName(QStringLiteral("radioPeer"));

        verticalLayout->addWidget(radioPeer);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addWidget(frame_2, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 0, 0, 1, 1);


        gridLayout->addWidget(frame, 2, 0, 1, 1);

        StartWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StartWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 230, 26));
        StartWindow->setMenuBar(menuBar);

        retranslateUi(StartWindow);

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "StartWindow", 0));
        label->setText(QApplication::translate("StartWindow", "<html><head/><body><div align=\"center\">Welcome to Comm Audio!</div><div align=\"center\">Please Make a Program Selection</div></body></html>", 0));
        pushButton->setText(QApplication::translate("StartWindow", "Start!", 0));
        radioMultiClient->setText(QApplication::translate("StartWindow", "Multicast Client", 0));
        radioMultiServer->setText(QApplication::translate("StartWindow", "Multicast Server", 0));
        radioPeer->setText(QApplication::translate("StartWindow", "Peer To Peer", 0));
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
