DROP DATABASE IF EXISTS basa4;
CREATE DATABASE basa4;
USE basa4;
-- Таблица таблицы кафедры 
CREATE TABLE KAFEDRA (
    KOD_KAFEDRU INT PRIMARY KEY,
    NAME_KAFEDRA VARCHAR(50)
);

-- Таблица таблицы студентов
CREATE TABLE STUDENT (
    STUDENT_ID INT AUTO_INCREMENT PRIMARY KEY,
    SUTNAME VARCHAR(50) NOT NULL,
    SUTFNAME VARCHAR(50) NOT NULL,
    STIPEND DECIMAL(10,2) CHECK (STIPEND < 500),
    KURS INT CHECK (KURS BETWEEN 1 AND 5),
    CITY VARCHAR(50),
    BIRTDAY DATE,
    `GROUP` VARCHAR(20),
    KOD_KAFEDRU INT,
    CONSTRAINT fk_student_kafedru FOREIGN KEY (KOD_KAFEDRU)
        REFERENCES KAFEDRA(KOD_KAFEDRU)
);
-- Создание таблицы учителей 
CREATE TABLE TEACHER (
    KOD_TEACHER INT AUTO_INCREMENT PRIMARY KEY,
    KOD_KAFEDRU INT,
    NAME_TEACHER VARCHAR(50),
    INDEF_KOD VARCHAR(50) UNIQUE,
    DOLGNOST ENUM('профессор','доцент','старший преподаватель','ассистент') DEFAULT 'ассистент',
    ZVANIE ENUM('к.т.н','к.г.у','к.с.н','к.ф.м.н.','д.т.н','д.г.у','д.с.н','д.ф.м.н','нет') DEFAULT 'нет',
    SALARY DECIMAL(10,2) DEFAULT 1000 CHECK (SALARY > 0),
    RISE DECIMAL(10,2) DEFAULT 0 CHECK (RISE >= 0),
    DATA_HIRE DATETIME,
    BIRTHDAY DATE,
    POL ENUM('ж','м'),
    TEL_TEACHER VARCHAR(12),
    CONSTRAINT fk_teacher_kafedru FOREIGN KEY (KOD_KAFEDRU)
        REFERENCES KAFEDRA(KOD_KAFEDRU),
    CONSTRAINT chk_tel_teacher CHECK (TEL_TEACHER REGEXP '^[1-9][0-9]-[0-9]{2}-[0-9]{2}$')
);

-- Заполнение кафедры
INSERT INTO KAFEDRA (KOD_KAFEDRU, NAME_KAFEDRA) VALUES
(1, 'Математика'),
(2, 'Физика');

-- Заполнение студентов
INSERT INTO STUDENT (SUTNAME, SUTFNAME, STIPEND, KURS, CITY, BIRTDAY, `GROUP`, KOD_KAFEDRU) VALUES
('Виктор', 'Носков', 100, 1, 'Чита', '2008-07-29', 'А-11', 1),
('Виктория', 'Носкова', 200, 2, 'Чита', '2001-07-29', 'Б-12', 2);

-- Заполнение учителей
INSERT INTO TEACHER (KOD_KAFEDRU, NAME_TEACHER, INDEF_KOD, DOLGNOST, ZVANIE, SALARY, RISE, DATA_HIRE, BIRTHDAY, POL, TEL_TEACHER) VALUES
(1, 'Иваченко', 'ID001', 'профессор', 'д.т.н', 1500, 200, '2024-02-10', '1980-01-10', 'м', '123456'),
(2, 'Киселева', 'ID002', 'профессор', 'к.т.н', 1200, 150, '2023-01-10', '1980-02-10', 'ж', '234567');