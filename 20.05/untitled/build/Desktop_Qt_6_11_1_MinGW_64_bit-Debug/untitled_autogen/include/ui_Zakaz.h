/********************************************************************************
** Form generated from reading UI file 'zakaz.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZAKAZ_H
#define UI_ZAKAZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Zakaz
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Zakaz)
    {
        if (Zakaz->objectName().isEmpty())
            Zakaz->setObjectName("Zakaz");
        Zakaz->resize(400, 300);
        pushButton = new QPushButton(Zakaz);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(150, 140, 131, 29));
        label = new QLabel(Zakaz);
        label->setObjectName("label");
        label->setGeometry(QRect(140, 90, 131, 41));
        label_2 = new QLabel(Zakaz);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(140, 40, 141, 20));

        retranslateUi(Zakaz);

        QMetaObject::connectSlotsByName(Zakaz);
    } // setupUi

    void retranslateUi(QWidget *Zakaz)
    {
        Zakaz->setWindowTitle(QCoreApplication::translate("Zakaz", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Zakaz", "\320\236\321\204\320\276\321\200\320\274\320\270\321\202\321\214 \320\267\320\260\320\272\320\260\320\267", nullptr));
        label->setText(QCoreApplication::translate("Zakaz", "\320\242\320\276\320\262\320\260\321\200: Dice Battle\n"
"\320\246\320\265\320\275\320\260: 2990 \321\200\321\203\320\261\320\273\320\265\320\271", nullptr));
        label_2->setText(QCoreApplication::translate("Zakaz", "\320\236\321\204\320\276\321\200\320\274\320\273\320\265\320\275\320\270\320\265 \320\267\320\260\320\272\320\260\320\267\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Zakaz: public Ui_Zakaz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZAKAZ_H
