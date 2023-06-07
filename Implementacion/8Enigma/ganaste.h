#ifndef GANASTE_H
#define GANASTE_H

#include <QMainWindow>

namespace Ui {
class ganaste;
}

class ganaste : public QMainWindow
{
    Q_OBJECT

public:
    explicit ganaste(QWidget *parent = nullptr);
    ~ganaste();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::ganaste *ui;
};

#endif // GANASTE_H
