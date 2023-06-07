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
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;

    void setupUi(QMainWindow *ganaste)
    {
        if (ganaste->objectName().isEmpty())
            ganaste->setObjectName(QString::fromUtf8("ganaste"));
        ganaste->resize(639, 359);
        centralwidget = new QWidget(ganaste);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(330, 250, 141, 24));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 250, 141, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 805, 360));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/ganaste.png")));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(240, 230, 807, 362));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ganaste->setCentralWidget(centralwidget);
        label_2->raise();
        pushButton->raise();
        pushButton_2->raise();

        retranslateUi(ganaste);

        QMetaObject::connectSlotsByName(ganaste);
    } // setupUi

    void retranslateUi(QMainWindow *ganaste)
    {
        ganaste->setWindowTitle(QCoreApplication::translate("ganaste", "\302\241Ganaste!", nullptr));
        pushButton_2->setText(QCoreApplication::translate("ganaste", "Salir", nullptr));
        pushButton->setText(QCoreApplication::translate("ganaste", "Volver a jugar", nullptr));
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ganaste: public Ui_ganaste {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GANASTE_H
