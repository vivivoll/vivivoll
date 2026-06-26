#include "teachermainwindow.h"
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
#include <QPushButton>
#include <QComboBox>
#include <QTableWidget>
#include <QHeaderView>
#include <QStatusBar>
#include <QTimer>
#include <QDateTime>
#include <QOverload>
#include <QPixmap>
#include <QIcon>

TeacherMainWindow::TeacherMainWindow(QWidget *parent)
    : QMainWindow(parent), m_userId(0), m_teacherId(0)
{
    setWindowTitle("Журнал посещаемости — Учитель");
    setMinimumSize(950, 620);
    setupUI();
    applyStyle();
}

void TeacherMainWindow::setupUI()
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

    nameLabel = new QLabel("Учитель");
    nameLabel->setObjectName("userNameLabel");
    topLayout->addWidget(nameLabel);

    QPushButton *btnLogout = new QPushButton("Выйти");
    btnLogout->setObjectName("logoutButton");
    btnLogout->setCursor(Qt::PointingHandCursor);
    connect(btnLogout, &QPushButton::clicked, this, &TeacherMainWindow::on_btnLogout_clicked);
    topLayout->addWidget(btnLogout);

    mainLayout->addLayout(topLayout);

    //информация об учителе
    QHBoxLayout *infoLayout = new QHBoxLayout();
    infoLayout->setContentsMargins(0, 0, 0, 10);

    subjectLabel = new QLabel("Предмет");
    subjectLabel->setObjectName("subjectLabel");
    infoLayout->addWidget(subjectLabel);

    infoLayout->addStretch();
    mainLayout->addLayout(infoLayout);

    //выбор класса и даты
    QHBoxLayout *selectLayout = new QHBoxLayout();
    selectLayout->setSpacing(15);

    QLabel *lbClass = new QLabel("Класс:");
    lbClass->setObjectName("filterLabel");
    classCombo = new QComboBox();
    classCombo->setObjectName("filterCombo");
    classCombo->setMinimumWidth(180);
    classCombo->setCursor(Qt::PointingHandCursor);

    QLabel *lbDate = new QLabel("Дата:");
    lbDate->setObjectName("filterLabel");
    dateEdit = new QDateEdit(QDate::currentDate());
    dateEdit->setCalendarPopup(true);
    dateEdit->setDisplayFormat("dd.MM.yyyy");
    dateEdit->setObjectName("dateEdit");

    selectLayout->addWidget(lbClass);
    selectLayout->addWidget(classCombo);
    selectLayout->addWidget(lbDate);
    selectLayout->addWidget(dateEdit);
    selectLayout->addStretch();

    mainLayout->addLayout(selectLayout);

    //таблица посещаемости
    QLabel *lbTable = new QLabel("Посещаемость урока:");
    lbTable->setObjectName("sectionTitle");
    mainLayout->addWidget(lbTable);

    attendanceTable = new QTableWidget();
    attendanceTable->setColumnCount(3);
    attendanceTable->setHorizontalHeaderLabels({"Ученик", "Статус", "Причина"});
    attendanceTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    attendanceTable->verticalHeader()->setVisible(false);
    attendanceTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    attendanceTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    attendanceTable->setAlternatingRowColors(true);
    attendanceTable->setObjectName("contentTable");
    mainLayout->addWidget(attendanceTable);

    //кнопки действий
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(12);

    btnSave = new QPushButton("Сохранить посещаемость");
    QPixmap savePixmap(":/icons/save.png");
    if (!savePixmap.isNull()) {
        QIcon icon(savePixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        btnSave->setIcon(icon);
        btnSave->setIconSize(QSize(20, 20));
    }
    btnSave->setObjectName("actionButton");
    btnSave->setCursor(Qt::PointingHandCursor);

    btnStatistics = new QPushButton("Статистика по классу");
    QPixmap statsPixmap(":/icons/stats.png");
    if (!statsPixmap.isNull()) {
        QIcon icon(statsPixmap.scaled(20, 20, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        btnStatistics->setIcon(icon);
        btnStatistics->setIconSize(QSize(20, 20));
    }
    btnStatistics->setObjectName("actionButton");
    btnStatistics->setCursor(Qt::PointingHandCursor);

    btnLayout->addWidget(btnSave);
    btnLayout->addWidget(btnStatistics);
    btnLayout->addStretch();

    mainLayout->addLayout(btnLayout);

    //статусная строка
    statusLabel = new QLabel("");
    statusLabel->setObjectName("statusLabel");
    statusLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(statusLabel);

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
    connect(classCombo, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &TeacherMainWindow::onClassChanged);
    connect(dateEdit, &QDateEdit::dateChanged,
            this, &TeacherMainWindow::onDateChanged);
    connect(btnSave, &QPushButton::clicked,
            this, &TeacherMainWindow::onSaveAttendance);
    connect(btnStatistics, &QPushButton::clicked,
            this, &TeacherMainWindow::onShowStatistics);
}

void TeacherMainWindow::applyStyle()
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

        QLabel#subjectLabel {
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
            padding: 8px 0 4px 0;
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

        QComboBox#filterCombo {
            background-color: white;
            color: black;
            border-radius: 8px;
            font-size: 13px;
            padding: 5px 12px;
            border: 1px solid #C8E6C9;
            min-width: 150px;
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

        QLabel#statusLabel {
            color: #2E7D32;
            font-size: 13px;
            padding: 4px;
        }

        QLabel#timeLabel {
            color: #757575;
            font-size: 12px;
            padding: 4px 8px;
        }
    )");
}

