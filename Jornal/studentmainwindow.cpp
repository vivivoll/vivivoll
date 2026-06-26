#include "studentmainwindow.h"
#include "loginwindow.h"
#include "database.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QFrame>
#include <QScrollArea>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QHeaderView>
#include <QStatusBar>
#include <QTimer>
#include <QDateTime>
#include <QOverload>
#include <QPixmap>
#include <QIcon>

StudentMainWindow::StudentMainWindow(QWidget *parent)
    : QMainWindow(parent), m_userId(0), m_studentId(0), m_classId(0)
{
    setWindowTitle("Журнал посещаемости — Ученик");
    setMinimumSize(950, 620);
    setupUI();
    applyStyle();
}

StudentMainWindow::~StudentMainWindow() {}

void StudentMainWindow::setupUI()
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    QVBoxLayout *mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(30, 20, 30, 30);
    mainLayout->setSpacing(15);

    //верхняя панель с заголовком и кнопкой выхода
    QHBoxLayout *topLayout = new QHBoxLayout();
    topLayout->setContentsMargins(0, 0, 0, 0);
    topLayout->setSpacing(10);

    //заголовок с иконкой
    QHBoxLayout *titleLayout = new QHBoxLayout();
    titleLayout->setSpacing(10);

    QLabel *bookIcon = new QLabel();
    QPixmap bookPixmap(":/icons/book.png");
    if (!bookPixmap.isNull()) {
        bookIcon->setPixmap(bookPixmap.scaled(32, 32, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }
    titleLayout->addWidget(bookIcon);

    QLabel *titleLabel = new QLabel("Журнал посещаемости");
    titleLabel->setObjectName("mainTitleLabel");
    titleLayout->addWidget(titleLabel);

    topLayout->addLayout(titleLayout);

    topLayout->addStretch();

    //имя пользователя
    nameLabel = new QLabel("Ученик");
    nameLabel->setObjectName("userNameLabel");
    topLayout->addWidget(nameLabel);

    //кнопка выхода с иконкой
    QPushButton *btnLogout = new QPushButton("Выйти");
    btnLogout->setObjectName("logoutButton");
    btnLogout->setCursor(Qt::PointingHandCursor);
    connect(btnLogout, &QPushButton::clicked, this, &StudentMainWindow::on_btnLogout_clicked);
    topLayout->addWidget(btnLogout);

    mainLayout->addLayout(topLayout);

    //кнопки меню
    QHBoxLayout *menuLayout = new QHBoxLayout();
    menuLayout->setContentsMargins(0, 5, 0, 15);
    menuLayout->setSpacing(8);

    QString menuBtnStyle = R"(
    QPushButton {
        background-color: #2E7D32;
        color: white;
        border-radius: 10px;
        font-size: 14px;
        padding: 8px 20px;
        border: none;
        min-height: 20px;
    }
    QPushButton:hover { background-color: #388E3C; }
    QPushButton:checked {
        background-color: #1B5E20;
        border: 2px solid white;
    }
)";

    auto createMenuButton = [&](const QString &text, const QString &iconPath, const char *slot) {
        QPushButton *btn = new QPushButton(text);
        QPixmap pixmap(iconPath);
        if (!pixmap.isNull()) {
            QIcon icon(pixmap.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
            btn->setIcon(icon);
            btn->setIconSize(QSize(24, 24));
        }
        btn->setStyleSheet(menuBtnStyle);
        btn->setCursor(Qt::PointingHandCursor);
        btn->setCheckable(true);
        connect(btn, SIGNAL(clicked()), this, slot);
        menuLayout->addWidget(btn);
        return btn;
    };

    btnSchedule = createMenuButton("Расписание", ":/icons/schedule.png", SLOT(on_btnSchedule_clicked()));
    QPushButton *btnAttendance = createMenuButton("Посещаемость", ":/icons/attendance.png", SLOT(on_btnAttendance_clicked()));
    QPushButton *btnStats = createMenuButton("Статистика", ":/icons/stats.png", SLOT(on_btnStats_clicked()));

    menuLayout->addStretch();

    //информация о классе
    classLabel = new QLabel("Класс");
    classLabel->setObjectName("classLabel");
    menuLayout->addWidget(classLabel);

    mainLayout->addLayout(menuLayout);

    //контент
    QStackedWidget *stackedWidget = new QStackedWidget();
    stackedWidget->setObjectName("stackedWidget");

    //виджет расписания
    scheduleWidget = new QWidget();
    QVBoxLayout *scheduleLayout = new QVBoxLayout(scheduleWidget);
    scheduleLayout->setContentsMargins(0, 0, 0, 0);
    scheduleLayout->setSpacing(12);

    QHBoxLayout *scheduleFilterLayout = new QHBoxLayout();
    QLabel *scheduleFilterLabel = new QLabel("Показать:");
    scheduleFilterLabel->setObjectName("filterLabel");
    scheduleFilter = new QComboBox();
    scheduleFilter->addItem("Сегодня", "today");
    scheduleFilter->addItem("Завтра", "tomorrow");
    scheduleFilter->addItem("Неделя", "week");
    scheduleFilter->setObjectName("filterCombo");
    scheduleFilterLayout->addWidget(scheduleFilterLabel);
    scheduleFilterLayout->addWidget(scheduleFilter);
    scheduleFilterLayout->addStretch();
    scheduleLayout->addLayout(scheduleFilterLayout);

    scheduleTable = new QTableWidget();
    scheduleTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    scheduleTable->setAlternatingRowColors(true);
    scheduleTable->verticalHeader()->setVisible(false);
    scheduleTable->setObjectName("contentTable");
    scheduleLayout->addWidget(scheduleTable);

    stackedWidget->addWidget(scheduleWidget);

    //виджет посещаемости
    attendanceWidget = new QWidget();
    QVBoxLayout *attendanceLayout = new QVBoxLayout(attendanceWidget);
    attendanceLayout->setContentsMargins(0, 0, 0, 0);
    attendanceLayout->setSpacing(12);

    QLabel *attendanceTitle = new QLabel("Моя посещаемость");
    attendanceTitle->setObjectName("sectionTitle");
    attendanceLayout->addWidget(attendanceTitle);

    attendanceTable = new QTableWidget();
    attendanceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    attendanceTable->setAlternatingRowColors(true);
    attendanceTable->verticalHeader()->setVisible(false);
    attendanceTable->setObjectName("contentTable");
    attendanceLayout->addWidget(attendanceTable);

    stackedWidget->addWidget(attendanceWidget);

    //виджет статистики
    statsWidget = new QWidget();
    QVBoxLayout *statsLayout = new QVBoxLayout(statsWidget);
    statsLayout->setContentsMargins(0, 0, 0, 0);
    statsLayout->setSpacing(12);

    QHBoxLayout *statsFilterLayout = new QHBoxLayout();
    QLabel *statsFilterLabel = new QLabel("Статистика:");
    statsFilterLabel->setObjectName("filterLabel");
    statsFilter = new QComboBox();
    statsFilter->addItem("Общая", 0);
    statsFilter->addItem("По предметам", 1);
    statsFilter->setObjectName("filterCombo");
    statsFilterLayout->addWidget(statsFilterLabel);
    statsFilterLayout->addWidget(statsFilter);
    statsFilterLayout->addStretch();
    statsLayout->addLayout(statsFilterLayout);

    statsTable = new QTableWidget();
    statsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    statsTable->setAlternatingRowColors(true);
    statsTable->verticalHeader()->setVisible(false);
    statsTable->setObjectName("contentTable");
    statsLayout->addWidget(statsTable);

    stackedWidget->addWidget(statsWidget);

    //по умолчанию показываем расписание
    stackedWidget->setCurrentWidget(scheduleWidget);
    btnSchedule->setChecked(true);
    currentActiveButton = btnSchedule;

    mainLayout->addWidget(stackedWidget);

    //статус бар
    QStatusBar *statusBar = new QStatusBar(this);
    setStatusBar(statusBar);

    QLabel *timeLabel = new QLabel();
    timeLabel->setObjectName("timeLabel");
    statusBar->addPermanentWidget(timeLabel);

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [timeLabel]() {
        timeLabel->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));
    });
    timer->start(1000);
    timeLabel->setText(QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss"));

    //подключаем сигналы
    connect(scheduleFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &StudentMainWindow::onScheduleFilterChanged);
    connect(statsFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &StudentMainWindow::onStatsFilterChanged);
}

