#pragma once
#include <QMainWindow>
#include <QLabel>
#include <QComboBox>
#include <QTableWidget>
#include <QPushButton>
#include <QStackedWidget>

class StudentMainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit StudentMainWindow(QWidget *parent = nullptr);
    ~StudentMainWindow();
    void setStudentName(const QString &name);
    void setUserId(int id);

private slots:
    void on_btnSchedule_clicked();
    void on_btnAttendance_clicked();
    void on_btnStats_clicked();
    void on_btnLogout_clicked();
    void onScheduleFilterChanged(int index);
    void onStatsFilterChanged(int index);

private:
    void setupUI();
    void applyStyle();
    void loadSchedule(const QString &filter);
    void loadAttendance();
    void loadStatistics(int filterType);

    int m_userId = 0;
    int m_studentId = 0;
    int m_classId = 0;

    QLabel *nameLabel = nullptr;
    QLabel *classLabel = nullptr;

    QTableWidget *scheduleTable = nullptr;
    QTableWidget *attendanceTable = nullptr;
    QTableWidget *statsTable = nullptr;

    QComboBox *scheduleFilter = nullptr;
    QComboBox *statsFilter = nullptr;

    QPushButton *btnSchedule = nullptr;
    QPushButton *currentActiveButton = nullptr;

    QWidget *scheduleWidget = nullptr;
    QWidget *attendanceWidget = nullptr;
    QWidget *statsWidget = nullptr;
};