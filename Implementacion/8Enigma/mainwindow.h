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
    int imp;

protected:
    bool eventFilter(QObject *watched, QEvent *event);

private slots:
    void mover();
    void on_verticalSlider_2_sliderMoved(int data);

    //void on_verticalSlider_2_sliderReleased();

    //void on_verticalSlider_sliderMoved(int position);//Slider que define el cambio del angulo en el taco alrededor

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timer2;
    bola *arreglo_bolas;
    bool readyTaco;
    Taco *taco;
    bool tiro;

};

#endif // MAINWINDOW_H
