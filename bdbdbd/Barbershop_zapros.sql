USE Barbershop;
GO

-- 1
CREATE OR ALTER PROCEDURE GetAllBarbers
AS
BEGIN
    SELECT FullName
    FROM Barbers;
END;
GO

-- тест 1
EXEC GetAllBarbers;
GO


-- 2
CREATE OR ALTER PROCEDURE GetSeniorBarbers
AS
BEGIN
    SELECT *
    FROM Barbers
    WHERE Position = N'Синьор-барбер';
END;
GO

-- тест 2
EXEC GetSeniorBarbers;
GO


-- 3
CREATE OR ALTER PROCEDURE GetBarbersForTraditionalShaving
AS
BEGIN
    SELECT DISTINCT b.*
    FROM Barbers b
    JOIN BarberServices bs ON b.BarberId = bs.BarberId
    JOIN Services s ON bs.ServiceId = s.ServiceId
    WHERE s.ServiceName = N'Традиционное бритьё бороды';
END;
GO

-- тест 3
EXEC GetBarbersForTraditionalShaving;
GO


-- 4
CREATE OR ALTER PROCEDURE GetBarbersByService
    @ServiceName NVARCHAR(100)
AS
BEGIN
    SELECT DISTINCT b.*
    FROM Barbers b
    JOIN BarberServices bs ON b.BarberId = bs.BarberId
    JOIN Services s ON bs.ServiceId = s.ServiceId
    WHERE s.ServiceName = @ServiceName;
END;
GO

-- тест 4
EXEC GetBarbersByService N'Оформление бороды';
GO


-- 5
CREATE OR ALTER PROCEDURE GetBarbersByExperience
    @Years INT
AS
BEGIN
    SELECT *
    FROM Barbers
    WHERE DATEADD(YEAR, @Years, HireDate) < CAST(GETDATE() AS DATE);
END;
GO

-- тест 5
EXEC GetBarbersByExperience 5;
GO


-- 6
CREATE OR ALTER PROCEDURE GetBarberPositionCounts
AS
BEGIN
    SELECT
        SUM(CASE WHEN Position = N'Синьор-барбер' THEN 1 ELSE 0 END) AS SeniorBarbers,
        SUM(CASE WHEN Position = N'Джуниор-барбер' THEN 1 ELSE 0 END) AS JuniorBarbers
    FROM Barbers;
END;
GO

-- тест 6
EXEC GetBarberPositionCounts;
GO


-- 7
CREATE OR ALTER PROCEDURE GetRegularClients
    @VisitCount INT
AS
BEGIN
    SELECT
        c.ClientId,
        c.FullName,
        c.Phone,
        c.Email,
        COUNT(v.VisitId) AS VisitCount
    FROM Clients c
    JOIN VisitArchive v ON c.ClientId = v.ClientId
    GROUP BY c.ClientId, c.FullName, c.Phone, c.Email
    HAVING COUNT(v.VisitId) >= @VisitCount;
END;
GO

-- тест 7
EXEC GetRegularClients 2;
GO


