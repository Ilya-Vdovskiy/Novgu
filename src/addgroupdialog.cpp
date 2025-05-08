#include "addgroupdialog.h"
#include "ui_addgroupdialog.h"

AddGroupDialog::AddGroupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddGroupDialog)
{
    ui->setupUi(this);
}

AddGroupDialog::~AddGroupDialog()
{
    delete ui;
}

QString AddGroupDialog::getGroupNumber() const {
    return ui->groupNumberEdit->text();
}

QStringList AddGroupDialog::getStudents() const {
    return ui->studentsEdit->toPlainText().split("\n", Qt::SkipEmptyParts);
}

int AddGroupDialog::getLectures() const {
    return ui->lecturesSpinBox->value();
}

int AddGroupDialog::getPractices() const {
    return ui->practicesSpinBox->value();
}

int AddGroupDialog::getCourseNumber() const {
    return ui->courseNumber->value();
}