void StudentMainWindow::applyStyle()
{
    setStyleSheet(R"(
        QMainWindow {
            background-color: #F5F5F5;
        }

        QLabel#mainTitleLabel {
            color: #2E7D32;
            font-size: 22px;
            font-weight: bold;
            font-family: Arial;
        }

        QLabel#userNameLabel {
            color: #2E7D32;
            font-size: 14px;
            font-weight: bold;
            font-family: Arial;
            padding: 4px 12px;
            background-color: #E8F5E9;
            border-radius: 8px;
        }

        QLabel#classLabel {
            color: #757575;
            font-size: 13px;
            font-family: Arial;
            padding: 4px 12px;
            background-color: white;
            border-radius: 8px;
        }

        QLabel#filterLabel {
            color: #37474F;
            font-size: 13px;
            font-weight: bold;
            font-family: Arial;
        }

        QLabel#sectionTitle {
            color: #2E7D32;
            font-size: 16px;
            font-weight: bold;
            font-family: Arial;
        }

        QPushButton#logoutButton {
            background-color: #D32F2F;
            color: white;
            border-radius: 8px;
            font-size: 13px;
            padding: 6px 18px;
            border: none;
            font-weight: bold;
            min-height: 20px;
        }

        QPushButton#logoutButton:hover {
            background-color: #B71C1C;
        }

        QComboBox#filterCombo {
            background-color: white;
            color: black;
            border-radius: 8px;
            font-size: 13px;
            padding: 5px 12px;
            border: 1px solid #C8E6C9;
            min-width: 120px;
        }

        QTableWidget#contentTable {
            background-color: white;
            border-radius: 12px;
            border: none;
        }

        QHeaderView::section {
            background-color: #2E7D32;
            color: white;
            font-weight: bold;
            padding: 8px;
        }

        QTableWidget::item {
            color: black;
            padding: 6px;
        }

        QTableWidget::item:selected {
            background-color: #E8F5E9;
            color: black;
        }

        QLabel#timeLabel {
            color: #757575;
            font-size: 12px;
            padding: 4px 8px;
        }

        QStackedWidget#stackedWidget {
            background-color: transparent;
        }
    )");
}

