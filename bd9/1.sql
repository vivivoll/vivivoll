CREATE TEMPORARY TABLE TempOrders AS
SELECT ID_заказа, Дата_заказа, Статус
FROM Заказы
WHERE Статус = 'Доставлен';

SELECT * FROM TempOrders;

-- Удаление временной таблицы после использования
DROP TEMPORARY TABLE IF EXISTS TempOrders;