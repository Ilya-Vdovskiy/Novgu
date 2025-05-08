#ifndef ADDGROUPDIALOG_H
#define ADDGROUPDIALOG_H

#include <QDialog>

namespace Ui {
class AddGroupDialog;
}

class AddGroupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddGroupDialog(QWidget *parent = nullptr);
    ~AddGroupDialog();

    QString getGroupNumber() const;
    QStringList getStudents() const;
    int getLectures() const;
    int getPractices() const;
    int getCourseNumber() const;

private:
    Ui::AddGroupDialog *ui;
};

#endif // ADDGROUPDIALOG_H
