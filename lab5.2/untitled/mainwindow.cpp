#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    QSet<QString> vseTovary;

    vseTovary << "Хлеб"
              << "Молоко"
              << "Сыр"
              << "Сок"
              << "Масло"
              << "Чай";

    QSet<QString> magazin1;
    magazin1 << "Хлеб"
             << "Молоко"
             << "Сыр";

    QSet<QString> magazin2;
    magazin2 << "Хлеб"
             << "Сыр"
             << "Сок";

    QSet<QString> magazin3;
    magazin3 << "Хлеб"
             << "Сыр"
             << "Масло";

    QSet<QString> voVseh = magazin1;
    voVseh.intersect(magazin2);
    voVseh.intersect(magazin3);

    QSet<QString> hotyaBiVOdnom = magazin1;
    hotyaBiVOdnom.unite(magazin2);
    hotyaBiVOdnom.unite(magazin3);

    QSet<QString> netNigde = vseTovary;
    netNigde.subtract(hotyaBiVOdnom);

    ui->textEdit->clear();
    ui->textEdit_2->clear();
    ui->textEdit_3->clear();

    foreach(QString tovar, voVseh)
    {
        ui->textEdit->append(tovar);
    }

    foreach(QString tovar, hotyaBiVOdnom)
    {
        ui->textEdit_2->append(tovar);
    }

    foreach(QString tovar, netNigde)
    {
        ui->textEdit_3->append(tovar);
    }
}