void StudentMainWindow::setStudentName(const QString &name)
{
    if (nameLabel) nameLabel->setText(name);
}

void StudentMainWindow::setUserId(int id)
{
    m_userId = id;

    QSqlQuery q(Database::getDB());
    q.prepare("SELECT id, class_id FROM students WHERE user_id = ?");
    q.addBindValue(id);

    if (q.exec() && q.next()) {
        m_studentId = q.value(0).toInt();
        m_classId = q.value(1).toInt();

        QSqlQuery classQ(Database::getDB());
        classQ.prepare("SELECT name FROM classes WHERE id = ?");
        classQ.addBindValue(m_classId);
        if (classQ.exec() && classQ.next()) {
            classLabel->setText(classQ.value(0).toString());
        }

        loadSchedule("today");
        loadAttendance();
        loadStatistics(0);
    } else {
        qDebug() << "Не найден student_id для user_id =" << id;
    }
}

void StudentMainWindow::loadSchedule(const QString &filter)
{
    scheduleTable->clear();
    scheduleTable->setRowCount(0);

    QStringList headers = {"День", "№", "Предмет", "Учитель", "Время"};
    scheduleTable->setColumnCount(headers.size());
    scheduleTable->setHorizontalHeaderLabels(headers);
    scheduleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QDate currentDate = QDate::currentDate();
    QSqlQuery q(Database::getDB());

    if (filter == "today") {
        QString date = currentDate.toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.class_id = ? AND s.date = ?
            ORDER BY s.lesson_number
        )");
        q.addBindValue(m_classId);
        q.addBindValue(date);
    } else if (filter == "tomorrow") {
        QString date = currentDate.addDays(1).toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.class_id = ? AND s.date = ?
            ORDER BY s.lesson_number
        )");
        q.addBindValue(m_classId);
        q.addBindValue(date);
    } else {
        QString startDate = currentDate.toString("yyyy-MM-dd");
        QString endDate = currentDate.addDays(6).toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.class_id = ? AND s.date BETWEEN ? AND ?
            ORDER BY s.date, s.lesson_number
        )");
        q.addBindValue(m_classId);
        q.addBindValue(startDate);
        q.addBindValue(endDate);
    }

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки расписания:" << q.lastError().text();
        return;
    }

    int row = 0;
    while (q.next()) {
        scheduleTable->insertRow(row);
        scheduleTable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        scheduleTable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
        scheduleTable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        scheduleTable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));
        scheduleTable->setItem(row, 4, new QTableWidgetItem(q.value(4).toString() + " - " + q.value(5).toString()));

        for (int col = 0; col < 5; ++col) {
            if (scheduleTable->item(row, col)) {
                scheduleTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
            }
        }
        row++;
    }

    for (int r = 0; r < scheduleTable->rowCount(); ++r) {
        scheduleTable->setRowHeight(r, 30);
    }

    if (row == 0) {
        scheduleTable->insertRow(0);
        auto *empty = new QTableWidgetItem("Нет уроков");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        scheduleTable->setSpan(0, 0, 1, 5);
        scheduleTable->setItem(0, 0, empty);
        scheduleTable->setRowHeight(0, 30);
    }
}

