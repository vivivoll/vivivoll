#include "forgotpasswordwindow.h"
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

ForgotPasswordWindow::ForgotPasswordWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Восстановление пароля");
    setFixedSize(420, 300);
    setWindowFlags(Qt::Dialog | Qt::WindowCloseButtonHint);
    //откл прозрач окон
    setAttribute(Qt::WA_TranslucentBackground, false);
    setAutoFillBackground(true);

    setupUI();
}

void ForgotPasswordWindow::setupUI()
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(40, 40, 40, 40);
    layout->setSpacing(20);


    QLabel *iconLabel = new QLabel("");
    iconLabel->setAlignment(Qt::AlignCenter);
    iconLabel->setStyleSheet("font-size: 48px; background: transparent;");
    layout->addWidget(iconLabel);

    QLabel *textLabel = new QLabel(
        "Для восстановления пароля\n"
        "обратитесь в учебную часть:\n\n"
        "pochta@gmail.com"
        );
    textLabel->setAlignment(Qt::AlignCenter);
    textLabel->setObjectName("infoLabel");
    layout->addWidget(textLabel);

    //кнопка закрытия
    QPushButton *closeBtn = new QPushButton("Закрыть");
    closeBtn->setObjectName("closeButton");
    closeBtn->setFixedSize(140, 40);
    closeBtn->setCursor(Qt::PointingHandCursor);
    layout->addWidget(closeBtn, 0, Qt::AlignCenter);

    //подключение закрытия окна по кнопке
    connect(closeBtn, &QPushButton::clicked, this, &ForgotPasswordWindow::close);

    //стили окна
    setStyleSheet(R"(
        QWidget {
            background-color: white;
        }
        QLabel#infoLabel {
            color: #2E7D32;
            font-size: 16px;
            font-family: Arial;
            font-weight: bold;
        }
        QPushButton#closeButton {
            background-color: #388E3C;
            color: white;
            border-radius: 12px;
            font-size: 14px;
            font-family: Arial;
            border: none;
        }
        QPushButton#closeButton:hover {
            background-color: #2E7D32;
        }
    )");
}