#include "schedulewindow.h"
#include "database.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QHeaderView>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QColor>
#include <QDebug>

ScheduleWindow::ScheduleWindow(int userId, QWidget *parent)
    : QWidget(parent), m_userId(userId)
{
    setWindowTitle("Расписание");
    setMinimumSize(700, 480);
    setupUI();
    showToday();
}

void ScheduleWindow::setupUI()
{
    setStyleSheet("QWidget { background-color: #F5F5F5; }");

    QVBoxLayout *main = new QVBoxLayout(this);
    main->setContentsMargins(24, 24, 24, 24);
    main->setSpacing(16);

    //заголовок
    QLabel *title = new QLabel("Расписание");
    title->setStyleSheet("color: #2E7D32; font-size: 20px; font-weight: bold;");
    main->addWidget(title);

    //кнопки переключения
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(10);

    btnToday = new QPushButton("Текущий день");
    btnWeek = new QPushButton("За неделю");

    QString btnStyle = R"(
    QPushButton {
        background-color: #2E7D32;
        color: white;
        border-radius: 12px;
        font-size: 14px;
        padding: 10px;
        text-align: left;
        border: none;
    }
    QPushButton:hover { background-color: #388E3C; }
    QPushButton:pressed { background-color: #1B5E20; }
    QPushButton:checked {
        background-color: #1B5E20;
        border: 2px solid white;
    }
)";

    btnToday->setStyleSheet(btnStyle);
    btnWeek->setStyleSheet(btnStyle);
    btnToday->setCheckable(true);
    btnWeek->setCheckable(true);
    btnToday->setChecked(true);
    btnToday->setCursor(Qt::PointingHandCursor);
    btnWeek->setCursor(Qt::PointingHandCursor);

    btnLayout->addWidget(btnToday);
    btnLayout->addWidget(btnWeek);
    btnLayout->addStretch();
    main->addLayout(btnLayout);

    //таблица расписания
    table = new QTableWidget();
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setAlternatingRowColors(true);
    table->verticalHeader()->setVisible(false);

    //стили таблицы
    table->setStyleSheet(R"(
    QTableWidget {
        background-color: white;
        border-radius: 12px;
    }
    QHeaderView::section {
        background-color: #2E7D32;
        color: white;
        font-weight: bold;
    }
    QTableWidget::item {
        color: black;
        padding: 6px;
    }
    QTableWidget::item:selected {
        background-color: #C8E6C9;
        color: black;
    }
)");

    main->addWidget(table);

    //подключение кнопок
    connect(btnToday, &QPushButton::clicked, this, &ScheduleWindow::showToday);
    connect(btnWeek, &QPushButton::clicked, this, &ScheduleWindow::showWeek);
}

void ScheduleWindow::showToday()
{
    btnToday->setChecked(true);
    btnWeek->setChecked(false);
    loadSchedule("today");
}

void ScheduleWindow::showWeek()
{
    btnWeek->setChecked(true);
    btnToday->setChecked(false);
    loadSchedule("week");
}

//основной метод загрузки расписания
void ScheduleWindow::loadSchedule(const QString &filter)
{
    table->clear();
    table->setRowCount(0);

    static const QStringList dayNames =
        {
            "",
            "Понедельник",
            "Вторник",
            "Среда",
            "Четверг",
            "Пятница"
        };

    if (filter == "today")
    {
        int today = QDate::currentDate().dayOfWeek();

        table->setColumnCount(4);
        table->setHorizontalHeaderLabels(
            {"№", "Предмет", "Учитель", "Время"});
        table->horizontalHeader()
            ->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());

        q.prepare(R"(
            SELECT
                sc.lesson_number,
                su.name,
                u.full_name,
                sc.start_time,
                sc.end_time
            FROM schedule sc
            JOIN subjects su
                ON su.id = sc.subject_id
            JOIN teachers t
                ON t.id = sc.teacher_id
            JOIN users u
                ON u.id = t.user_id
            JOIN students st
                ON st.class_id = sc.class_id
            WHERE st.user_id = ?
              AND sc.day_of_week = ?
            ORDER BY sc.lesson_number
        )");

        q.addBindValue(m_userId);
        q.addBindValue(today);

        if (!q.exec())
        {
            qDebug() << "Ошибка расписания:";
            qDebug() << q.lastError().text();
            return;
        }

        int row = 0;

        while (q.next())
        {
            table->insertRow(row);

            table->setItem(row, 0,
                           new QTableWidgetItem(
                               q.value(0).toString()));

            table->setItem(row, 1,
                           new QTableWidgetItem(
                               q.value(1).toString()));

            table->setItem(row, 2,
                           new QTableWidgetItem(
                               q.value(2).toString()));

            table->setItem(row, 3,
                           new QTableWidgetItem(
                               q.value(3).toString()
                               + " - "
                               + q.value(4).toString()));

            row++;
        }

        qDebug() << "Найдено уроков:" << row;

        //если на сегодня нет уроков
        if (row == 0)
        {
            table->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет уроков на сегодня");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            table->setSpan(0, 0, 1, 4);
            table->setItem(0, 0, empty);
        }
    }
    else
    {
        table->setColumnCount(5);

        table->setHorizontalHeaderLabels(
            {"День", "№", "Предмет", "Учитель", "Время"});

        table->horizontalHeader()
            ->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());

        q.prepare(R"(
            SELECT
                sc.day_of_week,
                sc.lesson_number,
                su.name,
                u.full_name,
                sc.start_time,
                sc.end_time
            FROM schedule sc
            JOIN subjects su
                ON su.id = sc.subject_id
            JOIN teachers t
                ON t.id = sc.teacher_id
            JOIN users u
                ON u.id = t.user_id
            JOIN students st
                ON st.class_id = sc.class_id
            WHERE st.user_id = ?
            ORDER BY
                sc.day_of_week,
                sc.lesson_number
        )");

        q.addBindValue(m_userId);

        if (!q.exec())
        {
            qDebug() << "Ошибка расписания:";
            qDebug() << q.lastError().text();
            return;
        }

        int row = 0;

        while (q.next())
        {
            table->insertRow(row);

            int day = q.value(0).toInt();

            table->setItem(row, 0,
                           new QTableWidgetItem(dayNames.value(day)));

            table->setItem(row, 1,
                           new QTableWidgetItem(
                               q.value(1).toString()));

            table->setItem(row, 2,
                           new QTableWidgetItem(
                               q.value(2).toString()));

            table->setItem(row, 3,
                           new QTableWidgetItem(
                               q.value(3).toString()));

            table->setItem(row, 4,
                           new QTableWidgetItem(
                               q.value(4).toString()
                               + " - "
                               + q.value(5).toString()));

            row++;
        }

        qDebug() << "Найдено уроков за неделю:" << row;

        if (row == 0)
        {
            table->insertRow(0);
            auto *empty = new QTableWidgetItem("Расписание не найдено");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            table->setSpan(0, 0, 1, 5);
            table->setItem(0, 0, empty);
        }
    }
}