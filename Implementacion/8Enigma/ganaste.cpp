#include "ganaste.h"
#include "ui_ganaste.h"

ganaste::ganaste(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ganaste)
{
    ui->setupUi(this);
    setWindowFlags(windowFlags() | Qt::MSWindowsFixedSizeDialogHint);
}

ganaste::~ganaste()
{
    delete ui;
}

void ganaste::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
}


void ganaste::on_pushButton_clicked()
{
    close();
}

