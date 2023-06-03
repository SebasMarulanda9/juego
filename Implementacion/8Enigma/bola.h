#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <QObject>

#define radio 12
#define masa 100

#define tiempo 0.001
#define elasti 0.9 //Coeficiente de elasticidad
#define desaceleracion 0.992
#define tolerancia 20

#define ladoIzquierdo 46
#define ladoInferior -356
#define ladoSuperior -46
#define ladoDerecho 648

class bola: public QGraphicsItem
{
public:

    bola();
    static int puntaje;
    static int m;
    int bola_en_juego;
    int muerta;
    void setPosX(float);
    void setPosY(float);
    void setVelX(float);
    void setVelY(float);
    void setAccelX(float);
    void setAccelY(float);
    void setColor(int);
    static void setM(int);
    static void setpuntaje(int);


    float getPosX();
    float getPosY();
    float getVelX();
    float getVelY();
    float getAccelX();
    float getAccelY();
    int getColor();
    static int getM(); //Adquirir la variable de acumulación de bolas en la canaleta
    static int getpuntaje();

    QRectF boundingRect() const;
    void paint(QPainter *painter ,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover(int x0, int y0, int w, int h);
    float choque(bola *b2);

private:
    float posX;
    float posY;
    float velX;
    float velY;
    float accelX;
    float accelY;
    int color;

};

#endif // BOLA_H
