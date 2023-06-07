#include "bola.h"

bola::bola()
{
    posX = 0;
    posY = 0;
    velX = 0;
    velY = 0;
    accelX = 0;
    accelY = 0;
    color = 0;
    bola_en_juego = 1;
    encestada = 0;
}

int bola::m=0;
int bola::puntaje=0;

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

void bola::setpuntaje(int _puntaje)
{
    puntaje+=_puntaje;
}

void bola::resetPuntaje()
{
    puntaje = 0;
}

void bola::resetM(){
    m = 0;
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

int bola::getpuntaje()
{
    return puntaje;
}

QRectF bola::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void bola::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap image;
    switch(color){
    case 0:
        image = QPixmap(":/imagenes/0.png");
        break;
    case 1:
        image = QPixmap(":/imagenes/1.png");
        break;
    case 2:
        image = QPixmap(":/imagenes/2.png");
        break;
    case 3:
        image = QPixmap(":/imagenes/3.png");
        break;
    case 4:
        image = QPixmap(":/imagenes/4.png");
        break;
    case 5:
        image = QPixmap(":/imagenes/5.png");
        break;
    case 6:
        image = QPixmap(":/imagenes/6.png");
        break;
    case 7:
        image = QPixmap(":/imagenes/7.png");
        break;
    case 8:
        image = QPixmap(":/imagenes/8.png");
        break;
    case 9:
        image = QPixmap(":/imagenes/9.png");
        break;
    case 10:
        image = QPixmap(":/imagenes/10.png");
        break;
    case 11:
        image = QPixmap(":/imagenes/11.png");
        break;
    case 12:
        image = QPixmap(":/imagenes/12.png");
        break;
    case 13:
        image = QPixmap(":/imagenes/13.png");
        break;
    case 14:
        image = QPixmap(":/imagenes/14.png");
        break;
    case 15:
        image = QPixmap(":/imagenes/15.png");
        break;
    default:
        break;
    }
    QRectF rect = boundingRect();
    QPointF position(rect.x(), rect.y());
    QSizeF size(rect.width(), rect.height());

    //dibujar la imagen en lugar de la elipse
    painter->drawPixmap(position, image.scaled(QSize(size.width(), size.height())));
}

void bola::mover(int x0, int y0, int w, int h)
{
    if(bola_en_juego == 1){
        posX += (tiempo*velX);
        posY += (tiempo*velY);

        velX *= desaceleracion;
        velY *= desaceleracion;

        if(posX-radio <= x0){
            velX *= -elasti;
            if(posX-radio+radio/100 <= x0){  //lado izquierdo
                posX = x0+radio;
            }
        }
        if(posX+radio >= w){
            velX *= -elasti;
            if(posX+radio-radio/100 >= w){ //lado derecho
                posX = w-radio;
            }
        }
        if(posY-radio <= y0){
            velY *= -elasti;
            if(posY-radio+radio/100 <= y0){  //lado inferior
                posY = y0+radio;
            }
        }
        if(posY+radio >= h){
            velY *= -elasti;
            if(posY+radio-radio/100 >= h){  //lado superior
                posY = h-radio;
            }
        }
        setPos(posX,-posY);
    }

    else{
        if(encestada == 0){   //la variable "encestada" se utiliza para que solo entre una vez
            encestada ++;
            bola::setM(1);
            encestada *= bola::getM();
            posY = radio;
        }
        else{
            setPos(54+(radio*3*encestada),-20);
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
    ta = tiempo*velX;
    tb = tiempo*velY;
    tc = tiempo*b2->velX;
    td = tiempo*b2->velY;

    //calculando el parametro de impacto

    float a = -1*velY;
    float b = velX;
    float c = a*posX + b*posY;
    float param = fabs(a*b2->posX+b*b2->posY-c)/sqrt(pow(a,2)+pow(b,2));

    //si la colision es unidimensional
    if(param < 0.1){
        float t1 = velX* elasti;
        float t2 = velY* elasti;
        velX = velX *  -elasti;
        velY = velY *   -elasti;
        b2->velX = t1;
        b2->velY = t2;
        return 0.0;
    }

    //si no es unidimensional, se calcula velocidades y ángulos

    float teta = asin(param/(2*radio));
    float alfa = atan2(2*tan(teta),1-elasti)-teta;
    teta *=-1;
    float vel_final1 = (cos(alfa)*(velY+b2->velY)-sin(alfa)*(velX+b2->velX))/sin(-M_PI/2);
    float vel_final2 = (velX+b2->velX-vel_final1*cos(teta))/cos(alfa);

    //asignación  de las nuevas velocidades

    velX = vel_final1*cos(alfa);
    velY = -vel_final1*sin(alfa);
    b2->velX = vel_final2*cos(teta);
    b2->velY = -vel_final2*sin(teta);

    //nuevas posiciones

    posX -= ta;
    posY -= tb;
    b2->posX -= tc;
    b2->posY -= td;

    return vel_final1;
}
