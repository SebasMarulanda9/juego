#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QPixmap>
#include <QGraphicsScene>
#include <QPainter>
#include <QImage>
#include <QTimer>
#include <QtCore>
#include <QMouseEvent>
#include <QDateTime>
#include <iostream>
#include "bola.h"
#include "taco.h"

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
     MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void tacoInteraction();
    bool eventFilter(QObject *watched, QEvent *event);
    void reinicio();

private slots:
    void mover();
    void updatelabel();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timer2;
    bola *arreglo_bolas;
    Taco *taco;
    bool tiro;
    int tiempoAcumulado;
    float velBlanca_x;
    float velBlanca_y;
    int contador, contador2, contador3, contador4;
    int contadorDisplay=0;

};

#endif // MAINWINDOW_H
