#include "headteachermainwindow.h"
#include "loginwindow.h"
#include "database.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFrame>
#include <QScrollArea>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QDate>
#include <QDebug>
#include <QHeaderView>
#include <QOverload>
#include <QFileDialog>
#include <QTextStream>
#include <QFile>
#include <QStatusBar>
#include <QTimer>
#include <QDateTime>
#include <QPixmap>
#include <QIcon>

HeadTeacherMainWindow::HeadTeacherMainWindow(QWidget *parent)
    : QMainWindow(parent), m_userId(0), m_headTeacherId(0)
{
    setWindowTitle("Журнал посещаемости — Завуч");
    setMinimumSize(950, 620);
    setupUI();
    applyStyle();
}

void HeadTeacherMainWindow::setupUI()
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

    nameLabel = new QLabel("Завуч");
    nameLabel->setObjectName("userNameLabel");
    topLayout->addWidget(nameLabel);

    QPushButton *btnLogout = new QPushButton("Выйти");
    btnLogout->setObjectName("logoutButton");
    btnLogout->setCursor(Qt::PointingHandCursor);
    connect(btnLogout, &QPushButton::clicked, this, &HeadTeacherMainWindow::on_btnLogout_clicked);
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
    btnAttendance = createMenuButton("Посещаемость", ":/icons/attendance.png", SLOT(on_btnAttendance_clicked()));
    btnStats = createMenuButton("Статистика", ":/icons/stats.png", SLOT(on_btnStats_clicked()));

    // Кнопка отчета
    btnReport = new QPushButton("Сформировать отчет");
    QPixmap reportPixmap(":/icons/report.png");
    if (!reportPixmap.isNull()) {
        QIcon icon(reportPixmap.scaled(24, 24, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        btnReport->setIcon(icon);
        btnReport->setIconSize(QSize(24, 24));
    }
    btnReport->setObjectName("reportButton");
    btnReport->setCursor(Qt::PointingHandCursor);
    connect(btnReport, &QPushButton::clicked, this, &HeadTeacherMainWindow::on_btnReport_clicked);
    menuLayout->addWidget(btnReport);

    menuLayout->addStretch();

    welcomeLabel = new QLabel("Добро пожаловать!");
    welcomeLabel->setObjectName("welcomeLabel");
    menuLayout->addWidget(welcomeLabel);

    mainLayout->addLayout(menuLayout);

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

    QHBoxLayout *attendanceSelectLayout = new QHBoxLayout();
    attendanceSelectLayout->setSpacing(15);

    QLabel *classLabel = new QLabel("Класс:");
    classLabel->setObjectName("filterLabel");
    classCombo = new QComboBox();
    classCombo->setObjectName("filterCombo");
    classCombo->setMinimumWidth(150);

    QLabel *subjectLabel = new QLabel("Предмет:");
    subjectLabel->setObjectName("filterLabel");
    subjectCombo = new QComboBox();
    subjectCombo->setObjectName("filterCombo");
    subjectCombo->setMinimumWidth(150);

    QLabel *dateLabel = new QLabel("Дата:");
    dateLabel->setObjectName("filterLabel");
    dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    dateEdit->setObjectName("dateEdit");

    attendanceSelectLayout->addWidget(classLabel);
    attendanceSelectLayout->addWidget(classCombo);
    attendanceSelectLayout->addWidget(subjectLabel);
    attendanceSelectLayout->addWidget(subjectCombo);
    attendanceSelectLayout->addWidget(dateLabel);
    attendanceSelectLayout->addWidget(dateEdit);
    attendanceSelectLayout->addStretch();

    attendanceLayout->addLayout(attendanceSelectLayout);

    attendanceTable = new QTableWidget();
    attendanceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    attendanceTable->setAlternatingRowColors(true);
    attendanceTable->verticalHeader()->setVisible(false);
    attendanceTable->setObjectName("contentTable");
    attendanceLayout->addWidget(attendanceTable);

    QHBoxLayout *attendanceBtnLayout = new QHBoxLayout();
    btnSave = new QPushButton("Сохранить посещаемость");
    QPixmap savePixmap(":/icons/save.png");
    if (!savePixmap.isNull()) {
        QIcon icon(savePixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(20, 20));
    }
    btnSave->setObjectName("actionButton");
    btnSave->setCursor(Qt::PointingHandCursor);
    attendanceBtnLayout->addWidget(btnSave);
    attendanceBtnLayout->addStretch();
    attendanceLayout->addLayout(attendanceBtnLayout);

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
    statsFilter->addItem("По школе", 0);
    statsFilter->addItem("По классам", 1);
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

    //по умолчанию показ расписания
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

    //сигналы
    connect(scheduleFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HeadTeacherMainWindow::onScheduleFilterChanged);
    connect(classCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HeadTeacherMainWindow::onClassChanged);
    connect(subjectCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HeadTeacherMainWindow::onSubjectChanged);
    connect(dateEdit, &QDateEdit::dateChanged,
            this, &HeadTeacherMainWindow::onDateChanged);
    connect(btnSave, &QPushButton::clicked,
            this, &HeadTeacherMainWindow::onSaveAttendance);
    connect(statsFilter, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &HeadTeacherMainWindow::onStatsFilterChanged);
}

void HeadTeacherMainWindow::applyStyle()
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

        QLabel#welcomeLabel {
            color: #757575;
            font-size: 13px;
            font-family: Arial;
            padding: 4px 12px;
        }

        QLabel#filterLabel {
            color: #37474F;
            font-size: 13px;
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

        QPushButton#actionButton {
            background-color: #2E7D32;
            color: white;
            border-radius: 8px;
            font-size: 13px;
            padding: 8px 24px;
            border: none;
            font-weight: bold;
            min-height: 20px;
        }

        QPushButton#actionButton:hover {
            background-color: #388E3C;
        }

        QPushButton#reportButton {
            background-color: #2E7D32;
            color: white;
            border-radius: 8px;
            font-size: 13px;
            padding: 8px 18px;
            border: none;
            font-weight: bold;
            min-height: 20px;
        }

        QPushButton#reportButton:hover {
            background-color: #388E3C;
        }

        QComboBox#filterCombo {
            background-color: white;
            color: black;
            border-radius: 8px;
            font-size: 13px;
            padding: 5px 12px;
            border: 1px solid #C8E6C9;
            min-width: 140px;
        }

        QDateEdit#dateEdit {
            background-color: white;
            color: black;
            border-radius: 8px;
            font-size: 13px;
            padding: 5px 12px;
            border: 1px solid #C8E6C9;
            min-width: 130px;
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

        QComboBox {
            background-color: white;
            color: black;
            border-radius: 6px;
            padding: 4px 8px;
            border: 1px solid #C8E6C9;
        }

        QLineEdit {
            background-color: white;
            color: black;
            border-radius: 6px;
            padding: 4px 8px;
            border: 1px solid #C8E6C9;
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

//загрузка данных
void HeadTeacherMainWindow::setHeadTeacherName(const QString &name)
{
    if (nameLabel) nameLabel->setText(name);
    if (welcomeLabel) {
        QString firstName = name.split(" ").first();
        welcomeLabel->setText("Добро пожаловать, " + firstName + "!");
    }
}

void HeadTeacherMainWindow::setUserId(int id)
{
    m_userId = id;

    QSqlQuery q(Database::getDB());
    q.prepare("SELECT id FROM headteachers WHERE user_id = ?");
    q.addBindValue(id);

    if (q.exec() && q.next()) {
        m_headTeacherId = q.value(0).toInt();
    } else {
        return;
    }

    loadClasses();
    loadSchedule("today");
    loadStatistics(0);

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(scheduleWidget);
    }
}

