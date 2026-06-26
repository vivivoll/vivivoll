#include "loginwindow.h"
#include "forgotpasswordwindow.h"
#include "studentmainwindow.h"
#include "teachermainwindow.h"
#include "headteachermainwindow.h"
#include "database.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

LoginWindow::LoginWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Журнал посещаемости — Вход");
    setFixedSize(520, 580);
    setupUI();
    applyStyles();
}

void LoginWindow::setupUI()
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(60, 50, 60, 50);
    mainLayout->setSpacing(18);

    //заголовок с иконкой
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setAlignment(Qt::AlignCenter);
    titleLayout->setSpacing(10);

    QLabel *bookIcon = new QLabel();
    QPixmap bookPixmap(":/icons/book.png");
    if (!bookPixmap.isNull()) {
        bookIcon->setPixmap(bookPixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    titleLayout->addWidget(bookIcon);

    QLabel *titleLabel = new QLabel("Журнал посещаемости");
    titleLabel->setObjectName("titleLabel");
    titleLayout->addWidget(titleLabel);

    mainLayout->addLayout(titleLayout);

    QLabel *subTitleLabel = new QLabel("Войдите в систему");
    subTitleLabel->setAlignment(Qt::AlignCenter);
    subTitleLabel->setObjectName("subTitleLabel");
    mainLayout->addWidget(subTitleLabel);

    mainLayout->addSpacing(30);

    QLabel *loginLabel = new QLabel("Логин");
    loginLabel->setObjectName("fieldLabel");
    mainLayout->addWidget(loginLabel);

    loginEdit = new QLineEdit();
    loginEdit->setPlaceholderText("Введите ваш логин");
    loginEdit->setObjectName("inputField");
    loginEdit->setFixedHeight(48);
    mainLayout->addWidget(loginEdit);

    mainLayout->addSpacing(10);

    QLabel *passLabel = new QLabel("Пароль");
    passLabel->setObjectName("fieldLabel");
    mainLayout->addWidget(passLabel);

    passwordEdit = new QLineEdit();
    passwordEdit->setPlaceholderText("Введите ваш пароль");
    passwordEdit->setEchoMode(QLineEdit::Password);
    passwordEdit->setObjectName("inputField");
    passwordEdit->setFixedHeight(48);
    mainLayout->addWidget(passwordEdit);

    mainLayout->addSpacing(8);

    QHBoxLayout *forgotLayout = new QHBoxLayout();
    forgotLayout->addStretch();
    forgotButton = new QPushButton("Забыли пароль?");
    forgotButton->setObjectName("forgotButton");
    forgotButton->setCursor(Qt::PointingHandCursor);
    forgotButton->setFixedHeight(32);
    forgotLayout->addWidget(forgotButton);
    mainLayout->addLayout(forgotLayout);

    mainLayout->addSpacing(20);

    loginButton = new QPushButton("Войти");
    loginButton->setObjectName("loginButton");
    loginButton->setFixedHeight(52);
    loginButton->setCursor(Qt::PointingHandCursor);
    mainLayout->addWidget(loginButton);

    mainLayout->addStretch();

    connect(loginButton, &QPushButton::clicked, this, &LoginWindow::onLoginClicked);
    connect(forgotButton, &QPushButton::clicked, this, &LoginWindow::onForgotPasswordClicked);
    connect(passwordEdit, &QLineEdit::returnPressed, this, &LoginWindow::onLoginClicked);
    connect(loginEdit, &QLineEdit::returnPressed, this, &LoginWindow::onLoginClicked);
}

void LoginWindow::applyStyles()
{
    setStyleSheet(R"(
        QWidget {
            background-color: #F5F5F5;
        }

        QLabel#titleLabel {
            color: #2E7D32;
            font-size: 26px;
            font-weight: bold;
            font-family: Arial;
            background: transparent;
        }

        QLabel#subTitleLabel {
            color: #757575;
            font-size: 15px;
            font-family: Arial;
            background: transparent;
        }

        QLabel#fieldLabel {
            color: #37474F;
            font-size: 14px;
            font-weight: bold;
            font-family: Arial;
            background: transparent;
        }

        QLineEdit#inputField {
            background-color: white;
            color: #263238;
            border: 2px solid #C8E6C9;
            border-radius: 12px;
            padding: 4px 18px;
            font-size: 15px;
            font-family: Arial;
        }

        QLineEdit#inputField:focus {
            border: 2px solid #2E7D32;
            background-color: #FAFAFA;
        }

        QLineEdit#inputField::placeholder {
            color: #B0BEC5;
        }

        QPushButton#loginButton {
            background-color: #2E7D32;
            color: white;
            border-radius: 14px;
            font-size: 18px;
            font-weight: bold;
            font-family: Arial;
            border: none;
            letter-spacing: 1px;
            min-height: 30px;
        }

        QPushButton#loginButton:hover {
            background-color: #388E3C;
        }

        QPushButton#forgotButton {
            background-color: transparent;
            color: #2E7D32;
            border: none;
            font-size: 14px;
            font-family: Arial;
        }

        QPushButton#forgotButton:hover {
            color: #1B5E20;
            text-decoration: underline;
        }
    )");
}

//слоты
void LoginWindow::onLoginClicked()
{
    QString login = loginEdit->text().trimmed();
    QString pass = passwordEdit->text();

    if (login.isEmpty() || pass.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Введите логин и пароль!");
        return;
    }

    QSqlQuery q(Database::getDB());
    q.prepare("SELECT id, full_name, role FROM users WHERE login = :login AND password = :pass");
    q.bindValue(":login", login);
    q.bindValue(":pass", pass);

    if (!q.exec()) {
        QMessageBox::critical(this, "Ошибка", "Ошибка базы данных:\n" + q.lastError().text());
        return;
    }

    if (!q.next()) {
        QMessageBox::warning(this, "Ошибка входа", "Неверный логин или пароль!");
        return;
    }

    int userId = q.value(0).toInt();
    QString fullName = q.value(1).toString();
    int role = q.value(2).toInt();

    QWidget *mainWin = nullptr;

    switch (role) {
    case 0: {
        StudentMainWindow *w = new StudentMainWindow();
        w->setUserId(userId);
        w->setStudentName(fullName);
        mainWin = w;
        break;
    }
    case 2: {
        TeacherMainWindow *w = new TeacherMainWindow();
        w->setUserId(userId);
        w->setTeacherName(fullName);
        mainWin = w;
        break;
    }
    case 3: {
        HeadTeacherMainWindow *w = new HeadTeacherMainWindow();
        w->setUserId(userId);
        w->setHeadTeacherName(fullName);
        mainWin = w;
        break;
    }
    default: {
        QMessageBox::warning(this, "Ошибка", "Неизвестная роль пользователя!");
        return;
    }
    }

    if (mainWin) {
        mainWin->show();
        this->close();
    }
}

void LoginWindow::onForgotPasswordClicked()
{
    ForgotPasswordWindow *w = new ForgotPasswordWindow(this);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->show();
}