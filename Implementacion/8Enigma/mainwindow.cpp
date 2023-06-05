#include <qdebug.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bola.h"

#define num_balls 16

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int contador = 0, contador2 = 0, contador3 = 0, contador4 = 0;
    ui->setupUi(this);
    ui->graphicsView->viewport()->installEventFilter(this);
    scene = new QGraphicsScene(this);
    timer = new QTimer;
    timer2 = new QTimer;
    arreglo_bolas = new bola[num_balls];
    taco = new Taco(0,scene);
    tiro = false;

    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);
    QPixmap pixmap(":/imagenes/mesa.png");
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(pixmap);
    pixmapItem->setPos(0, 0); // Establece la posición en la escena
    pixmapItem->setScale(1.15); // Ajusta la escala del pixmap





    if(bola::getpuntaje()<15){
        for(int i=0;i<num_balls;i++){
            arreglo_bolas[i].setColor(i);

            if (i == 0){
               arreglo_bolas[i].setPosX(550);
               arreglo_bolas[i].setPosY(-205);
               arreglo_bolas[i].setVelX(0);
               arreglo_bolas[i].setVelY(0);
            }
            else{
                if(i<=5){
                    arreglo_bolas[i].setPosX(150);
                    arreglo_bolas[i].setPosY(-253+contador);
                    arreglo_bolas[i].setVelX(0);
                    arreglo_bolas[i].setVelY(0);
                    contador += radio*2;
                }
                else{
                    if(i<=9){
                        arreglo_bolas[i].setPosX(174);
                        arreglo_bolas[i].setPosY(-241+contador2);
                        arreglo_bolas[i].setVelX(0);
                        contador2 += radio*2;
                    }
                    else{
                        if(i<=12){
                            arreglo_bolas[i].setPosX(198);
                            arreglo_bolas[i].setPosY(-229+contador3);
                            arreglo_bolas[i].setVelX(0);
                            arreglo_bolas[i].setVelY(0);
                            contador3 += radio*2;
                        }
                        else{
                            if(i<=14){
                                arreglo_bolas[i].setPosX(222);
                                arreglo_bolas[i].setPosY(-217+contador4);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                                contador4 += radio*2;
                            }
                            else{
                                arreglo_bolas[i].setPosX(246);
                                arreglo_bolas[i].setPosY(-205);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                            }
                        }
                    }
                }
            }
            scene->addItem(&arreglo_bolas[i]);
            timer->start(5);
        }
    }
    else{
        for(int i=0;i<num_balls;i++){
            arreglo_bolas[i].setColor(i);

            if (i == 0){
               arreglo_bolas[i].setPosX(550);
               arreglo_bolas[i].setPosY(-205);
               arreglo_bolas[i].setVelX(0);
               arreglo_bolas[i].setVelY(0);
            }
            else{
                if(i<=5){
                    arreglo_bolas[i].setPosX(150);
                    arreglo_bolas[i].setPosY(-253+contador);
                    arreglo_bolas[i].setVelX(0);
                    arreglo_bolas[i].setVelY(0);
                    contador += radio*2;
                }
                else{
                    if(i<=9){
                        arreglo_bolas[i].setPosX(174);
                        arreglo_bolas[i].setPosY(-241+contador2);
                        arreglo_bolas[i].setVelX(0);
                        contador2 += radio*2;
                    }
                    else{
                        if(i<=12){
                            arreglo_bolas[i].setPosX(198);
                            arreglo_bolas[i].setPosY(-229+contador3);
                            arreglo_bolas[i].setVelX(0);
                            arreglo_bolas[i].setVelY(0);
                            contador3 += radio*2;
                        }
                        else{
                            if(i<=14){
                                arreglo_bolas[i].setPosX(222);
                                arreglo_bolas[i].setPosY(-217+contador4);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                                contador4 += radio*2;
                            }
                            else{
                                arreglo_bolas[i].setPosX(246);
                                arreglo_bolas[i].setPosY(-205);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                            }
                        }
                    }
                }
            }
            scene->addItem(&arreglo_bolas[i]);
            timer->start(5);
        }
    }
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
}

MainWindow::~MainWindow()
{
    delete scene;
    delete timer;
    delete timer2;
    delete arreglo_bolas;
    delete taco;
    delete ui;
}


