#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QTextStream>
#include <QMessageBox>

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
    QFile fileF("f.txt");

    if(!fileF.exists())
    {
        QMessageBox::warning(this,
                             "Ошибка",
                             "Файл f.txt не найден");
        return;
    }

    if(!fileF.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this,
                             "Ошибка",
                             "Невозможно открыть файл f.txt");
        return;
    }

    QTextStream in(&fileF);

    QString text = in.readAll();

    fileF.close();

    ui->textEdit->setText(text);

    QStringList chisla =
        text.split(" ", Qt::SkipEmptyParts);

    QFile fileG("g.txt");

    if(!fileG.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,
                             "Ошибка",
                             "Невозможно создать файл g.txt");
        return;
    }

    QTextStream out(&fileG);

    ui->textEdit_2->clear();

    for(int i = 0; i < chisla.size(); i += 5)
    {
        int maksimum = chisla[i].toInt();

        for(int j = i;
             j < i + 5 && j < chisla.size();
             j++)
        {
            if(chisla[j].toInt() > maksimum)
            {
                maksimum = chisla[j].toInt();
            }
        }

        out << maksimum << " ";

        ui->textEdit_2->append(
            QString::number(maksimum));
    }

    fileG.close();

    QMessageBox::information(this,
                             "Готово",
                             "Файл успешно обработан");
}