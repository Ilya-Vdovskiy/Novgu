#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include "addgroupdialog.h"

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_Exit_clicked();
    void on_AddNewGroup_clicked();
    bool isGroupExists(const QString& groupNumber);

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
