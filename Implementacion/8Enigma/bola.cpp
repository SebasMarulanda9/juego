#include "bola.h"


bola::bola()
{
    posX = 0;
    posY = 0;
    velX = 0;
    velY = 0;
    accelX = 0;
    accelY = 0;
    velX = 0;
    velY = 0;
    color = 0;
    bola_en_juego = 1;
    muerta = 0;
}

int bola::m=0;

void bola::setPosX(float _posX){
    posX = _posX;
}
void bola::setPosY(float _posY){
    posY = _posY;
}
void bola:: setVelX(float _velX){
    velX = _velX;
}
void bola::setVelY(float _velY){
    velY = _velY;
}

void bola::setAccelX(float _accelX){
    accelX = _accelX;
}
void bola::setAccelY(float _accelY){
    accelY = _accelY;
}

void bola::setColor(int _color)
{
    color = _color;
}

void bola::setM(int _m)
{
    m+=_m;
}

float bola:: getPosX() { return posX; }

float bola:: getPosY() { return posY; }

float bola:: getVelX() { return velX; }

float bola:: getVelY() { return velY; }

float bola:: getAccelX() { return accelX; }

float bola:: getAccelY() { return accelY; }

int bola::getColor() { return color; }

int bola::getM()
{
    return m;
}

QRectF bola::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);

}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    switch(color){//se asigna un numero para cada color el cual es utilizado en mainwindows dentro del for que dibuja las bolas empezando por la blanca como indica el switch ya que es el caso 0
    case 0:
        painter->setBrush(Qt::white);
        break;
    case 1:
        painter->setBrush(Qt::green);
        break;
    case 2:
        painter->setBrush(Qt::yellow);
        break;
    case 3:
        painter->setBrush(Qt::blue);
        break;
    case 4:
        painter->setBrush(Qt::gray);
        break;
    case 5:
        painter->setBrush(Qt::red);
        break;
    case 6:
        painter->setBrush(Qt::magenta);
        break;
    case 7:
        painter->setBrush(Qt::darkCyan);
        break;
    case 8:
        painter->setBrush(Qt::darkYellow);
        break;
    case 9:
        painter->setBrush(Qt::lightGray);
        break;
    case 10:
        painter->setBrush(Qt::darkRed);
        break;
    case 11:
        painter->setBrush(Qt::cyan);
        break;
    case 12:
        painter->setBrush(Qt::darkMagenta);
        break;
    case 13:
        painter->setBrush(Qt::darkGray);
        break;
    case 14:
        painter->setBrush(Qt::darkBlue);
        break;
    case 15:
        painter->setBrush(Qt::black);
        break;
    default:
        break;
    }
    painter->drawEllipse(boundingRect());
}


void bola::mover(int x0, int y0, int w, int h)
{
    if(bola_en_juego == 1){

        posX += (time*velX);
        posY += (time*velY);

        velX *= desaceleracion;
        velY *= desaceleracion;

        if(posX-radio <= x0){
            velX *= -0.9;
            if(posX-radio+radio/100 <= x0){
                posX = x0+radio;
            }
        }
        if(posX+radio >= x0+w){
            velX *= - 0.9;
            if(posX+radio-radio/100 >= x0+w){
                posX = x0-radio+w;
            }
        }

        if(posY-radio <= y0){
            velY *= - 0.9;
            if(posY-radio+radio/100 <= y0){
                posY = y0+radio;
            }
        }
        if(posY+radio >= y0+h){
            velY *= - 0.9;
            if(posY+radio-radio/100 >= y0+h){
                posY = y0-radio+h;
            }
        }

        setPos(posX,-posY);
    }
    else{
        if(muerta == 0){   //la variable "muerta" se utiliza para que solo entre una vez
            muerta ++;
            setPos(bola_en_hueco_x,radio);
            bola :: setM(1);   //la funcion set ya no se suma solo de a uno, se le suma el argumento
            muerta *= bola::getM();
            posY = radio;
        }
        else{
            setPos(-35,470-(2*radio*(muerta)));
        }

    }
}

float bola::choque(bola *b2)
{
    if(fabs(velX) < 0.0000001 && fabs(velY) < 0.0000001){
        if(fabs(b2->velX) < 0.0000001 && fabs(b2->velY) < 0.0000001)
            return 0.0;
        b2->choque(this);
        return 0.0;
    }

    float ta,tb,tc,td;
    ta = time*velX;
    tb = time*velY;
    tc = time*b2->velX;
    td = time*b2->velY;

    //Calculando el parametro de impacto

    float a = -1*velY;
    float b = velX;
    float c = a*posX + b*posY;
    float param = fabs(a*b2->posX+b*b2->posY-c)/sqrt(pow(a,2)+pow(b,2));

    //Si la colision es unidimensional
    if(param < 0.1){
        float t1 = velX* 0.9;
        float t2 = velY* 0.9;
        velX = velX * - 0.9;
        velY = velY *  - 0.9;
        b2->velX = t1;
        b2->velY = t2;
        return 0.0;
    }

    //Si no es unidimensional, se calcula velocidades y ángulos

    float teta = asin(param/(2*radio));
    float alfa = atan2(2*tan(teta),1-0.9)-teta;
    // float alfa = (M_PI/2)-teta;
    std::cout<<"alfa: "<<alfa<<" "<<"teta: "<<teta<<std::endl;
    teta *=-1;
    float vel_final1 =(cos(alfa)*(velY+b2->velY)-sin(alfa)*(velX+b2->velX))/sin(-M_PI/2);
    float vel_final2 = (velX+b2->velX-vel_final1*cos(teta))/cos(alfa);

    //Asignación  de las nuevas velocidades

    velX = vel_final1*cos(alfa);
    velY = -vel_final1*sin(alfa);
    b2->velX = vel_final2*cos(teta);
    b2->velY = -vel_final2*sin(teta);

    //Nuevas posiciones

    posX -= ta;
    posY -= tb;
    b2->posX -= tc;
    b2->posY -= td;
    return vel_final1;

}