void TeacherMainWindow::setTeacherName(const QString &name)
{
    if (nameLabel) nameLabel->setText(name);
}

void TeacherMainWindow::setUserId(int id)
{
    m_userId = id;

    QSqlQuery q(Database::getDB());
    q.prepare("SELECT id FROM teachers WHERE user_id = ?");
    q.addBindValue(id);
    if (q.exec() && q.next()) {
        m_teacherId = q.value(0).toInt();
    } else {
        qDebug() << "Не найден teacher_id для user_id =" << id;
        return;
    }

    loadTeacherInfo();
    loadClasses();
}

void TeacherMainWindow::loadTeacherInfo()
{
    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT DISTINCT s.name
        FROM subjects s
        JOIN teacher_subjects ts ON ts.subject_id = s.id
        WHERE ts.teacher_id = ?
    )");
    q.addBindValue(m_teacherId);

    if (q.exec()) {
        QStringList subjects;
        while (q.next()) {
            subjects << q.value(0).toString();
        }
        subjectLabel->setText(subjects.join(", "));
    }
}

void TeacherMainWindow::loadClasses()
{
    if (!classCombo) return;
    classCombo->blockSignals(true);
    classCombo->clear();

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT DISTINCT c.id, c.name
        FROM classes c
        JOIN teacher_subjects ts ON ts.class_id = c.id
        WHERE ts.teacher_id = ?
        ORDER BY c.name
    )");
    q.addBindValue(m_teacherId);

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки классов:" << q.lastError().text();
        classCombo->blockSignals(false);
        return;
    }

    while (q.next()) {
        classCombo->addItem(q.value(1).toString(), q.value(0).toInt());
    }

    classCombo->blockSignals(false);

    if (classCombo->count() > 0) {
        classCombo->setCurrentIndex(0);
        onClassChanged(0);
    }
}

