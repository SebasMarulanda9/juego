/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titulo;
    QLabel *bola4;
    QLabel *bola1;
    QLabel *bola3;
    QLabel *bola5;
    QLabel *bola6;
    QLabel *bola7;
    QLabel *bola8;
    QLabel *bola9;
    QLabel *bola10;
    QLabel *bola11;
    QLabel *bola12;
    QLabel *bola13;
    QLabel *bola14;
    QLabel *bola15;
    QLabel *bola2;
    QLabel *bola0;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1190, 653);
        MainWindow->setStyleSheet(QString::fromUtf8("#centralwidget{\n"
"background-color: rgb(170, 170, 127);\n"
"}\n"
"\n"
"#titulo {\n"
"color : white;\n"
"}\n"
"\n"
"#cronometro {\n"
"colot : white;\n"
"}\n"
"\n"
"#graphicsView{\n"
"background-color: rgb(170, 170, 127);\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        titulo = new QLabel(centralwidget);
        titulo->setObjectName(QString::fromUtf8("titulo"));
        titulo->setGeometry(QRect(480, 0, 197, 64));
        QFont font;
        font.setPointSize(36);
        font.setBold(true);
        titulo->setFont(font);
        bola4 = new QLabel(centralwidget);
        bola4->setObjectName(QString::fromUtf8("bola4"));
        bola4->setGeometry(QRect(260, 20, 31, 31));
        bola4->setPixmap(QPixmap(QString::fromUtf8(":/4.png")));
        bola4->setScaledContents(true);
        bola1 = new QLabel(centralwidget);
        bola1->setObjectName(QString::fromUtf8("bola1"));
        bola1->setGeometry(QRect(140, 20, 31, 31));
        bola1->setPixmap(QPixmap(QString::fromUtf8(":/1.png")));
        bola1->setScaledContents(true);
        bola3 = new QLabel(centralwidget);
        bola3->setObjectName(QString::fromUtf8("bola3"));
        bola3->setGeometry(QRect(220, 20, 31, 31));
        bola3->setPixmap(QPixmap(QString::fromUtf8(":/3.png")));
        bola3->setScaledContents(true);
        bola5 = new QLabel(centralwidget);
        bola5->setObjectName(QString::fromUtf8("bola5"));
        bola5->setGeometry(QRect(300, 20, 31, 31));
        bola5->setPixmap(QPixmap(QString::fromUtf8(":/5.png")));
        bola5->setScaledContents(true);
        bola6 = new QLabel(centralwidget);
        bola6->setObjectName(QString::fromUtf8("bola6"));
        bola6->setGeometry(QRect(340, 20, 31, 31));
        bola6->setPixmap(QPixmap(QString::fromUtf8(":/6.png")));
        bola6->setScaledContents(true);
        bola7 = new QLabel(centralwidget);
        bola7->setObjectName(QString::fromUtf8("bola7"));
        bola7->setGeometry(QRect(380, 20, 31, 31));
        bola7->setPixmap(QPixmap(QString::fromUtf8(":/7.png")));
        bola7->setScaledContents(true);
        bola8 = new QLabel(centralwidget);
        bola8->setObjectName(QString::fromUtf8("bola8"));
        bola8->setGeometry(QRect(420, 20, 31, 31));
        bola8->setPixmap(QPixmap(QString::fromUtf8(":/8.png")));
        bola8->setScaledContents(true);
        bola9 = new QLabel(centralwidget);
        bola9->setObjectName(QString::fromUtf8("bola9"));
        bola9->setGeometry(QRect(720, 20, 31, 31));
        bola9->setPixmap(QPixmap(QString::fromUtf8(":/9.png")));
        bola9->setScaledContents(true);
        bola10 = new QLabel(centralwidget);
        bola10->setObjectName(QString::fromUtf8("bola10"));
        bola10->setGeometry(QRect(760, 20, 31, 31));
        bola10->setPixmap(QPixmap(QString::fromUtf8(":/10.png")));
        bola10->setScaledContents(true);
        bola11 = new QLabel(centralwidget);
        bola11->setObjectName(QString::fromUtf8("bola11"));
        bola11->setGeometry(QRect(800, 20, 31, 31));
        bola11->setPixmap(QPixmap(QString::fromUtf8(":/11.png")));
        bola11->setScaledContents(true);
        bola12 = new QLabel(centralwidget);
        bola12->setObjectName(QString::fromUtf8("bola12"));
        bola12->setGeometry(QRect(840, 20, 31, 31));
        bola12->setPixmap(QPixmap(QString::fromUtf8(":/12.png")));
        bola12->setScaledContents(true);
        bola13 = new QLabel(centralwidget);
        bola13->setObjectName(QString::fromUtf8("bola13"));
        bola13->setGeometry(QRect(880, 20, 31, 31));
        bola13->setPixmap(QPixmap(QString::fromUtf8(":/13.png")));
        bola13->setScaledContents(true);
        bola14 = new QLabel(centralwidget);
        bola14->setObjectName(QString::fromUtf8("bola14"));
        bola14->setGeometry(QRect(920, 20, 31, 31));
        bola14->setPixmap(QPixmap(QString::fromUtf8(":/14.png")));
        bola14->setScaledContents(true);
        bola15 = new QLabel(centralwidget);
        bola15->setObjectName(QString::fromUtf8("bola15"));
        bola15->setGeometry(QRect(960, 20, 31, 31));
        bola15->setPixmap(QPixmap(QString::fromUtf8(":/15.png")));
        bola15->setScaledContents(true);
        bola2 = new QLabel(centralwidget);
        bola2->setObjectName(QString::fromUtf8("bola2"));
        bola2->setGeometry(QRect(180, 20, 31, 31));
        bola2->setPixmap(QPixmap(QString::fromUtf8(":/2.png")));
        bola2->setScaledContents(true);
        bola0 = new QLabel(centralwidget);
        bola0->setObjectName(QString::fromUtf8("bola0"));
        bola0->setGeometry(QRect(1000, 20, 31, 31));
        bola0->setPixmap(QPixmap(QString::fromUtf8(":/0.png")));
        bola0->setScaledContents(true);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 1191, 611));
        graphicsView->setStyleSheet(QString::fromUtf8(""));
        MainWindow->setCentralWidget(centralwidget);
        graphicsView->raise();
        titulo->raise();
        bola4->raise();
        bola1->raise();
        bola3->raise();
        bola5->raise();
        bola6->raise();
        bola7->raise();
        bola8->raise();
        bola9->raise();
        bola10->raise();
        bola11->raise();
        bola12->raise();
        bola13->raise();
        bola14->raise();
        bola15->raise();
        bola2->raise();
        bola0->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1190, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        titulo->setText(QCoreApplication::translate("MainWindow", "8Enigma", nullptr));
        bola4->setText(QString());
        bola1->setText(QString());
        bola3->setText(QString());
        bola5->setText(QString());
        bola6->setText(QString());
        bola7->setText(QString());
        bola8->setText(QString());
        bola9->setText(QString());
        bola10->setText(QString());
        bola11->setText(QString());
        bola12->setText(QString());
        bola13->setText(QString());
        bola14->setText(QString());
        bola15->setText(QString());
        bola2->setText(QString());
        bola0->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
