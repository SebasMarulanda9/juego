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
    Taco(qreal angl,QGraphicsScene *scene);
    ~Taco();
    void shotTaco(QGraphicsScene *scene,bola &ballrefer);

    void setImpulso(qreal impul);
    void setAngulo(qreal angl);

    qreal getImpulso();
    qreal getangulo();
private:
    qreal impulso;
    qreal angulo;
};
#endif // TACO_H
