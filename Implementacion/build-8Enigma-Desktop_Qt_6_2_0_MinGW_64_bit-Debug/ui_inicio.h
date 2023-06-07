/********************************************************************************
** Form generated from reading UI file 'inicio.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INICIO_H
#define UI_INICIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_inicio
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QMainWindow *inicio)
    {
        if (inicio->objectName().isEmpty())
            inicio->setObjectName(QString::fromUtf8("inicio"));
        inicio->resize(600, 300);
        centralwidget = new QWidget(inicio);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(230, 230, 141, 51));
        QFont font;
        font.setPointSize(16);
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-30, 0, 681, 371));
        label->setPixmap(QPixmap(QString::fromUtf8(":/imagenes/inicio.jpg")));
        label->setScaledContents(true);
        inicio->setCentralWidget(centralwidget);
        label->raise();
        pushButton->raise();

        retranslateUi(inicio);

        QMetaObject::connectSlotsByName(inicio);
    } // setupUi

    void retranslateUi(QMainWindow *inicio)
    {
        inicio->setWindowTitle(QCoreApplication::translate("inicio", "Inicio", nullptr));
        pushButton->setText(QCoreApplication::translate("inicio", "Jugar", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class inicio: public Ui_inicio {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INICIO_H