void StudentMainWindow::loadAttendance()
{
    attendanceTable->clear();
    attendanceTable->setRowCount(0);

    QStringList headers = {"Дата", "Предмет", "Статус", "Причина"};
    attendanceTable->setColumnCount(headers.size());
    attendanceTable->setHorizontalHeaderLabels(headers);
    attendanceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT s.date, sub.name, ast.name, a.reason
        FROM attendance a
        JOIN schedule s ON s.id = a.schedule_id
        JOIN subjects sub ON sub.id = s.subject_id
        JOIN attendance_statuses ast ON ast.id = a.status
        WHERE a.student_id = ?
        ORDER BY s.date DESC, s.lesson_number
    )");
    q.addBindValue(m_studentId);

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки посещаемости:" << q.lastError().text();
        return;
    }

    int row = 0;
    while (q.next()) {
        attendanceTable->insertRow(row);
        attendanceTable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        attendanceTable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
        attendanceTable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        attendanceTable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString().isEmpty() ? "-" : q.value(3).toString()));

        for (int col = 0; col < 4; ++col) {
            if (attendanceTable->item(row, col)) {
                attendanceTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
            }
        }
        row++;
    }

    for (int r = 0; r < attendanceTable->rowCount(); ++r) {
        attendanceTable->setRowHeight(r, 30);
    }

    if (row == 0) {
        attendanceTable->insertRow(0);
        auto *empty = new QTableWidgetItem("Нет данных о посещаемости");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        attendanceTable->setSpan(0, 0, 1, 4);
        attendanceTable->setItem(0, 0, empty);
        attendanceTable->setRowHeight(0, 30);
    }
}

