#ifndef TACO_H
#define TACO_H

#include <qglobal.h>
#include <qmath.h>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QtGui>
#include "bola.h"

class Taco {
public:
    Taco();
    Taco(float angl,QGraphicsScene *scene);
    ~Taco();
    void tiroTaco(QGraphicsScene *scene,bola &ballrefer);

    void setImpulso(float impul);
    void setAngulo(float angl);

    float getImpulso();
    float getangulo();
private:
    float impulso;
    float angulo;
};
#endif // TACO_H
