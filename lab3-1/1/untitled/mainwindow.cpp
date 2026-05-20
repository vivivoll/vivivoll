#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <cstdlib>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    nachalo = nullptr;

    srand(time(0));

    for(int i = 0; i < 10; i++)
    {
        dobavitVKonec(rand() % 100);
    }

    pokazatSpisok();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dobavitVKonec(int chislo)
{
    Element* noviy = new Element;

    noviy->znachenie = chislo;
    noviy->sled = nullptr;

    if(nachalo == nullptr)
    {
        nachalo = noviy;
        return;
    }

    Element* tek = nachalo;

    while(tek->sled != nullptr)
    {
        tek = tek->sled;
    }

    tek->sled = noviy;
}

void MainWindow::udalitSNachala()
{
    if(nachalo == nullptr)
        return;

    Element* temp = nachalo;

    nachalo = nachalo->sled;

    delete temp;
}

void MainWindow::pokazatSpisok()
{
    ui->textEdit->clear();

    Element* tek = nachalo;

    while(tek != nullptr)
    {
        ui->textEdit->append(QString::number(tek->znachenie));

        tek = tek->sled;
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        int chislo = ui->lineEdit->text().toInt();

        dobavitVKonec(chislo);
    }

    if(ui->radioButton_2->isChecked())
    {
        udalitSNachala();
    }

    pokazatSpisok();
}