void HeadTeacherMainWindow::loadClasses()
{
    if (!classCombo) return;
    classCombo->blockSignals(true);
    classCombo->clear();
    classCombo->addItem("Выберите класс", 0);

    QSqlQuery q(Database::getDB());
    q.prepare("SELECT id, name FROM classes ORDER BY name");

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки классов:" << q.lastError().text();
        classCombo->blockSignals(false);
        return;
    }

    while (q.next()) {
        classCombo->addItem(q.value(1).toString(), q.value(0).toInt());
    }

    classCombo->blockSignals(false);
}

void HeadTeacherMainWindow::loadSubjects(int classId)
{
    if (!subjectCombo) return;
    subjectCombo->blockSignals(true);
    subjectCombo->clear();
    subjectCombo->addItem("Все предметы", 0);

    if (classId <= 0) {
        subjectCombo->blockSignals(false);
        return;
    }

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT DISTINCT s.id, s.name
        FROM subjects s
        JOIN schedule sch ON sch.subject_id = s.id
        WHERE sch.class_id = ?
        ORDER BY s.name
    )");
    q.addBindValue(classId);

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки предметов:" << q.lastError().text();
        subjectCombo->blockSignals(false);
        return;
    }

    while (q.next()) {
        subjectCombo->addItem(q.value(1).toString(), q.value(0).toInt());
    }

    subjectCombo->blockSignals(false);
}

