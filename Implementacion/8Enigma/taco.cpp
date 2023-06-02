#include "taco.h"
#include "mainwindow.h"
#include "bola.h"
#define rad 12//el taco se dibuja en una circunferencia con centro en el punto medio de la bola blanca
//y este radio es la distancia por defecto de el centro a donde se dibuja

Taco::Taco() {
    impulso = 4.0;
    angulo = 0;
}

Taco::Taco(qreal angl, QGraphicsScene *scene) {
     angulo = angl;
     impulso = 0;
}

Taco::~Taco() {

}

void Taco::shotTaco(QGraphicsScene *scene,bola &ballrefer){//se calcula la velocidad en X y en Y
    qreal Vel_x = 70*( impulso*cos( angulo));    // las cuales se pasan al metodo set de la bola blanca
    qreal Vel_y = 70*( impulso*sin( angulo));    // que es la bola que se pasa por referencia

    ballrefer.setVelX(-Vel_x);//se envian valores a la bola
    ballrefer.setVelY(-Vel_y);
    impulso = 0;
}

void Taco::setImpulso(qreal impul){
     impulso = impul;
}
void Taco::setAngulo(qreal angl){
     angulo = angl;
}

qreal Taco::getImpulso(){
    return  impulso;
}
qreal Taco::getangulo(){
    return  angulo;
}
