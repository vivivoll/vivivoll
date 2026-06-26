#pragma once
#include <QMainWindow>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QMap>
#include <QStackedWidget>

class HeadTeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit HeadTeacherMainWindow(QWidget *parent = nullptr);
    void setHeadTeacherName(const QString &name);
    void setUserId(int id);

private slots:
    void on_btnSchedule_clicked();
    void on_btnAttendance_clicked();
    void on_btnStats_clicked();
    void on_btnReport_clicked();
    void on_btnLogout_clicked();

    void onScheduleFilterChanged(int index);
    void onClassChanged(int index);
    void onSubjectChanged(int index);
    void onDateChanged();
    void onSaveAttendance();
    void onStatsFilterChanged(int index);

private:
    void setupUI();
    void applyStyle();
    void loadHeadTeacherInfo();
    void loadClasses();
    void loadSubjects(int classId);
    void loadSchedule(const QString &filter);
    void loadAttendance();
    void loadStatistics(int filterType);
    QString generateReport();

    int m_userId = 0;
    int m_headTeacherId = 0;

    QLabel *nameLabel = nullptr;
    QLabel *welcomeLabel = nullptr;

    QPushButton *btnSchedule = nullptr;
    QPushButton *btnAttendance = nullptr;
    QPushButton *btnStats = nullptr;
    QPushButton *btnReport = nullptr;
    QPushButton *currentActiveButton = nullptr;

    QWidget *scheduleWidget = nullptr;
    QWidget *attendanceWidget = nullptr;
    QWidget *statsWidget = nullptr;

    QTableWidget *scheduleTable = nullptr;
    QComboBox *scheduleFilter = nullptr;

    QComboBox *classCombo = nullptr;
    QComboBox *subjectCombo = nullptr;
    QDateEdit *dateEdit = nullptr;
    QTableWidget *attendanceTable = nullptr;
    QPushButton *btnSave = nullptr;
    QMap<int, int> attendanceIds;

    QComboBox *statsFilter = nullptr;
    QTableWidget *statsTable = nullptr;
};