//расписание
void HeadTeacherMainWindow::loadSchedule(const QString &filter)
{
    if (!scheduleTable) return;

    scheduleTable->clear();
    scheduleTable->setRowCount(0);

    QStringList headers = {"Класс", "Дата", "№", "Предмет", "Учитель", "Время"};
    scheduleTable->setColumnCount(headers.size());
    scheduleTable->setHorizontalHeaderLabels(headers);
    scheduleTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QDate currentDate = QDate::currentDate();
    QSqlQuery q(Database::getDB());

    if (filter == "today") {
        QString date = currentDate.toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT c.name, s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN classes c ON c.id = s.class_id
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.date = ?
            ORDER BY c.name, s.lesson_number
        )");
        q.addBindValue(date);
    } else if (filter == "tomorrow") {
        QString date = currentDate.addDays(1).toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT c.name, s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN classes c ON c.id = s.class_id
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.date = ?
            ORDER BY c.name, s.lesson_number
        )");
        q.addBindValue(date);
    } else {
        QString startDate = currentDate.toString("yyyy-MM-dd");
        QString endDate = currentDate.addDays(6).toString("yyyy-MM-dd");
        q.prepare(R"(
            SELECT c.name, s.date, s.lesson_number, sub.name, u.full_name, s.start_time, s.end_time
            FROM schedule s
            JOIN classes c ON c.id = s.class_id
            JOIN subjects sub ON sub.id = s.subject_id
            JOIN teachers t ON t.id = s.teacher_id
            JOIN users u ON u.id = t.user_id
            WHERE s.date BETWEEN ? AND ?
            ORDER BY c.name, s.date, s.lesson_number
        )");
        q.addBindValue(startDate);
        q.addBindValue(endDate);
    }

    if (!q.exec()) {
        scheduleTable->insertRow(0);
        auto *errorItem = new QTableWidgetItem("Ошибка загрузки данных");
        errorItem->setTextAlignment(Qt::AlignCenter);
        errorItem->setForeground(QColor("#C62828"));
        scheduleTable->setSpan(0, 0, 1, 6);
        scheduleTable->setItem(0, 0, errorItem);
        return;
    }

    int row = 0;
    while (q.next()) {
        scheduleTable->insertRow(row);
        scheduleTable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        scheduleTable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
        scheduleTable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        scheduleTable->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));
        scheduleTable->setItem(row, 4, new QTableWidgetItem(q.value(4).toString()));
        scheduleTable->setItem(row, 5, new QTableWidgetItem(q.value(5).toString() + " - " + q.value(6).toString()));

        for (int col = 0; col < 6; ++col) {
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
        auto *empty = new QTableWidgetItem("Нет уроков на выбранный период");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        scheduleTable->setSpan(0, 0, 1, 6);
        scheduleTable->setItem(0, 0, empty);
        scheduleTable->setRowHeight(0, 30);
    }
}

