#include "admin.h"
#include "ui_admin.h"
#include "mainwindow.h"
#include "QMessageBox"

Admin::Admin(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Admin)
{
    ui->setupUi(this);
}

Admin::~Admin()
{
    delete ui;
}

void Admin::on_Exit_clicked()
{
    hide();
    MainWindow *reg = new MainWindow(this);
    reg->show();
}


void Admin::on_AddNewGroup_clicked() {
    AddGroupDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString groupNumber = dialog.getGroupNumber();
        int targetColumn = dialog.getCourseNumber();

        QPushButton* newGroupButton = new QPushButton(groupNumber, this);
        newGroupButton->setFixedSize(100, 30);

        int targetRow = 0;
        while (ui->gridLayout->itemAtPosition(targetRow, targetColumn) != nullptr) {
            targetRow++;
        }

        if (isGroupExists(groupNumber)) {
            QMessageBox::warning(this, "Ошибка", "Группа уже существует!");
            return;
        }

        ui->gridLayout->addWidget(newGroupButton, targetRow, targetColumn);
    }
}

bool Admin::isGroupExists(const QString& groupNumber) {
    for (auto* item : ui->gridLayout->children()) {
        if (auto* button = qobject_cast<QPushButton*>(item)) {
            if (button->text() == groupNumber) return true;
        }
    }
    return false;
}
