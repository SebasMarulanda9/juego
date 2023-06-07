/********************************************************************************
** Form generated from reading UI file 'ganaste.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GANASTE_H
#define UI_GANASTE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ganaste
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *ganaste)
    {
        if (ganaste->objectName().isEmpty())
            ganaste->setObjectName(QString::fromUtf8("ganaste"));
        ganaste->resize(280, 125);
        centralwidget = new QWidget(ganaste);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 0, 271, 61));
        QFont font;
        font.setPointSize(48);
        label->setFont(font);
        label->setScaledContents(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 80, 162, 26));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(layoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        ganaste->setCentralWidget(centralwidget);

        retranslateUi(ganaste);

        QMetaObject::connectSlotsByName(ganaste);
    } // setupUi

    void retranslateUi(QMainWindow *ganaste)
    {
        ganaste->setWindowTitle(QCoreApplication::translate("ganaste", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("ganaste", "!Ganaste!", nullptr));
        pushButton->setText(QCoreApplication::translate("ganaste", "Volver a jugar", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ganaste", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ganaste: public Ui_ganaste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANASTE_H
