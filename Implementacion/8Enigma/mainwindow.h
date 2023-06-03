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

private slots:
    void mover();
    void on_Tirar_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QTimer *timer2;
    bola *arreglo_bolas;
    Taco *taco;
    bool tiro;

};

#endif // MAINWINDOW_H
