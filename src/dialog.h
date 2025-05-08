#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTabWidget>
#include <QTableWidget>
#include <QSqlDatabase>
#include <QSqlQuery>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void showGroup(int groupId);

private:
    Ui::Dialog *ui;
    QSqlDatabase db;

    void initDatabase();
    void createTestData();
    QTabWidget* createGroupTab(int groupId);
    void setupGradesTable(QTableWidget *table, int groupId);
    void setupAttendanceTable(QTableWidget *table, int groupId);
};

#endif // DIALOG_H
