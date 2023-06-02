#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>
#include <QObject>


#define radio 12// Macro del radio para todas las bolas igual
#define masa 100// Masa de las bolas para todas igual

#define tiempo 0.001 //Macro para el tiempo
#define elasti 0.9 //Coeficiente de elasticidad
#define desaceleracion 0.992 // Desacelaracion para que asi las bolas se detengan

class bola: public QGraphicsItem
{
public:

    bola();
    int bola_en_juego;
    void setPosX(float);
    void setPosY(float);
    void setVelX(float);
    void setVelY(float);
    void setAccelX(float);
    void setAccelY(float);
    void setColor(int);


    float getPosX();
    float getPosY();
    float getVelX();
    float getVelY();
    float getAccelX();
    float getAccelY();
    int getColor();

    QRectF boundingRect() const;
    void paint(QPainter *painter ,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mover(int w, int h);
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
