#include <qdebug.h>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "bola.h"
#define ancho_mesa 640
#define largo_mesa 400
#define margen 30
#define num_balls 16
#define distancia_bolas_mesa 3
#define distancia_bola_blanca 11

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    int puntaje = 15;
    ui->setupUi(this);
    scene= new QGraphicsScene(this);
    timer = new QTimer;
    timer2 = new QTimer;
    arreglo_bolas = new bola[num_balls];
    taco = new Taco(0,scene);
    tiro = false;
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing,true);

    if(puntaje<15){
        for(int i=0;i<num_balls;i++){
            arreglo_bolas[i].setColor(i);
            if (i == 0){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-2*radio)/2+(2*15-1-28)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bola_blanca*margen+10*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=5){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-10*radio)/2+(2*i-1)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+2*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=9){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-8*radio)/2+(2*i-1-10)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+4*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=12){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-6*radio)/2+(2*i-1-18)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+6*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=14){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-4*radio)/2+(2*i-1-24)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+8*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }else{
                arreglo_bolas[i].setPosX((ancho_mesa-margen-2*radio)/2+(2*i-1-28)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+10*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }

            scene->addItem(&arreglo_bolas[i]);
            timer->start(5);
        }
    }


    else{
        for(int i=0;i<num_balls;i++){
            arreglo_bolas[i].setColor(i);
            if (i == 0){
               arreglo_bolas[i].setPosX((ancho_mesa-margen-2*radio)/2+(2*15-1-28)*radio);
               arreglo_bolas[i].setPosY(-(distancia_bola_blanca*margen+10*radio));
               arreglo_bolas[i].setVelX(0);
               arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=5){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-10*radio)/2+(2*i-1)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+2*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=9){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-8*radio)/2+(2*i-1-10)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+4*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=12){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-6*radio)/2+(2*i-1-18)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+6*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else
            if(i<=14){
                arreglo_bolas[i].setPosX((ancho_mesa-margen-4*radio)/2+(2*i-1-24)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+8*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
            }
            else{
                arreglo_bolas[i].setPosX((ancho_mesa-margen-2*radio)/2+(2*i-1-28)*radio);
                arreglo_bolas[i].setPosY(-(distancia_bolas_mesa*margen+10*radio));
                arreglo_bolas[i].setVelX(0);
                arreglo_bolas[i].setVelY(0);
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
    for(int it1 = 0; it1 < num_balls; it1++) {
       for(int it2 = 0; it2 < num_balls; it2++){
           if(it1 != it2){
               float a = arreglo_bolas[it1].getPosX();
               float b = arreglo_bolas[it2].getPosX();
               float c = arreglo_bolas[it1].getPosY();
               float d = arreglo_bolas[it2].getPosY();
               if(sqrt(pow(a-b,2)+pow(c-d,2)) <= (2*(radio-0.5)))
                   arreglo_bolas[it1].choque(&arreglo_bolas[it2]);

           }
       }

        arreglo_bolas[it1].mover(ancho_mesa-2*margen,largo_mesa-2*margen);
    }
  }

void MainWindow::tacoInteraction()
{
    if(tiro){
        tiro = false;
         taco->shotTaco( scene,arreglo_bolas[0]);
    }
}

void MainWindow::on_Tirar_clicked()
{
    timer2->start(1000);
    //poner taco
    taco->setAngulo(-90*(M_PI/180.0));

    //angulo
    qreal angulo = 4*((qreal)68)*(M_PI/180.0);
     taco->setAngulo(angulo);


    //fuerza
    taco->setImpulso((qreal)150);


    //disparar
    tiro = true;

}

