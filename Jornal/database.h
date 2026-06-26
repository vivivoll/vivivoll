#pragma once
#include <QFileInfo>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QStringList>
#include <QDate>

class Database
{
public:
    static Database& instance()
    {
        static Database db;
        return db;
    }

    bool init(const QString& path = "school.db")
    {
        if (QSqlDatabase::contains("JOURNAL_DB"))
            return true;

        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "JOURNAL_DB");
        db.setDatabaseName(path);

        if (!db.open())
        {
            qDebug() << "Ошибка открытия БД:" << db.lastError().text();
            return false;
        }
        createTables();
        seedData();
        return true;
    }

    static QSqlDatabase getDB()
    {
        return QSqlDatabase::database("JOURNAL_DB");
    }

private:
    Database() = default;

    bool execQuery(QSqlQuery& q, const QString& sql)
    {
        if (!q.exec(sql))
        {
            qDebug() << "SQL ERROR:" << sql;
            qDebug() << q.lastError().text();
            return false;
        }
        return true;
    }

    void createTables()
    {
        QSqlQuery q(getDB());

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS users(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                login TEXT UNIQUE NOT NULL,
                password TEXT NOT NULL,
                role INTEGER NOT NULL,
                full_name TEXT NOT NULL
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS classes(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS students(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                user_id INTEGER NOT NULL,
                class_id INTEGER NOT NULL,
                FOREIGN KEY(user_id) REFERENCES users(id),
                FOREIGN KEY(class_id) REFERENCES classes(id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS teachers(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                user_id INTEGER NOT NULL,
                FOREIGN KEY(user_id) REFERENCES users(id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS headteachers(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                user_id INTEGER NOT NULL,
                FOREIGN KEY(user_id) REFERENCES users(id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS subjects(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS teacher_subjects(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                teacher_id INTEGER NOT NULL,
                subject_id INTEGER NOT NULL,
                class_id INTEGER NOT NULL,
                FOREIGN KEY(teacher_id) REFERENCES teachers(id),
                FOREIGN KEY(subject_id) REFERENCES subjects(id),
                FOREIGN KEY(class_id) REFERENCES classes(id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS schedule(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                class_id INTEGER NOT NULL,
                subject_id INTEGER NOT NULL,
                teacher_id INTEGER NOT NULL,
                date TEXT NOT NULL,
                lesson_number INTEGER NOT NULL,
                start_time TEXT NOT NULL,
                end_time TEXT NOT NULL,
                FOREIGN KEY(class_id) REFERENCES classes(id),
                FOREIGN KEY(subject_id) REFERENCES subjects(id),
                FOREIGN KEY(teacher_id) REFERENCES teachers(id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS attendance(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                student_id INTEGER NOT NULL,
                schedule_id INTEGER NOT NULL,
                status INTEGER NOT NULL DEFAULT 1,
                reason TEXT,
                FOREIGN KEY(student_id) REFERENCES students(id),
                FOREIGN KEY(schedule_id) REFERENCES schedule(id),
                UNIQUE(student_id, schedule_id)
            )
        )");

        execQuery(q, R"(
            CREATE TABLE IF NOT EXISTS attendance_statuses(
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                name TEXT NOT NULL,
                color TEXT NOT NULL
            )
        )");
    }

    void addScheduleForClass(int classId, int days, int lessonsPerDay,
                             const QList<int>& subjectIds, const QList<int>& teacherIds,
                             const QString& startDate)
    {
        QSqlQuery q(getDB());
        QDate currentDate = QDate::fromString(startDate, "yyyy-MM-dd");

        for (int day = 0; day < days; day++) {
            QDate date = currentDate.addDays(day);
            QString dateStr = date.toString("yyyy-MM-dd");

            for (int lesson = 1; lesson <= lessonsPerDay; lesson++) {
                int idx = (day * lessonsPerDay + lesson - 1) % subjectIds.size();
                int subjectId = subjectIds[idx];
                int teacherId = teacherIds[idx % teacherIds.size()];

                QString startTime = QString("%1:%2")
                                        .arg(7 + lesson, 2, 10, QChar('0'))
                                        .arg(lesson % 2 == 0 ? "45" : "35");
                QString endTime = QString("%1:%2")
                                      .arg(8 + lesson, 2, 10, QChar('0'))
                                      .arg(lesson % 2 == 0 ? "30" : "20");

                QSqlQuery ins(getDB());
                ins.prepare("INSERT INTO schedule(class_id, subject_id, teacher_id, date, lesson_number, start_time, end_time) "
                            "VALUES(?, ?, ?, ?, ?, ?, ?)");
                ins.addBindValue(classId);
                ins.addBindValue(subjectId);
                ins.addBindValue(teacherId);
                ins.addBindValue(dateStr);
                ins.addBindValue(lesson);
                ins.addBindValue(startTime);
                ins.addBindValue(endTime);
                ins.exec();
            }
        }
    }

    void seedData()
    {
        QSqlQuery q(getDB());

        q.exec("SELECT COUNT(*) FROM users");
        if (q.next() && q.value(0).toInt() > 0)
            return;

        qDebug() << "Создаем базу данных с актуальными датами...";

        //классы
        q.exec("INSERT INTO classes(name) VALUES('10 А')");
        q.exec("INSERT INTO classes(name) VALUES('9 В')");

        //предметы
        QStringList subjects = {"Математика", "Физика", "История", "Русский язык",
                                "Химия", "Биология", "Английский язык", "Литература"};
        for (const QString& subject : subjects) {
            QSqlQuery ins(getDB());
            ins.prepare("INSERT INTO subjects(name) VALUES(?)");
            ins.addBindValue(subject);
            ins.exec();
        }
        //статус посещаемости
        q.exec("INSERT INTO attendance_statuses(name, color) VALUES('Присутствовал', '#2E7D32')");
        q.exec("INSERT INTO attendance_statuses(name, color) VALUES('Отсутствовал', '#C62828')");
        q.exec("INSERT INTO attendance_statuses(name, color) VALUES('Опоздал', '#F57F17')");

        //пользователи
        q.exec("INSERT INTO users(login,password,role,full_name) VALUES('teacher1','123123',2,'Смирнов Сергей Сергеевич')");
        q.exec("INSERT INTO users(login,password,role,full_name) VALUES('teacher2','123123',2,'Петров Алексей Викторович')");
        q.exec("INSERT INTO users(login,password,role,full_name) VALUES('admin','123123',3,'Иванова Анна Петровна')");
        q.exec("INSERT INTO users(login,password,role,full_name) VALUES('student1','123123',0,'Иванов Иван')");
        q.exec("INSERT INTO users(login,password,role,full_name) VALUES('student2','123123',0,'Сидоров Максим')");

        //ученики
        q.exec("INSERT INTO students(user_id,class_id) VALUES(4,1)");  //Иванов 10А
        q.exec("INSERT INTO students(user_id,class_id) VALUES(5,2)");  //Сидоров 9В

        //учителя
        q.exec("INSERT INTO teachers(user_id) VALUES(1)");  //Смирнов
        q.exec("INSERT INTO teachers(user_id) VALUES(2)");  //Петров

        //завуч
        q.exec("INSERT INTO headteachers(user_id) VALUES(3)");

        //связи учителей с предметами и классами
        q.exec("INSERT INTO teacher_subjects(teacher_id,subject_id,class_id) VALUES(1,1,1)");
        q.exec("INSERT INTO teacher_subjects(teacher_id,subject_id,class_id) VALUES(1,1,2)");
        q.exec("INSERT INTO teacher_subjects(teacher_id,subject_id,class_id) VALUES(2,2,1)");

        //расписание на неделю
        QDate today = QDate::currentDate();
        QString todayStr = today.toString("yyyy-MM-dd");

        //предметы 10А
        QList<int> class1Subjects = {1, 2, 3, 4, 5, 6, 7, 8};
        QList<int> class1Teachers = {1, 2, 1, 1, 1, 1, 1, 1};

        //предметы 9В
        QList<int> class2Subjects = {1, 6, 7, 8, 1, 4, 2, 3};
        QList<int> class2Teachers = {1, 1, 1, 1, 1, 1, 2, 1};

        addScheduleForClass(1, 5, 4, class1Subjects, class1Teachers, todayStr);
        addScheduleForClass(2, 5, 3, class2Subjects, class2Teachers, todayStr);

        //посещаемость
        QSqlQuery sel(getDB());

        //иванов 10А
        sel.exec("SELECT id FROM schedule WHERE class_id = 1 ORDER BY date, lesson_number LIMIT 10");
        QList<int> scheduleIds;
        while (sel.next()) scheduleIds << sel.value(0).toInt();

        for (int i = 0; i < scheduleIds.size(); i++) {
            int status = (i % 3 == 0) ? 2 : 1;
            QString reason = (status == 2) ? "Болел" : "";
            QSqlQuery ins(getDB());
            ins.prepare("INSERT INTO attendance(student_id, schedule_id, status, reason) VALUES(?, ?, ?, ?)");
            ins.addBindValue(1);
            ins.addBindValue(scheduleIds[i]);
            ins.addBindValue(status);
            ins.addBindValue(reason);
            ins.exec();
        }

        //сидоров 9В
        sel.exec("SELECT id FROM schedule WHERE class_id = 2 ORDER BY date, lesson_number LIMIT 10");
        scheduleIds.clear();
        while (sel.next()) scheduleIds << sel.value(0).toInt();

        for (int i = 0; i < scheduleIds.size(); i++) {
            int status = (i % 2 == 0) ? 1 : 2;
            QString reason = (status == 2) ? "Уважительная причина" : "";
            QSqlQuery ins(getDB());
            ins.prepare("INSERT INTO attendance(student_id, schedule_id, status, reason) VALUES(?, ?, ?, ?)");
            ins.addBindValue(2);
            ins.addBindValue(scheduleIds[i]);
            ins.addBindValue(status);
            ins.addBindValue(reason);
            ins.exec();
        }

        qDebug() << "База данных создана! Расписание на текущую неделю добавлено.";
    }
};