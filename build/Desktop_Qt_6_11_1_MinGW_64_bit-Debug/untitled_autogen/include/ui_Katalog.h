/********************************************************************************
** Form generated from reading UI file 'katalog.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KATALOG_H
#define UI_KATALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Katalog
{
public:
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton;
    QLabel *label_4;

    void setupUi(QWidget *Katalog)
    {
        if (Katalog->objectName().isEmpty())
            Katalog->setObjectName("Katalog");
        Katalog->resize(464, 410);
        label = new QLabel(Katalog);
        label->setObjectName("label");
        label->setGeometry(QRect(130, 0, 201, 20));
        label_3 = new QLabel(Katalog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 260, 191, 81));
        pushButton = new QPushButton(Katalog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(190, 350, 93, 29));
        label_4 = new QLabel(Katalog);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(60, 30, 331, 221));
        label_4->setPixmap(QPixmap(QString::fromUtf8("dice.jpg")));
        label_4->setScaledContents(true);

        retranslateUi(Katalog);

        QMetaObject::connectSlotsByName(Katalog);
    } // setupUi

    void retranslateUi(QWidget *Katalog)
    {
        Katalog->setWindowTitle(QCoreApplication::translate("Katalog", "Form", nullptr));
        label->setText(QCoreApplication::translate("Katalog", "\320\235\320\260\321\201\321\202\320\276\320\273\321\214\320\275\320\260\321\217 \320\270\320\263\321\200\320\260 Dice Battle", nullptr));
        label_3->setText(QCoreApplication::translate("Katalog", "\320\246\320\265\320\275\320\260: 2990 \321\200\321\203\320\261\320\273\320\265\320\271\n"
"\n"
"\320\230\320\263\321\200\320\260 \320\264\320\273\321\217 \320\272\320\276\320\274\320\277\320\260\320\275\320\270\320\270 \320\264\321\200\321\203\320\267\320\265\320\271.\n"
"\320\222\320\276\320\267\321\200\320\260\321\201\321\202: 12+", nullptr));
        pushButton->setText(QCoreApplication::translate("Katalog", "\320\227\320\260\320\272\320\260\320\267\320\260\321\202\321\214", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Katalog: public Ui_Katalog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KATALOG_H
