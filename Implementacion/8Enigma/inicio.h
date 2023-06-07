#ifndef INICIO_H
#define INICIO_H

#include <QMainWindow>

namespace Ui {
class inicio;
}

class inicio : public QMainWindow
{
    Q_OBJECT

public:
    explicit inicio(QWidget *parent = nullptr);
    ~inicio();

private slots:
    void on_pushButton_clicked();

private:
    Ui::inicio *ui;
};

#endif // INICIO_H
