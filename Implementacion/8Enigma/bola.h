#ifndef BOLA_H
#define BOLA_H

#include <math.h>
#include <QGraphicsItem>
#include <QPainter>
#include <iostream>


#define radio 12// Macro del radio para todas las bolas igual
#define masa 100// Masa de las bolas para todas igual

#define time 0.001 //Macro para el tiempo
// #define e 0.9 //Coeficiente de elasticidad
#define desaceleracion 0.992 // Desacelaracion para que asi las bolas se detengan

#define bola_en_hueco_x - 34
#define bola_en_hueco_y 460 - radio




class bola: public QGraphicsItem
{
public:

    bola();
    int bola_en_juego;
    int muerta;
    static int m;
    static int puntaje;

    void setPosX(float);
    void setPosY(float);
    void setVelX(float);
    void setVelY(float);
    void setAccelX(float);
    void setAccelY(float);
    void setColor(int);
    static void setM(int);

    float getPosX();
    float getPosY();
    float getVelX();
    float getVelY();
    float getAccelX();
    float getAccelY();
    int getColor();
    static int getM();


    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
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