//посещаемость
void HeadTeacherMainWindow::loadAttendance()
{
    if (!attendanceTable) return;
    attendanceTable->setRowCount(0);
    attendanceIds.clear();

    int classId = classCombo->currentData().toInt();
    if (classId <= 0) {
        attendanceTable->insertRow(0);
        auto *empty = new QTableWidgetItem("Выберите класс для просмотра посещаемости");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        attendanceTable->setSpan(0, 0, 1, 3);
        attendanceTable->setItem(0, 0, empty);
        attendanceTable->setRowHeight(0, 35);
        return;
    }

    int subjectId = subjectCombo->currentData().toInt();
    QString date = dateEdit->date().toString("yyyy-MM-dd");

    QStringList headers = {"Ученик", "Статус", "Причина"};
    attendanceTable->setColumnCount(headers.size());
    attendanceTable->setHorizontalHeaderLabels(headers);
    attendanceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    QString scheduleQuery = "SELECT id FROM schedule WHERE class_id = ? AND date = ?";
    if (subjectId > 0) {
        scheduleQuery += " AND subject_id = ?";
    }
    scheduleQuery += " LIMIT 1";

    QSqlQuery scheduleQ(Database::getDB());
    scheduleQ.prepare(scheduleQuery);
    scheduleQ.addBindValue(classId);
    scheduleQ.addBindValue(date);
    if (subjectId > 0) {
        scheduleQ.addBindValue(subjectId);
    }

    if (!scheduleQ.exec() || !scheduleQ.next()) {
        attendanceTable->insertRow(0);
        auto *empty = new QTableWidgetItem("Нет урока на выбранную дату");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        attendanceTable->setSpan(0, 0, 1, 3);
        attendanceTable->setItem(0, 0, empty);
        attendanceTable->setRowHeight(0, 35);
        return;
    }

    int scheduleId = scheduleQ.value(0).toInt();

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT
            st.id,
            u.full_name,
            a.status,
            a.reason,
            a.id as attendance_id
        FROM students st
        JOIN users u ON u.id = st.user_id
        LEFT JOIN attendance a ON a.student_id = st.id AND a.schedule_id = ?
        WHERE st.class_id = ?
        ORDER BY u.full_name
    )");
    q.addBindValue(scheduleId);
    q.addBindValue(classId);

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки посещаемости:" << q.lastError().text();
        return;
    }

    int row = 0;
    while (q.next()) {
        int studentId = q.value(0).toInt();
        QString name = q.value(1).toString();
        int status = q.value(2).isNull() ? 1 : q.value(2).toInt();
        QString reason = q.value(3).toString();
        int attendanceId = q.value(4).toInt();

        attendanceTable->insertRow(row);

        auto *nameItem = new QTableWidgetItem(name);
        nameItem->setTextAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        nameItem->setFlags(nameItem->flags() & ~Qt::ItemIsEditable);
        attendanceTable->setItem(row, 0, nameItem);

        QComboBox *statusCombo = new QComboBox();
        statusCombo->addItem("Присутствовал", 1);
        statusCombo->addItem("Отсутствовал", 2);
        statusCombo->addItem("Опоздал", 3);

        int index = statusCombo->findData(status);
        if (index >= 0) statusCombo->setCurrentIndex(index);
        attendanceTable->setCellWidget(row, 1, statusCombo);

        QLineEdit *reasonEdit = new QLineEdit();
        reasonEdit->setPlaceholderText("Причина отсутствия");
        reasonEdit->setText(reason);
        reasonEdit->setVisible(status == 2);
        attendanceTable->setCellWidget(row, 2, reasonEdit);

        attendanceIds[studentId] = attendanceId;

        connect(statusCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
                [reasonEdit, statusCombo](int index) {
                    int status = statusCombo->currentData().toInt();
                    bool showReason = (status == 2);
                    reasonEdit->setVisible(showReason);
                    if (!showReason) reasonEdit->clear();
                });

        row++;
    }

    for (int r = 0; r < attendanceTable->rowCount(); ++r) {
        attendanceTable->setRowHeight(r, 35);
    }

    if (row == 0) {
        attendanceTable->insertRow(0);
        auto *empty = new QTableWidgetItem("Нет учеников в этом классе");
        empty->setTextAlignment(Qt::AlignCenter);
        empty->setForeground(QColor("#9E9E9E"));
        attendanceTable->setSpan(0, 0, 1, 3);
        attendanceTable->setItem(0, 0, empty);
        attendanceTable->setRowHeight(0, 35);
    }
}

