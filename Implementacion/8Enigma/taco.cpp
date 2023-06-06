#include "taco.h"
#include "mainwindow.h"
#include "bola.h"
#define rad 12

Taco::Taco() {
    impulso = RADIO_PUNTA;
    angulo = 0;
    taco = NULL;
    punt =  NULL;
    pos_x = 0;
    pos_y = 0;
}

Taco::Taco(qreal p_x, qreal p_y, qreal angl, QGraphicsScene *scene) {
    angulo = angl;
    impulso = 0;
    taco = NULL;
    pos_x = p_x;
    pos_y = p_y;
    impulso = 0;
    drawTaco(scene,LARGO_TACO);
}


Taco::~Taco() {
    if(punt != NULL)
        delete punt;
    if(taco != NULL)
        delete taco;
}

void Taco::impulseTaco(QGraphicsScene *scene,bola &ballrefer, qreal impulseMagn){
     impulso += impulseMagn;

     moveTaco(scene,ballrefer);
}

void Taco::moveTaco(QGraphicsScene *scene,bola &ballrefer){
    qreal X_ref = ballrefer.getPosX()/**ESCALA*/;
    qreal Y_ref = ballrefer.getPosY()/**ESCALA*/;
    qreal R_ref = rad*2/**ESCALA*/;

    pos_x = X_ref + (R_ref+ impulso)*cos( angulo);
    pos_y = Y_ref + (R_ref+ impulso)*sin( angulo);

    drawTaco(scene,LARGO_TACO);
}
void Taco::resetTaco(QGraphicsScene *scene){//funcion para poner el taco debajo de la mesa en el cual el angulo e impulso son 0
    //angulo = 0;
    //impulso = 0;
    //scene->removeItem( taco);
}
void Taco::drawTaco(QGraphicsScene *scene,qreal longitud){

    qreal X_taco =  pos_x + longitud*cos(angulo);//se calcula para dibujar el taco en la direccion que se desea apuntar
    qreal Y_taco =  pos_y + longitud*sin(angulo);//cuando se gira el angulo el taco siempre queda de frente  la bola
    qreal Punt_X =  pos_x - RADIO_PUNTA;//sirve para saber donde dibujar la punta del taco ya que no es solo un dibujo
    qreal Punt_Y = - pos_y - RADIO_PUNTA;//a la posicion de la bola blanca se le resta el Radio de la punta difinido al inicio

    if(taco != NULL)//estos dos condicionales sirven para eliminar el taco en cada posicion nueva eliminan el taco anterior
        delete taco;//cuando se mueve hacia adelante o alrededor de la bola blanca de no existir estos condicionales
    /*if(punt != nullptr)//se dibujarian tantos tacos como movimientos que se realicen
        delete punt;*/


    QBrush puntaColor(Qt::black);//se define el color de la punta Negro
    QPen tacoColor(QColor(200,100,0));//se define el color de la linea que es el taco cafe claro
    tacoColor.setWidth(6);//se le asigna el grosor a la linea que dibuja el cuerpo del taco
    taco = new QGraphicsLineItem(pos_x,- pos_y,X_taco,-Y_taco);//se dibuja el taco
    taco->setPen(tacoColor);//se le asigna el color
    punt = new QGraphicsEllipseItem(Punt_X,Punt_Y,2*RADIO_PUNTA,2*RADIO_PUNTA);//se dibuja la punta
    punt->setBrush(puntaColor);//se le asigna el color
    punt->setPen(QPen(Qt::red));//se traza el color rojo que esta alrededor de el punto negro en la punta
    scene->addItem( taco);//se añade el taco a la escena
    scene->addItem( punt);//se añade la punta del taco a la escena
    delete punt;

}

void Taco::tiroTaco(QGraphicsScene *scene,bola &ballrefer){//se calcula la velocidad en X y en Y
    qreal Vel_x = 70*( impulso*cos(angulo));
    qreal Vel_y = 70*( impulso*sin(angulo));

    ballrefer.setVelX(-Vel_x);//se envian valores a la bola
    ballrefer.setVelY(-Vel_y);
    impulso = 0;//se resetea el impulso
    //scene->removeItem(taco);
    moveTaco(scene, ballrefer);

}

void Taco::setImpulso(qreal impul){
    impulso = impul;
}
void Taco::setAngulo(qreal angl){
    angulo = angl;
}
void Taco::setPos_x(qreal p_x){
     pos_x = p_x;
}
void Taco::setPos_y(qreal p_y){
     pos_y = p_y;
}

qreal Taco::getImpulso(){
    return  impulso;
}
qreal Taco::getangulo(){
    return  angulo;
}
qreal Taco::getPos_x(){
    return  pos_x;
}
qreal Taco::getPos_y(){
    return  pos_y;
}
