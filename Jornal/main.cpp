#include <QApplication>
#include <QFont>
#include "loginwindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFont font("Arial", 10);
    a.setFont(font);

    Database::instance().init();

    //запуск окна для входа
    LoginWindow w;
    w.show();

    return a.exec();
}