void HeadTeacherMainWindow::onSaveAttendance()
{
    int classId = classCombo->currentData().toInt();
    int subjectId = subjectCombo->currentData().toInt();
    if (classId <= 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите класс");
        return;
    }

    QString date = dateEdit->date().toString("yyyy-MM-dd");

    QString scheduleQuery = "SELECT id FROM schedule WHERE class_id = ? AND date = ?";
    if (subjectId > 0) {
        scheduleQuery += " AND subject_id = ?";
    }
    scheduleQuery += " LIMIT 1";

    QSqlQuery checkQ(Database::getDB());
    checkQ.prepare(scheduleQuery);
    checkQ.addBindValue(classId);
    checkQ.addBindValue(date);
    if (subjectId > 0) {
        checkQ.addBindValue(subjectId);
    }

    if (!checkQ.exec() || !checkQ.next()) {
        QMessageBox::warning(this, "Ошибка", "Нет расписания на выбранную дату");
        return;
    }

    int scheduleId = checkQ.value(0).toInt();

    int rows = attendanceTable->rowCount();
    int saved = 0;
    int errors = 0;

    if (rows == 0 || (rows == 1 && attendanceTable->item(0, 0) &&
                      attendanceTable->item(0, 0)->text() == "Нет урока на выбранную дату")) {
        QMessageBox::warning(this, "Ошибка", "Нет данных для сохранения");
        return;
    }

    QSqlDatabase db = Database::getDB();
    db.transaction();

    for (int row = 0; row < rows; ++row) {
        QTableWidgetItem *nameItem = attendanceTable->item(row, 0);
        if (!nameItem) continue;

        QString studentName = nameItem->text();
        QSqlQuery findQ(db);
        findQ.prepare("SELECT st.id FROM students st JOIN users u ON u.id = st.user_id WHERE u.full_name = ? AND st.class_id = ?");
        findQ.addBindValue(studentName);
        findQ.addBindValue(classId);

        if (!findQ.exec() || !findQ.next()) {
            errors++;
            continue;
        }

        int studentId = findQ.value(0).toInt();

        QComboBox *statusCombo = qobject_cast<QComboBox*>(attendanceTable->cellWidget(row, 1));
        if (!statusCombo) continue;
        int status = statusCombo->currentData().toInt();

        QLineEdit *reasonEdit = qobject_cast<QLineEdit*>(attendanceTable->cellWidget(row, 2));
        QString reason = reasonEdit ? reasonEdit->text().trimmed() : "";

        if (status != 2) {
            reason = "";
        }

        if (attendanceIds.contains(studentId) && attendanceIds[studentId] > 0) {
            QSqlQuery updateQ(db);
            updateQ.prepare("UPDATE attendance SET status = ?, reason = ? WHERE id = ?");
            updateQ.addBindValue(status);
            updateQ.addBindValue(reason);
            updateQ.addBindValue(attendanceIds[studentId]);

            if (updateQ.exec()) {
                saved++;
            } else {
                errors++;
            }
        } else {
            QSqlQuery insertQ(db);
            insertQ.prepare("INSERT INTO attendance(student_id, schedule_id, status, reason) VALUES(?, ?, ?, ?)");
            insertQ.addBindValue(studentId);
            insertQ.addBindValue(scheduleId);
            insertQ.addBindValue(status);
            insertQ.addBindValue(reason);

            if (insertQ.exec()) {
                saved++;
                attendanceIds[studentId] = insertQ.lastInsertId().toInt();
            } else {
                errors++;
            }
        }
    }

    if (errors > 0) {
        db.rollback();
        QMessageBox::warning(this, "Ошибка",
                             QString("Не удалось сохранить данные. Ошибок: %1").arg(errors));
    } else {
        db.commit();
        QMessageBox::information(this, "Успех",
                                 QString("Посещаемость сохранена успешно!\nОбновлено: %1 записей").arg(saved));
    }
}