void MainWindow::mover()
{
    tacoInteraction();
    //cout << arreglo_bolas[0].getPosX() << endl;
    for(int bola1 = 0; bola1 < num_balls; bola1++) {
       for(int bola2 = 0; bola2 < num_balls; bola2++){
           if(bola1 != bola2){
               float a = arreglo_bolas[bola1].getPosX();
               float b = arreglo_bolas[bola2].getPosX();
               float c = arreglo_bolas[bola1].getPosY();
               float d = arreglo_bolas[bola2].getPosY();
               if(sqrt(pow(a-b,2)+pow(c-d,2)) <= (2*(radio-0.5)))
                    arreglo_bolas[bola1].choque(&arreglo_bolas[bola2]);

           }
       }

        arreglo_bolas[bola1].mover(ladoIzquierdo,ladoInferior,ladoDerecho,ladoSuperior);
    }

    for(int cont = 0;cont < num_balls;cont++){
        if(arreglo_bolas[cont].muerta == 0){
            if(arreglo_bolas[cont].getPosX() <= ladoIzquierdo+tolerancia && arreglo_bolas[cont].getPosY() >= ladoSuperior-tolerancia){  //hueco superior izquierdo
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
                }
            }
            else if(arreglo_bolas[cont].getPosX() <= ladoIzquierdo+tolerancia && arreglo_bolas[cont].getPosY() <= ladoInferior+tolerancia){  //hueco inferior izquierdo
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
               }
            }
            else if(arreglo_bolas[cont].getPosX() >= 340 && arreglo_bolas[cont].getPosX() <= 356 && arreglo_bolas[cont].getPosY() <= ladoInferior+tolerancia){  //hueco intermedio inferior
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
                }
            }
            else if(arreglo_bolas[cont].getPosX() >= ladoDerecho-tolerancia && arreglo_bolas[cont].getPosY() <= ladoInferior+tolerancia){  //hueco inferior derecho
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
                }
            }
            else if(arreglo_bolas[cont].getPosX() >= ladoDerecho-tolerancia && arreglo_bolas[cont].getPosY() >= ladoSuperior-tolerancia){  //hueco superior derecho
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
                }
            }
            else if(arreglo_bolas[cont].getPosX() >= 340 && arreglo_bolas[cont].getPosX() <= 356 && arreglo_bolas[cont].getPosY() >= ladoSuperior-tolerancia){  //hueco intermedio superior
                if(cont==0){
                    arreglo_bolas[cont].setPosX(550);
                    arreglo_bolas[cont].setPosY(-205);
                    arreglo_bolas[cont].setVelX(0);
                    arreglo_bolas[cont].setVelY(0);
                }
                else{
                    arreglo_bolas[cont].bola_en_juego = 0;
                    bola::setpuntaje(1);
                }
            }
        }
    }
}

void MainWindow::tacoInteraction()
{
    if(tiro){
        tiro = false;
        taco->tiroTaco(scene,arreglo_bolas[0]);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)

{
    if(watched == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonRelease)
    {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        float pos_mouseX = mouseEvent->x();
        float pos_mouseY = mouseEvent->y();
        std::cout << "Mouse: X= " << pos_mouseX << ", Y= " << pos_mouseY << std::endl;
        float catetoOpuesto = 0, catetoAdyacente = 0;
        float pos_blancaX = arreglo_bolas[0].getPosX()+18;
        float pos_blancaY = arreglo_bolas[0].getPosY()+467;
        std::cout << "Bola: X= " << pos_blancaX << " Y:= " << pos_blancaY << std::endl;
        catetoOpuesto = fabs(pos_mouseY-pos_blancaY);
        catetoAdyacente = fabs(pos_mouseX-pos_blancaX);

        double ang = atan2(static_cast<double>(catetoOpuesto), static_cast<double>(catetoAdyacente));
        double anguloGrados = ang*(180/M_PI);

        std::cout << "Angulo: " << anguloGrados << " grados\n \n" << std::endl;

        timer2->start(1000);

        //angulo
        float angulo = -((float)anguloGrados)*(M_PI/180.0);
        taco->setAngulo(angulo);

        //fuerza
        taco->setImpulso((float)150);

        //disparar
        tiro = true;
    }
    return false;
}