void TeacherMainWindow::loadAttendance()
{
    if (!attendanceTable) return;
    attendanceTable->setRowCount(0);
    attendanceIds.clear();

    int classId = classCombo->currentData().toInt();
    if (classId <= 0) return;

    QString date = dateEdit->date().toString("yyyy-MM-dd");

    QSqlQuery scheduleQ(Database::getDB());
    scheduleQ.prepare(R"(
        SELECT id FROM schedule
        WHERE class_id = ? AND date = ?
        LIMIT 1
    )");
    scheduleQ.addBindValue(classId);
    scheduleQ.addBindValue(date);

    if (!scheduleQ.exec() || !scheduleQ.next()) {
        attendanceTable->setRowCount(1);
        auto *empty = new QTableWidgetItem("Нет уроков на выбранную дату");
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

void TeacherMainWindow::loadStatistics()
{
    int classId = classCombo->currentData().toInt();
    if (classId <= 0) return;

    QSqlQuery q(Database::getDB());
    q.prepare(R"(
        SELECT
            u.full_name,
            COUNT(DISTINCT a.schedule_id) as total_lessons,
            SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) as present,
            SUM(CASE WHEN a.status = 2 THEN 1 ELSE 0 END) as absent,
            SUM(CASE WHEN a.status = 3 THEN 1 ELSE 0 END) as late,
            ROUND(CAST(SUM(CASE WHEN a.status = 1 THEN 1 ELSE 0 END) AS REAL) /
                  COUNT(DISTINCT a.schedule_id) * 100, 1) as percent
        FROM students st
        JOIN users u ON u.id = st.user_id
        JOIN attendance a ON a.student_id = st.id
        JOIN schedule s ON s.id = a.schedule_id
        WHERE st.class_id = ?
        GROUP BY st.id, u.full_name
        ORDER BY u.full_name
    )");
    q.addBindValue(classId);

    if (!q.exec()) {
        qDebug() << "Ошибка загрузки статистики:" << q.lastError().text();
        return;
    }

    QString stats = "Статистика посещаемости класса:\n\n";
    bool hasData = false;

    while (q.next()) {
        hasData = true;
        QString name = q.value(0).toString();
        int total = q.value(1).toInt();
        int present = q.value(2).toInt();
        int absent = q.value(3).toInt();
        int late = q.value(4).toInt();
        double percent = q.value(5).toDouble();

        stats += QString("%1\n  Всего: %2 | Присутствовал: %3 | Отсутствовал: %4 | Опоздал: %5 | Посещаемость: %6%\n\n")
                     .arg(name)
                     .arg(total)
                     .arg(present)
                     .arg(absent)
                     .arg(late)
                     .arg(percent);
    }

    if (!hasData) {
        stats += "Нет данных о посещаемости для этого класса.";
    }

    QMessageBox::information(this, "Статистика посещаемости", stats);
}

//слоты

void TeacherMainWindow::onClassChanged(int index)
{
    if (index < 0) return;
    loadAttendance();
}

void TeacherMainWindow::onDateChanged()
{
    loadAttendance();
}

void TeacherMainWindow::onSaveAttendance()
{
    int classId = classCombo->currentData().toInt();
    if (classId <= 0) {
        QMessageBox::warning(this, "Ошибка", "Выберите класс");
        return;
    }

    QString date = dateEdit->date().toString("yyyy-MM-dd");

    QSqlQuery checkQ(Database::getDB());
    checkQ.prepare("SELECT id FROM schedule WHERE class_id = ? AND date = ?");
    checkQ.addBindValue(classId);
    checkQ.addBindValue(date);

    if (!checkQ.exec() || !checkQ.next()) {
        QMessageBox::warning(this, "Ошибка", "Нет расписания на выбранную дату");
        return;
    }

    int scheduleId = checkQ.value(0).toInt();

    int rows = attendanceTable->rowCount();
    int saved = 0;
    int errors = 0;

    if (rows == 0 || (rows == 1 && attendanceTable->item(0, 0) &&
                      attendanceTable->item(0, 0)->text() == "Нет уроков на выбранную дату")) {
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
        statusLabel->setText(QString("Посещаемость сохранена! Обновлено: %1 записей").arg(saved));
        QMessageBox::information(this, "Успех",
                                 QString("Посещаемость сохранена успешно!\nОбновлено: %1 записей").arg(saved));
    }
}

void TeacherMainWindow::onShowStatistics()
{
    loadStatistics();
}

void TeacherMainWindow::on_btnLogout_clicked()
{
    LoginWindow *login = new LoginWindow();
    login->show();
    this->close();
}

void TeacherMainWindow::updateStatusLabel(const QString &text, bool success)
{
    if (!statusLabel) return;
    statusLabel->setText(text);
    statusLabel->setStyleSheet(QString("color: %1; font-size: 13px;")
                                   .arg(success ? "#2E7D32" : "#C62828"));
}