void StudentMainWindow::loadStatistics(int filterType)
{
    statsTable->clear();
    statsTable->setRowCount(0);

    if (filterType == 0) {
        QStringList headers = {"Показатель", "Значение"};
        statsTable->setColumnCount(headers.size());
        statsTable->setHorizontalHeaderLabels(headers);
        statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());
        q.prepare(R"(
            SELECT
                COUNT(DISTINCT s.id) as total_lessons,
                SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) as present,
                SUM(CASE WHEN a.status = 2 THEN 1 ELSE 0 END) as absent,
                SUM(CASE WHEN a.status = 3 THEN 1 ELSE 0 END) as late,
                ROUND(CAST(SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) AS REAL) /
                      COUNT(DISTINCT s.id) * 100, 1) as percent
            FROM attendance a
            JOIN schedule s ON s.id = a.schedule_id
            WHERE a.student_id = ?
        )");
        q.addBindValue(m_studentId);

        if (!q.exec() || !q.next()) {
            statsTable->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 2);
            statsTable->setItem(0, 0, empty);
            return;
        }

        int total = q.value(0).toInt();
        int present = q.value(1).toInt();
        int absent = q.value(2).toInt();
        int late = q.value(3).toInt();
        double percent = q.value(4).toDouble();

        QMap<QString, QString> data = {
            {"Всего уроков", QString::number(total)},
            {"Присутствовал", QString::number(present)},
            {"Отсутствовал", QString::number(absent)},
            {"Опоздал", QString::number(late)},
            {"Процент посещаемости", QString::number(percent, 'f', 1) + "%"}
        };

        int row = 0;
        for (auto it = data.begin(); it != data.end(); ++it) {
            statsTable->insertRow(row);
            statsTable->setItem(row, 0, new QTableWidgetItem(it.key()));
            statsTable->setItem(row, 1, new QTableWidgetItem(it.value()));
            statsTable->item(row, 0)->setTextAlignment(Qt::AlignCenter);
            statsTable->item(row, 1)->setTextAlignment(Qt::AlignCenter);

            if (it.key() == "Процент посещаемости") {
                QFont f = statsTable->item(row, 1)->font();
                f.setBold(true);
                statsTable->item(row, 1)->setFont(f);

                if (percent >= 80) {
                    statsTable->item(row, 1)->setForeground(QColor("#2E7D32"));
                } else if (percent >= 60) {
                    statsTable->item(row, 1)->setForeground(QColor("#F57F17"));
                } else {
                    statsTable->item(row, 1)->setForeground(QColor("#C62828"));
                }
            }
            row++;
        }

        for (int r = 0; r < statsTable->rowCount(); ++r) {
            statsTable->setRowHeight(r, 30);
        }

    } else {
        QStringList headers = {"Предмет", "Всего", "Присутствовал", "Отсутствовал", "%"};
        statsTable->setColumnCount(headers.size());
        statsTable->setHorizontalHeaderLabels(headers);
        statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());
        q.prepare(R"(
            SELECT
                sub.name,
                COUNT(DISTINCT s.id) as total,
                SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) as present,
                SUM(CASE WHEN a.status = 2 THEN 1 ELSE 0 END) as absent,
                ROUND(CAST(SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) AS REAL) /
                      COUNT(DISTINCT s.id) * 100, 1) as percent
            FROM attendance a
            JOIN schedule s ON s.id = a.schedule_id
            JOIN subjects sub ON sub.id = s.subject_id
            WHERE a.student_id = ?
            GROUP BY sub.id, sub.name
            ORDER BY sub.name
        )");
        q.addBindValue(m_studentId);

        if (!q.exec()) {
            statsTable->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 5);
            statsTable->setItem(0, 0, empty);
            return;
        }

        int row = 0;
        while (q.next()) {
            statsTable->insertRow(row);
            statsTable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
            statsTable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
            statsTable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
            statsTable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));
            statsTable->setItem(row, 4, new QTableWidgetItem(QString::number(q.value(4).toDouble(), 'f', 1) + "%"));

            for (int col = 0; col < 5; ++col) {
                if (statsTable->item(row, col)) {
                    statsTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
                }
            }

            double percent = q.value(4).toDouble();
            QTableWidgetItem *percentItem = statsTable->item(row, 4);
            if (percent >= 80) {
                percentItem->setForeground(QColor("#2E7D32"));
            } else if (percent >= 60) {
                percentItem->setForeground(QColor("#F57F17"));
            } else {
                percentItem->setForeground(QColor("#C62828"));
            }

            row++;
        }

        for (int r = 0; r < statsTable->rowCount(); ++r) {
            statsTable->setRowHeight(r, 30);
        }

        if (row == 0) {
            statsTable->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет данных по предметам");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 5);
            statsTable->setItem(0, 0, empty);
            statsTable->setRowHeight(0, 30);
        }
    }
}

//слоты
void StudentMainWindow::on_btnSchedule_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    btnSchedule->setChecked(true);
    currentActiveButton = btnSchedule;

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(scheduleWidget);
    }
    loadSchedule(scheduleFilter->currentData().toString());
}

void StudentMainWindow::on_btnAttendance_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        btn->setChecked(true);
        currentActiveButton = btn;
    }

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(attendanceWidget);
    }
    loadAttendance();
}

void StudentMainWindow::on_btnStats_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    if (btn) {
        btn->setChecked(true);
        currentActiveButton = btn;
    }

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(statsWidget);
    }
    loadStatistics(statsFilter->currentData().toInt());
}

void StudentMainWindow::onScheduleFilterChanged(int index)
{
    if (index < 0) return;
    QString filter = scheduleFilter->currentData().toString();
    loadSchedule(filter);
}

void StudentMainWindow::onStatsFilterChanged(int index)
{
    if (index < 0) return;
    int filterType = statsFilter->currentData().toInt();
    loadStatistics(filterType);
}

void StudentMainWindow::on_btnLogout_clicked()
{
    LoginWindow *login = new LoginWindow();
    login->show();
    this->close();
}