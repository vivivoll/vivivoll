#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "katalog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("BoardShop");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Katalog katalog;
    katalog.setModal(true);
    katalog.exec();
}