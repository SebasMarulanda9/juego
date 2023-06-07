#include "taco.h"
#include "mainwindow.h"
#include "bola.h"
#define rad 12

Taco::Taco() {
    impulso = 0;
    angulo = 0;
    taco = NULL;
    pos_x = 0;
    pos_y = 0;
}

Taco::Taco(float p_x, float p_y, float angl, QGraphicsScene *scene){
    angulo = angl;
    impulso = 0;
    taco = NULL;
    pos_x = p_x;
    pos_y = p_y;
    impulso = 0;
    poneTaco(scene);
}

Taco::~Taco(){
    delete taco;
}

void Taco::moverTaco(QGraphicsScene *scene,bola &ballrefer){
    float X_ref = ballrefer.getPosX();
    float Y_ref = ballrefer.getPosY();
    float R_ref = rad*2;

    pos_x = X_ref + (R_ref+ impulso)*cos( angulo);
    pos_y = Y_ref + (R_ref+ impulso)*sin( angulo);

    poneTaco(scene);
}

void Taco::quitaTaco(QGraphicsScene *scene){
    scene->removeItem( taco);
}

void Taco::poneTaco(QGraphicsScene *scene){
    if(taco != NULL)
        delete taco;

    QPixmap tacoImage(":/imagenes/taco.png");
    taco = new QGraphicsPixmapItem(tacoImage);
    taco->setPos(pos_x, -pos_y-tacoImage.height()/2);
    taco->setTransformOriginPoint(0, 0); // Establece el punto de origen
    taco->setRotation(-qRadiansToDegrees(angulo));
    scene->addItem(taco);
}

void Taco::tiroTaco(QGraphicsScene *scene,bola &ballrefer){

    //se calcula la velocidad en X y en Y
    float Vel_x = 70*( impulso*cos(angulo));
    float Vel_y = 70*( impulso*sin(angulo));

    //se envian valores a la bola
    ballrefer.setVelX(-Vel_x);
    ballrefer.setVelY(-Vel_y);
    impulso = 0;

    moverTaco(scene, ballrefer);
}

void Taco::setImpulso(float impul){
    impulso = impul;
}
void Taco::setAngulo(float angl){
    angulo = angl;
}
void Taco::setPos_x(float p_x){
     pos_x = p_x;
}
void Taco::setPos_y(float p_y){
     pos_y = p_y;
}

float Taco::getImpulso(){
    return  impulso;
}
float Taco::getangulo(){
    return  angulo;
}
float Taco::getPos_x(){
    return  pos_x;
}
float Taco::getPos_y(){
    return  pos_y;
}
