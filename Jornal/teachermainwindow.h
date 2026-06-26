#pragma once
#include <QMainWindow>
#include <QComboBox>
#include <QDateEdit>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QMap>

class TeacherMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TeacherMainWindow(QWidget *parent = nullptr);
    void setTeacherName(const QString &name);
    void setUserId(int id);

private slots:
    void on_btnLogout_clicked();
    void onClassChanged(int index);
    void onDateChanged();
    void onSaveAttendance();
    void onShowStatistics();

private:
    void setupUI();
    void applyStyle();
    void loadTeacherInfo();
    void loadClasses();
    void loadAttendance();
    void loadStatistics();
    void updateStatusLabel(const QString &text, bool success = true);

    int m_userId = 0;
    int m_teacherId = 0;

    QLabel *nameLabel = nullptr;
    QLabel *subjectLabel = nullptr;
    QLabel *statusLabel = nullptr;

    QComboBox *classCombo = nullptr;
    QDateEdit *dateEdit = nullptr;
    QTableWidget *attendanceTable = nullptr;

    QPushButton *btnSave = nullptr;
    QPushButton *btnStatistics = nullptr;

    QMap<int, int> attendanceIds;
};