-- 8 тригг
CREATE OR ALTER TRIGGER TRG_PreventChiefBarberDelete
ON Barbers
AFTER DELETE
AS
BEGIN
    IF NOT EXISTS (
        SELECT 1
        FROM Barbers
        WHERE Position = N'Чиф-барбер'
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50001, N'Нельзя удалить единственного чиф-барбера.', 1;
    END
END;
GO

-- тест 8
DELETE FROM Barbers
WHERE BarberId = 1;
GO


-- 9 тригг
CREATE OR ALTER TRIGGER TRG_PreventUnderageBarber
ON Barbers
AFTER INSERT
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM inserted
        WHERE DATEADD(YEAR, 21, BirthDate) > CAST(GETDATE() AS DATE)
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50002, N'Нельзя добавлять барбера младше 21 года.', 1;
    END
END;
GO

-- тест 9
INSERT INTO Barbers
(FullName, Gender, Phone, Email, BirthDate, HireDate, Position)
VALUES
(N'Тестовый Барбер', N'Мужской', N'+79990000999',
 N'test999@mail.ru', '2007-01-01', '2026-01-01',
 N'Джуниор-барбер');
GO


-- 10
CREATE OR ALTER PROCEDURE GetMostExperiencedBarber
AS
BEGIN
    SELECT TOP 1 *
    FROM Barbers
    ORDER BY HireDate;
END;
GO

-- тест 10
EXEC GetMostExperiencedBarber;
GO


-- 11
CREATE OR ALTER PROCEDURE GetTopBarberByClients
    @StartDate DATE,
    @EndDate DATE
AS
BEGIN
    SELECT TOP 1
        b.BarberId,
        b.FullName,
        COUNT(DISTINCT v.ClientId) AS ClientCount
    FROM Barbers b
    JOIN VisitArchive v ON b.BarberId = v.BarberId
    WHERE v.VisitDate >= @StartDate
      AND v.VisitDate < DATEADD(DAY, 1, @EndDate)
    GROUP BY b.BarberId, b.FullName
    ORDER BY ClientCount DESC;
END;
GO

-- тест 11
EXEC GetTopBarberByClients '2026-09-01', '2026-09-30';
GO


-- 12
CREATE OR ALTER PROCEDURE GetMostFrequentClient
AS
BEGIN
    SELECT TOP 1
        c.ClientId,
        c.FullName,
        COUNT(v.VisitId) AS VisitCount
    FROM Clients c
    JOIN VisitArchive v ON c.ClientId = v.ClientId
    GROUP BY c.ClientId, c.FullName
    ORDER BY VisitCount DESC;
END;
GO

-- тест 12
EXEC GetMostFrequentClient;
GO


-- 13
CREATE OR ALTER PROCEDURE GetBiggestSpender
AS
BEGIN
    SELECT TOP 1
        c.ClientId,
        c.FullName,
        SUM(v.TotalCost) AS TotalSpent
    FROM Clients c
    JOIN VisitArchive v ON c.ClientId = v.ClientId
    GROUP BY c.ClientId, c.FullName
    ORDER BY TotalSpent DESC;
END;
GO

-- тест 13
EXEC GetBiggestSpender;
GO


-- 14
CREATE OR ALTER PROCEDURE GetLongestService
AS
BEGIN
    SELECT TOP 1 *
    FROM Services
    ORDER BY DurationMinutes DESC;
END;
GO

-- тест 14
EXEC GetLongestService;
GO


-- 15
CREATE OR ALTER PROCEDURE GetMostPopularBarber
AS
BEGIN
    SELECT TOP 1
        b.BarberId,
        b.FullName,
        COUNT(DISTINCT v.ClientId) AS ClientCount
    FROM Barbers b
    JOIN VisitArchive v ON b.BarberId = v.BarberId
    GROUP BY b.BarberId, b.FullName
    ORDER BY ClientCount DESC;
END;
GO

-- тест 15
EXEC GetMostPopularBarber;
GO


-- 16
CREATE OR ALTER PROCEDURE GetTop3BarbersByMonth
    @Year INT,
    @Month INT
AS
BEGIN
    SELECT TOP 3
        b.BarberId,
        b.FullName,
        SUM(v.TotalCost) AS TotalMoney
    FROM Barbers b
    JOIN VisitArchive v ON b.BarberId = v.BarberId
    WHERE YEAR(v.VisitDate) = @Year
      AND MONTH(v.VisitDate) = @Month
    GROUP BY b.BarberId, b.FullName
    ORDER BY TotalMoney DESC;
END;
GO

-- тест 16
EXEC GetTop3BarbersByMonth 2026, 9;
GO


-- 17
CREATE OR ALTER PROCEDURE GetTop3BarbersByRating
AS
BEGIN
    SELECT TOP 3
        b.BarberId,
        b.FullName,
        AVG(CAST(v.Rating AS DECIMAL(10,2))) AS AverageRating,
        COUNT(v.VisitId) AS VisitCount
    FROM Barbers b
    JOIN VisitArchive v ON b.BarberId = v.BarberId
    WHERE v.Rating IS NOT NULL
    GROUP BY b.BarberId, b.FullName
    HAVING COUNT(v.VisitId) >= 30
    ORDER BY AverageRating DESC;
END;
GO

-- тест 17
EXEC GetTop3BarbersByRating;
GO


-- 18
CREATE OR ALTER PROCEDURE GetBarberSchedule
    @BarberId INT,
    @WorkDate DATE
AS
BEGIN
    SELECT
        b.FullName,
        bs.WorkDate,
        bs.StartTime,
        bs.EndTime
    FROM BarberSchedule bs
    JOIN Barbers b ON bs.BarberId = b.BarberId
    WHERE bs.BarberId = @BarberId
      AND bs.WorkDate = @WorkDate;
END;
GO

-- тест 18
EXEC GetBarberSchedule 1, '2026-09-28';
GO


-- 19
CREATE OR ALTER PROCEDURE GetFreeSlotsForWeek
    @BarberId INT,
    @StartDate DATE,
    @SlotMinutes INT = 30
AS
BEGIN
    ;WITH Numbers AS
    (
        SELECT 0 AS N
        UNION ALL
        SELECT N + 1
        FROM Numbers
        WHERE N < 47
    ),
    Slots AS
    (
        SELECT
            bs.WorkDate,
            DATEADD(
                MINUTE,
                n.N * @SlotMinutes,
                CAST(bs.StartTime AS DATETIME2)
            ) AS SlotStart,
            DATEADD(
                MINUTE,
                (n.N + 1) * @SlotMinutes,
                CAST(bs.StartTime AS DATETIME2)
            ) AS SlotEnd,
            bs.EndTime
        FROM BarberSchedule bs
        CROSS JOIN Numbers n
        WHERE bs.BarberId = @BarberId
          AND bs.WorkDate BETWEEN @StartDate
                              AND DATEADD(DAY, 6, @StartDate)
    )
    SELECT
        WorkDate,
        CAST(SlotStart AS TIME) AS FreeFrom,
        CAST(SlotEnd AS TIME) AS FreeTo
    FROM Slots
    WHERE CAST(SlotEnd AS TIME) <= EndTime
      AND NOT EXISTS (
          SELECT 1
          FROM Appointments a
          WHERE a.BarberId = @BarberId
            AND CAST(a.StartDateTime AS DATE) = WorkDate
            AND SlotStart < a.EndDateTime
            AND SlotEnd > a.StartDateTime
      )
    ORDER BY WorkDate, FreeFrom
    OPTION (MAXRECURSION 100);
END;
GO

-- тест 19
EXEC GetFreeSlotsForWeek 1, '2026-09-28', 30;
GO


-- 20
CREATE OR ALTER PROCEDURE MoveCompletedAppointmentsToArchive
AS
BEGIN
    SET NOCOUNT ON;

    BEGIN TRY
        BEGIN TRANSACTION;

        DECLARE
            @AppointmentId INT,
            @ClientId INT,
            @BarberId INT,
            @ServiceId INT,
            @StartDateTime DATETIME2,
            @Price DECIMAL(10,2),
            @VisitId INT;

        DECLARE cur CURSOR LOCAL FAST_FORWARD FOR
            SELECT
                a.AppointmentId,
                a.ClientId,
                a.BarberId,
                a.ServiceId,
                a.StartDateTime,
                s.Price
            FROM Appointments a
            JOIN Services s ON a.ServiceId = s.ServiceId
            WHERE a.EndDateTime < GETDATE();

        OPEN cur;

        FETCH NEXT FROM cur INTO
            @AppointmentId,
            @ClientId,
            @BarberId,
            @ServiceId,
            @StartDateTime,
            @Price;

        WHILE @@FETCH_STATUS = 0
        BEGIN
            INSERT INTO VisitArchive
            (ClientId, BarberId, VisitDate, TotalCost, Rating, Feedback)
            VALUES
            (@ClientId, @BarberId, @StartDateTime, @Price, NULL, NULL);

            SET @VisitId = SCOPE_IDENTITY();

            INSERT INTO VisitArchiveServices
            (VisitId, ServiceId)
            VALUES
            (@VisitId, @ServiceId);

            DELETE FROM Appointments
            WHERE AppointmentId = @AppointmentId;

            FETCH NEXT FROM cur INTO
                @AppointmentId,
                @ClientId,
                @BarberId,
                @ServiceId,
                @StartDateTime,
                @Price;
        END;

        CLOSE cur;
        DEALLOCATE cur;

        COMMIT TRANSACTION;
    END TRY
    BEGIN CATCH
        IF @@TRANCOUNT > 0
            ROLLBACK TRANSACTION;

        IF CURSOR_STATUS('local', 'cur') >= 0
            CLOSE cur;

        IF CURSOR_STATUS('local', 'cur') = -1
            DEALLOCATE cur;

        THROW;
    END CATCH
END;
GO

-- тест 20
EXEC MoveCompletedAppointmentsToArchive;
GO


-- 21 тригг
CREATE OR ALTER TRIGGER TRG_PreventAppointmentOverlap
ON Appointments
AFTER INSERT, UPDATE
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Appointments a
        JOIN inserted i
          ON a.BarberId = i.BarberId
         AND a.AppointmentId <> i.AppointmentId
         AND i.StartDateTime < a.EndDateTime
         AND i.EndDateTime > a.StartDateTime
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50003, N'Барбер уже занят в указанное время.', 1;
    END
END;
GO

-- тест 21
INSERT INTO Appointments
(ClientId, BarberId, ServiceId, StartDateTime, EndDateTime)
VALUES
(9, 1, 1, '2026-09-28 10:30', '2026-09-28 11:30');
GO


-- 22 тригг
CREATE OR ALTER TRIGGER TRG_MaxJuniorBarbers
ON Barbers
AFTER INSERT
AS
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Barbers
        WHERE Position = N'Джуниор-барбер'
        GROUP BY Position
        HAVING COUNT(*) > 5
    )
    BEGIN
        ROLLBACK TRANSACTION;
        THROW 50004,
              N'В салоне уже работают 5 джуниор-барберов.',
              1;
    END
END;
GO

-- тест 22
INSERT INTO Barbers
(FullName, Gender, Phone, Email, BirthDate, HireDate, Position)
VALUES
(N'Тестовый Джуниор', N'Мужской', N'+79990000888',
 N'junior@test.ru', '1995-01-01', '2026-01-01',
 N'Джуниор-барбер');
GO


-- 23
CREATE OR ALTER PROCEDURE GetClientsWithoutReviews
AS
BEGIN
    SELECT c.*
    FROM Clients c
    WHERE NOT EXISTS (
        SELECT 1
        FROM Reviews r
        WHERE r.ClientId = c.ClientId
    );
END;
GO

-- тест 23
EXEC GetClientsWithoutReviews;
GO


-- 24
CREATE OR ALTER PROCEDURE GetInactiveClients
AS
BEGIN
    SELECT c.*
    FROM Clients c
    WHERE NOT EXISTS (
        SELECT 1
        FROM VisitArchive v
        WHERE v.ClientId = c.ClientId
          AND v.VisitDate >= DATEADD(YEAR, -1, CAST(GETDATE() AS DATE))
    );
END;
GO

-- тест 24
EXEC GetInactiveClients;
GO