//статистика
void HeadTeacherMainWindow::loadStatistics(int filterType)
{
    statsTable->clear();
    statsTable->setRowCount(0);

    if (filterType == 0) {
        QStringList headers = {"Класс", "Учеников", "Всего уроков", "Средний %"};
        statsTable->setColumnCount(headers.size());
        statsTable->setHorizontalHeaderLabels(headers);
        statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());
        q.prepare(R"(
            SELECT
                c.name,
                COUNT(DISTINCT st.id) as students,
                COUNT(DISTINCT a.schedule_id) as total_lessons,
                ROUND(CASE WHEN COUNT(a.id) = 0 THEN 0 ELSE AVG(CASE WHEN a.status = 1 THEN 1.0 ELSE 0.0 END) * 100 END, 1) as avg_percent
            FROM classes c
            JOIN students st ON st.class_id = c.id
            LEFT JOIN attendance a ON a.student_id = st.id            GROUP BY c.id, c.name
            ORDER BY avg_percent DESC
        )");

        if (!q.exec()) {
            statsTable->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 4);
            statsTable->setItem(0, 0, empty);
            return;
        }

        int row = 0;
        while (q.next()) {
            statsTable->insertRow(row);
            statsTable->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
            statsTable->setItem(row, 1, new QTableWidgetItem(q.value(1).toString()));
            statsTable->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
            statsTable->setItem(row, 3, new QTableWidgetItem(QString::number(q.value(3).toDouble(), 'f', 1) + "%"));

            for (int col = 0; col < 4; ++col) {
                if (statsTable->item(row, col)) {
                    statsTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
                }
            }

            double percent = q.value(3).toDouble();
            QTableWidgetItem *percentItem = statsTable->item(row, 3);
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
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 4);
            statsTable->setItem(0, 0, empty);
            statsTable->setRowHeight(0, 30);
        }

    } else {
        QStringList headers = {"Класс", "Ученик", "Всего", "Присутствовал", "Отсутствовал", "%"};
        statsTable->setColumnCount(headers.size());
        statsTable->setHorizontalHeaderLabels(headers);
        statsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

        QSqlQuery q(Database::getDB());
        q.prepare(R"(
            SELECT
                c.name,
                u.full_name,
                COUNT(DISTINCT a.schedule_id) as total,
                SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) as present,
                SUM(CASE WHEN a.status = 2 THEN 1 ELSE 0 END) as absent,
                ROUND(CAST(SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) AS REAL) /
                      COUNT(DISTINCT a.schedule_id) * 100, 1) as percent
            FROM students st
            JOIN users u ON u.id = st.user_id
            JOIN classes c ON c.id = st.class_id
            LEFT JOIN attendance a ON a.student_id = st.id
            GROUP BY c.id, c.name, st.id, u.full_name
            ORDER BY c.name, u.full_name
        )");

        if (!q.exec()) {
            statsTable->insertRow(0);
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 6);
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
            statsTable->setItem(row, 4, new QTableWidgetItem(q.value(4).toString()));
            statsTable->setItem(row, 5, new QTableWidgetItem(QString::number(q.value(5).toDouble(), 'f', 1) + "%"));

            for (int col = 0; col < 6; ++col) {
                if (statsTable->item(row, col)) {
                    statsTable->item(row, col)->setTextAlignment(Qt::AlignCenter);
                }
            }

            double percent = q.value(5).toDouble();
            QTableWidgetItem *percentItem = statsTable->item(row, 5);
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
            auto *empty = new QTableWidgetItem("Нет данных");
            empty->setTextAlignment(Qt::AlignCenter);
            empty->setForeground(QColor("#9E9E9E"));
            statsTable->setSpan(0, 0, 1, 6);
            statsTable->setItem(0, 0, empty);
            statsTable->setRowHeight(0, 30);
        }
    }
}

