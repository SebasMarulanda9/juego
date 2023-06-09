#include "inicio.h"
#include "mainwindow.h"
#include "ui_inicio.h"

inicio::inicio(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::inicio)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
    QIcon icon(":/imagenes/icono.png");
    setWindowIcon(icon);
}

inicio::~inicio()
{
    delete ui;
}

void inicio::on_pushButton_clicked()
{
    MainWindow *juego= new MainWindow(this);
    juego->show();
}

