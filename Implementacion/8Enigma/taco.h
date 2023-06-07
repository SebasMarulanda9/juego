#ifndef TACO_H
#define TACO_H

#include <qglobal.h>
#include <qmath.h>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QtGui>
#include <QTimer>
#include "bola.h"

class Taco {
public:
    Taco();
    Taco(float p_x, float p_y, float angl, QGraphicsScene *scene);
    virtual ~Taco();
    void moverTaco(QGraphicsScene *scene,bola &ballrefer);
    void quitaTaco(QGraphicsScene *scene);
    void poneTaco(QGraphicsScene *scene,float longitud);
    void tiroTaco(QGraphicsScene *scene,bola &ballrefer);

    void setImpulso(float impul);
    void setAngulo(float angl);
    void setPos_x(float p_x);
    void setPos_y(float p_y);

    float getImpulso();
    float getangulo();
    float getPos_x();
    float getPos_y();
private:
    QGraphicsLineItem *taco;
    float impulso;
    float angulo;
    float pos_x;
    float pos_y;
};
#endif // TACO_H