QString HeadTeacherMainWindow::generateReport()
{
    QString report = "Отчет по посещаемости\n";
    report += "Дата: " + QDate::currentDate().toString("dd.MM.yyyy") + "\n\n";

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT
            c.name,
            u.full_name,
            COUNT(DISTINCT a.schedule_id) as total,
            SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) as present,
            SUM(CASE WHEN a.status = 2 THEN 1 ELSE 0 END) as absent,
            SUM(CASE WHEN a.status = 3 THEN 1 ELSE 0 END) as late,
            ROUND(CAST(SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) AS REAL) /
                  COUNT(DISTINCT a.schedule_id) * 100, 1) as percent
        FROM students st
        JOIN users u ON u.id = st.user_id
        JOIN classes c ON c.id = st.class_id
        JOIN attendance a ON a.student_id = st.id
        GROUP BY c.id, c.name, st.id, u.full_name
        ORDER BY c.name, u.full_name
    )");

    if (!q.exec()) {
        return "Ошибка формирования отчета";
    }

    QString currentClass = "";
    int count = 0;

    while (q.next()) {
        QString className = q.value(0).toString();
        QString studentName = q.value(1).toString();
        int total = q.value(2).toInt();
        int present = q.value(3).toInt();
        int absent = q.value(4).toInt();
        int late = q.value(5).toInt();
        double percent = q.value(6).toDouble();

        if (currentClass != className) {
            currentClass = className;
            report += "\n" + currentClass + "\n";
        }

        report += QString("%1, всего уроков: %2, присутствовал: %3, отсутствовал: %4, опоздал: %5, посещаемость: %6%\n")
                      .arg(studentName)
                      .arg(total)
                      .arg(present)
                      .arg(absent)
                      .arg(late)
                      .arg(percent);

        count++;
    }

    if (count == 0) {
        report = "Нет данных о посещаемости.";
    }

    return report;
}

//слоты

void HeadTeacherMainWindow::on_btnSchedule_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    btnSchedule->setChecked(true);
    currentActiveButton = btnSchedule;

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(scheduleWidget);
    }

    QString filter = scheduleFilter->currentData().toString();
    loadSchedule(filter);
}

void HeadTeacherMainWindow::on_btnAttendance_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    btnAttendance->setChecked(true);
    currentActiveButton = btnAttendance;

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(attendanceWidget);
    }

    loadAttendance();
}

void HeadTeacherMainWindow::on_btnStats_clicked()
{
    if (currentActiveButton) currentActiveButton->setChecked(false);
    btnStats->setChecked(true);
    currentActiveButton = btnStats;

    QStackedWidget *stacked = findChild<QStackedWidget*>("stackedWidget");
    if (stacked) {
        stacked->setCurrentWidget(statsWidget);
    }

    loadStatistics(statsFilter->currentData().toInt());
}

void HeadTeacherMainWindow::on_btnReport_clicked()
{
    QString report = generateReport();

    QString fileName = QFileDialog::getSaveFileName(this,
                                                    "Сохранить отчет", "отчет_посещаемости.txt", "Текстовые файлы (*.txt)");

    if (!fileName.isEmpty()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << report;
            file.close();
            QMessageBox::information(this, "Успех", "Отчет сохранен в " + fileName);
        } else {
            QMessageBox::warning(this, "Ошибка", "Не удалось сохранить отчет");
        }
    }
}

void HeadTeacherMainWindow::onScheduleFilterChanged(int index)
{
    if (index < 0) return;
    QString filter = scheduleFilter->currentData().toString();
    loadSchedule(filter);
}

void HeadTeacherMainWindow::onClassChanged(int index)
{
    if (index < 0) return;
    int classId = classCombo->currentData().toInt();
    loadSubjects(classId);
    loadAttendance();
}

void HeadTeacherMainWindow::onSubjectChanged(int index)
{
    Q_UNUSED(index);
    loadAttendance();
}

void HeadTeacherMainWindow::onDateChanged()
{
    loadAttendance();
}

void HeadTeacherMainWindow::onStatsFilterChanged(int index)
{
    if (index < 0) return;
    int filterType = statsFilter->currentData().toInt();
    loadStatistics(filterType);
}

void HeadTeacherMainWindow::on_btnLogout_clicked()
{
    LoginWindow *login = new LoginWindow();
    login->show();
    this->close();
}