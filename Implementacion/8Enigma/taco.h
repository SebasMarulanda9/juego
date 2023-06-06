#ifndef TACO_H
#define TACO_H

#include <qglobal.h>
#include <qmath.h>
#include <QGraphicsLineItem>
#include <QGraphicsEllipseItem>
#include <QtGui>
#include <QTimer>
#include "bola.h"

#define  LARGO_TACO 300.0
#define  RADIO_PUNTA 4.0
#define  VEL_SHOT 3.0
#define  POS_X_TACO_DEFAULT 100
#define  POS_Y_TACO_DEFAULT -650

class Taco {
public:
    Taco();
    Taco(qreal p_x, qreal p_y, qreal angl, QGraphicsScene *scene);
    virtual ~Taco();
    void impulseTaco(QGraphicsScene *scene,bola &ballrefer, qreal impulseMagn);
    void moveTaco(QGraphicsScene *scene,bola &ballrefer);
    void resetTaco(QGraphicsScene *scene);
    void drawTaco(QGraphicsScene *scene,qreal longitud);
    void tiroTaco(QGraphicsScene *scene,bola &ballrefer);

    void setImpulso(qreal impul);
    void setAngulo(qreal angl);
    void setPos_x(qreal p_x);
    void setPos_y(qreal p_y);

    qreal getImpulso();
    qreal getangulo();
    qreal getPos_x();
    qreal getPos_y();
private:
    QGraphicsEllipseItem *punt;
    QGraphicsLineItem *taco;
    qreal impulso;
    qreal angulo;
    qreal pos_x;
    qreal pos_y;
};
#endif // TACO_H
