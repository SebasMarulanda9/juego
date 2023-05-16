#include "mainwindow.h"
#include "qobjectdefs.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEstado()));
}



/*void MainWindow::definirResultadoFinal(){
    msgBox.setWindowTitle("Juego finalizado");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.setEscapeButton(QMessageBox::No);

    if(bolasRestantes==0){
        timer->stop();
        msgBox.setText("Ganaste! Felicitaciones. ¿Deseas volver a jugar?");
        if(QMessageBox::Yes == msgBox.exec()){
            iniciarJuego();
        }

        else{
            QCoreApplication::quit();
        }
    }
}*/

/*void MainWindow::actualizarCronometro(){
    time = time.addSecs(1);
    ui->cronometro->setText(time.toString("mm:ss"));

}*/

/*void MainWindow::actualizarEstado(){
    actualizarCronometro();
    definirResultadoFinal();
}*/

MainWindow::~MainWindow()
{
    delete ui;
}

