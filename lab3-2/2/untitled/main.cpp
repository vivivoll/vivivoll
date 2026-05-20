#include <QCoreApplication>
#include <QDebug>
#include <ctime>
#include <cstdlib>

struct Element
{
    int znachenie;
    Element* sled;
};

void dobavit(Element*& nachalo, int chislo)
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

void pokazat(Element* nachalo)
{
    Element* tek = nachalo;

    while(tek != nullptr)
    {
        qDebug() << tek->znachenie;

        tek = tek->sled;
    }
}

void ochistit(Element*& nachalo)
{
    while(nachalo != nullptr)
    {
        Element* vrem = nachalo;

        nachalo = nachalo->sled;

        delete vrem;
    }
}

void zamenitSpisok(Element*& perviy, Element* vtoroy)
{
    ochistit(perviy);

    Element* tek = vtoroy;

    while(tek != nullptr)
    {
        dobavit(perviy, tek->znachenie);

        tek = tek->sled;
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    srand(time(0));

    Element* spisok1 = nullptr;
    Element* spisok2 = nullptr;

    for(int i = 0; i < 5; i++)
    {
        dobavit(spisok1, rand() % 50);
        dobavit(spisok2, rand() % 50);
    }

    qDebug() << "Первый список:";
    pokazat(spisok1);

    qDebug() << "Второй список:";
    pokazat(spisok2);

    zamenitSpisok(spisok1, spisok2);

    qDebug() << "Первый список после замены:";
    pokazat(spisok1);

    return a.exec();
}