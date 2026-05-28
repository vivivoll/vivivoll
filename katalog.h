#ifndef KATALOG_H
#define KATALOG_H

#include <QDialog>

namespace Ui {
class Katalog;
}

class Katalog : public QDialog
{
    Q_OBJECT

public:
    explicit Katalog(QWidget *parent = nullptr);
    ~Katalog();

private:
    Ui::Katalog *ui;
};

#endif // KATALOG_H