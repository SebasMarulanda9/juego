#include <qdebug.h>
#include "ganaste.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bola.h"

#define num_bolas 16

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    contador = 0, contador2 = 0, contador3 = 0, contador4 = 0;
    ui->setupUi(this);
    ui->graphicsView->viewport()->installEventFilter(this);
    scene = new QGraphicsScene(this);
    timer = new QTimer;
    timer2 = new QTimer;
    arreglo_bolas = new bola[num_bolas];
    taco = new Taco(0,0,0,scene);
    tiro = true;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);
    scene->setSceneRect(0,0,692,384);
    QPixmap pixmap(":/imagenes/mesa.png");
    QGraphicsPixmapItem* pixmapItem = scene->addPixmap(pixmap);
    pixmapItem->setPos(0, 0);
    pixmapItem->setScale(1.15);
    taco->setAngulo(0*(M_PI/180.0));
    connect(timer2,SIGNAL(timeout()),this,SLOT(updatelabel()));
    QIcon icon(":/imagenes/icono.png");
    setWindowIcon(icon);

    for(int i=0;i<num_bolas;i++){
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
                contador += radio*2+2;
            }
            else{
                if(i<=9){
                    arreglo_bolas[i].setPosX(174);
                    arreglo_bolas[i].setPosY(-241+contador2);
                    arreglo_bolas[i].setVelX(0);
                    contador2 += radio*2+2;
                }
                else{
                    if(i<=12){
                        arreglo_bolas[i].setPosX(198);
                        arreglo_bolas[i].setPosY(-229+contador3);
                        arreglo_bolas[i].setVelX(0);
                        arreglo_bolas[i].setVelY(0);
                        contador3 += radio*2+2;
                    }
                    else{
                        if(i<=14){
                            arreglo_bolas[i].setPosX(222);
                            arreglo_bolas[i].setPosY(-217+contador4);
                            arreglo_bolas[i].setVelX(0);
                            arreglo_bolas[i].setVelY(0);
                            contador4 += radio*2+2;
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
    connect(timer,SIGNAL(timeout()),this,SLOT(mover()));
}


void MainWindow::updatelabel(){
    contadorDisplay++;
    ui->display->display(QString::number(contadorDisplay));
    int puntaje = bola::getpuntaje();
    ui->display2->display(puntaje);
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

void MainWindow::reinicio()
{
    contador = 0, contador2 = 0, contador3 = 0, contador4 = 0;
    if(bola::getpuntaje()==15){
        ganaste *ganast= new ganaste(this);
        ganast->show();
        timer2->stop();
        contadorDisplay = 0;
        bola::resetM();
        bola::resetPuntaje();

        for(int cont = 0;cont < num_bolas;cont++){
            arreglo_bolas[cont].encestada = 0;
        }

        for(int i=0;i<num_bolas;i++){
            if (i == 0){
                arreglo_bolas[i].setPosX(550);
                arreglo_bolas[i].setPosY(-205);
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else{
                if(i<=5){
                    arreglo_bolas[i].bola_en_juego = 1;
                    arreglo_bolas[i].setPosX(150);
                    arreglo_bolas[i].setPosY(-253+contador);
                    arreglo_bolas[i].setVelX(0);
                    arreglo_bolas[i].setVelY(0);
                    contador += radio*2+2;
                }
                else{
                    if(i<=9){
                        arreglo_bolas[i].bola_en_juego = 1;
                        arreglo_bolas[i].setPosX(174);
                        arreglo_bolas[i].setPosY(-241+contador2);
                        arreglo_bolas[i].setVelX(0);
                        contador2 += radio*2+2;
                    }
                    else{
                        if(i<=12){
                            arreglo_bolas[i].bola_en_juego = 1;
                            arreglo_bolas[i].setPosX(198);
                            arreglo_bolas[i].setPosY(-229+contador3);
                            arreglo_bolas[i].setVelX(0);
                            arreglo_bolas[i].setVelY(0);
                            contador3 += radio*2+2;
                        }
                        else{
                            if(i<=14){
                                arreglo_bolas[i].bola_en_juego = 1;
                                arreglo_bolas[i].setPosX(222);
                                arreglo_bolas[i].setPosY(-217+contador4);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                                contador4 += radio*2+2;
                            }
                            else{
                                arreglo_bolas[i].bola_en_juego = 1;
                                arreglo_bolas[i].setPosX(246);
                                arreglo_bolas[i].setPosY(-205);
                                arreglo_bolas[i].setVelX(0);
                                arreglo_bolas[i].setVelY(0);
                            }
                        }
                    }
                }
            }
        }
    }

}

void MainWindow::mover()
{
    tacoInteraction();
    for(int bola1 = 0; bola1 < num_bolas; bola1++) {
        for(int bola2 = 0; bola2 < num_bolas; bola2++){
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

    for(int cont = 0;cont < num_bolas;cont++){
        if(arreglo_bolas[cont].encestada == 0){
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
    //verifica si llego al puntaje maximo y renicia el juego
    reinicio();
}

void MainWindow::tacoInteraction()
{
    //disparo
    if(tiro){
        tiro = false;
        taco->tiroTaco(scene,arreglo_bolas[0]);
    }

    velBlanca_x = arreglo_bolas[0].getVelX();
    velBlanca_y = arreglo_bolas[0].getVelY();

    //quitar taco
    if(fabs(velBlanca_x) < 15 && fabs(velBlanca_y) < 15){
        taco->moverTaco(scene,arreglo_bolas[0]);
    }
    else {
        taco->quitaTaco( scene);
    }
}

bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if (watched == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonPress)
    {
        tiempoAcumulado = QDateTime::currentMSecsSinceEpoch();
    }
    if(watched == ui->graphicsView->viewport() && event->type() == QEvent::MouseButtonRelease)
    {
        int tiempoActual = QDateTime::currentMSecsSinceEpoch();
        int duracion = tiempoActual - tiempoAcumulado;

        if(duracion>3000)
         duracion = 3000;

        QMouseEvent *mouseEvent = static_cast<QMouseEvent*>(event);
        QPointF scenePos = ui->graphicsView->mapToScene(mouseEvent->pos());

        float pos_mouseX = scenePos.x();
        float pos_mouseY = scenePos.y();
        float catetoOpuesto = 0, catetoAdyacente = 0;
        float pos_blancaX = arreglo_bolas[0].getPosX();
        float pos_blancaY = -arreglo_bolas[0].getPosY();

        catetoOpuesto = fabs(pos_mouseY-pos_blancaY);
        catetoAdyacente = fabs(pos_mouseX-pos_blancaX);

        double ang = atan2(static_cast<double>(catetoOpuesto), static_cast<double>(catetoAdyacente));
        double anguloGrados = ang*(180/M_PI);

        if(pos_mouseX>=pos_blancaX && pos_mouseY<=pos_blancaY){
            anguloGrados = 180-anguloGrados;
        }
        else if(pos_mouseX>=pos_blancaX && pos_mouseY>=pos_blancaY){
            anguloGrados = anguloGrados-180;
        }
        else if(pos_mouseX<=pos_blancaX && pos_mouseY>=pos_blancaY){
            anguloGrados = 360-anguloGrados;
        }

        timer2->start(1000);

        //angulo
        float angulo = -((float)anguloGrados)*(M_PI/180.0);
        taco->setAngulo(angulo);

        //fuerza
        taco->setImpulso((float)duracion/10);

        //disparar
        tiro = true;
    }
    return false;
}


