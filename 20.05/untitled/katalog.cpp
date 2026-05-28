#include "katalog.h"
#include "ui_Katalog.h"

Katalog::Katalog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Katalog)
{
    ui->setupUi(this);

    setWindowTitle("Каталог товаров");
}

Katalog::~Katalog()
{
    delete ui;
}