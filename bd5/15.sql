-- 15.sql
SELECT ФИО, Телефон, Адрес
FROM Покупатели
WHERE Адрес IS NULL OR Адрес = '';