/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "canvaswidget.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    CanvasWidget *canvasWidget;
    QPushButton *fastHullButton;
    QPushButton *slowHullButton;
    QPushButton *generatePointsButton;
    QLabel *infoLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1310, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        canvasWidget = new CanvasWidget(centralwidget);
        canvasWidget->setObjectName("canvasWidget");
        fastHullButton = new QPushButton(canvasWidget);
        fastHullButton->setObjectName("fastHullButton");
        fastHullButton->setGeometry(QRect(910, 450, 161, 61));
        slowHullButton = new QPushButton(canvasWidget);
        slowHullButton->setObjectName("slowHullButton");
        slowHullButton->setGeometry(QRect(730, 450, 171, 61));
        generatePointsButton = new QPushButton(canvasWidget);
        generatePointsButton->setObjectName("generatePointsButton");
        generatePointsButton->setGeometry(QRect(540, 450, 181, 61));
        infoLabel = new QLabel(canvasWidget);
        infoLabel->setObjectName("infoLabel");
        infoLabel->setGeometry(QRect(980, 0, 131, 31));

        verticalLayout->addWidget(canvasWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1310, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        fastHullButton->setText(QCoreApplication::translate("MainWindow", "Run Fast Hull", nullptr));
        slowHullButton->setText(QCoreApplication::translate("MainWindow", "Run Slow Hull", nullptr));
        generatePointsButton->setText(QCoreApplication::translate("MainWindow", "Generate Points", nullptr));
        infoLabel->setText(QCoreApplication::translate("MainWindow", "InfoLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
