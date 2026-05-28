#include "zakaz.h"
#include "ui_Zakaz.h"
#include <QMessageBox>

Zakaz::Zakaz(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Zakaz)
{
    ui->setupUi(this);

    setWindowTitle("Оформление заказа");
}

Zakaz::~Zakaz()
{
    delete ui;
}

void Zakaz::on_btnOformit_clicked()
{
    QMessageBox::information(this,
                             "Заказ",
                             "Заказ успешно оформлен!");

    close();
}