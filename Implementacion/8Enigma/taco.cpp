#include "taco.h"
#include "mainwindow.h"
#include "bola.h"
#define rad 12

Taco::Taco() {
    impulso = 4.0;
    angulo = 0;
}

Taco::Taco(float angl, QGraphicsScene *scene) {
    angulo = angl;
    impulso = 0;
}

Taco::~Taco() {

}

void Taco::tiroTaco(QGraphicsScene *scene,bola &ballrefer){//se calcula la velocidad en X y en Y
    float Vel_x = 70*( impulso*cos(angulo));
    float Vel_y = 70*( impulso*sin(angulo));

    ballrefer.setVelX(-Vel_x);//se envian valores a la bola
    ballrefer.setVelY(-Vel_y);
    impulso = 0;
}

void Taco::setImpulso(float impul){
    impulso = impul;
}
void Taco::setAngulo(float angl){
    angulo = angl;
}

float Taco::getImpulso(){
    return  impulso;
}
float Taco::getangulo(){
    return  angulo;
}
