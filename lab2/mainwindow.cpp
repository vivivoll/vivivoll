#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    float a = ui->lineEdit->text().toFloat();
    float b = ui->lineEdit_2->text().toFloat();
    float c = ui->lineEdit_3->text().toFloat();

    float min = a;

    if(b < min) min = b;
    if(c < min) min = c;

    if (min == a)
        a = b + c;
    else if (min == b)
        b = a + c;
    else
        c = a + b;

    ui->textEdit->setText("a=" + QString::number(a) +
                          " b=" + QString::number(b) +
                          " c=" + QString::number(c));
}