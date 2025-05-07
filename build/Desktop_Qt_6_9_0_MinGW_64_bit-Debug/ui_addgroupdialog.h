/********************************************************************************
** Form generated from reading UI file 'addgroupdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDGROUPDIALOG_H
#define UI_ADDGROUPDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddGroupDialog
{
public:
    QVBoxLayout *vboxLayout;
    QLineEdit *groupNumberEdit;
    QTextEdit *studentsEdit;
    QHBoxLayout *hboxLayout;
    QLabel *label_2;
    QSpinBox *courseNumber;
    QLabel *label;
    QSpinBox *lecturesSpinBox;
    QLabel *label1;
    QSpinBox *practicesSpinBox;
    QHBoxLayout *hboxLayout1;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *AddGroupDialog)
    {
        if (AddGroupDialog->objectName().isEmpty())
            AddGroupDialog->setObjectName("AddGroupDialog");
        AddGroupDialog->resize(1000, 500);
        vboxLayout = new QVBoxLayout(AddGroupDialog);
        vboxLayout->setObjectName("vboxLayout");
        groupNumberEdit = new QLineEdit(AddGroupDialog);
        groupNumberEdit->setObjectName("groupNumberEdit");

        vboxLayout->addWidget(groupNumberEdit);

        studentsEdit = new QTextEdit(AddGroupDialog);
        studentsEdit->setObjectName("studentsEdit");

        vboxLayout->addWidget(studentsEdit);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setObjectName("hboxLayout");
        label_2 = new QLabel(AddGroupDialog);
        label_2->setObjectName("label_2");

        hboxLayout->addWidget(label_2);

        courseNumber = new QSpinBox(AddGroupDialog);
        courseNumber->setObjectName("courseNumber");

        hboxLayout->addWidget(courseNumber);

        label = new QLabel(AddGroupDialog);
        label->setObjectName("label");

        hboxLayout->addWidget(label);

        lecturesSpinBox = new QSpinBox(AddGroupDialog);
        lecturesSpinBox->setObjectName("lecturesSpinBox");

        hboxLayout->addWidget(lecturesSpinBox);

        label1 = new QLabel(AddGroupDialog);
        label1->setObjectName("label1");

        hboxLayout->addWidget(label1);

        practicesSpinBox = new QSpinBox(AddGroupDialog);
        practicesSpinBox->setObjectName("practicesSpinBox");

        hboxLayout->addWidget(practicesSpinBox);


        vboxLayout->addLayout(hboxLayout);

        hboxLayout1 = new QHBoxLayout();
        hboxLayout1->setObjectName("hboxLayout1");
        okButton = new QPushButton(AddGroupDialog);
        okButton->setObjectName("okButton");

        hboxLayout1->addWidget(okButton);

        cancelButton = new QPushButton(AddGroupDialog);
        cancelButton->setObjectName("cancelButton");

        hboxLayout1->addWidget(cancelButton);


        vboxLayout->addLayout(hboxLayout1);


        retranslateUi(AddGroupDialog);
        QObject::connect(okButton, &QPushButton::clicked, AddGroupDialog, qOverload<>(&QDialog::accept));
        QObject::connect(cancelButton, &QPushButton::clicked, AddGroupDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddGroupDialog);
    } // setupUi

    void retranslateUi(QDialog *AddGroupDialog)
    {
        AddGroupDialog->setWindowTitle(QCoreApplication::translate("AddGroupDialog", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\263\321\200\321\203\320\277\320\277\321\203", nullptr));
        groupNumberEdit->setPlaceholderText(QCoreApplication::translate("AddGroupDialog", "\320\235\320\276\320\274\320\265\321\200 \320\263\321\200\321\203\320\277\320\277\321\213", nullptr));
        studentsEdit->setPlaceholderText(QCoreApplication::translate("AddGroupDialog", "\320\230\320\274\320\265\320\275\320\260 \321\201\321\202\321\203\320\264\320\265\320\275\321\202\320\276\320\262 (\320\272\320\260\320\266\320\264\320\276\320\265 \321\201 \320\275\320\276\320\262\320\276\320\271 \321\201\321\202\321\200\320\276\320\272\320\270)", nullptr));
        label_2->setText(QCoreApplication::translate("AddGroupDialog", "\320\232\321\203\321\200\321\201:", nullptr));
        label->setText(QCoreApplication::translate("AddGroupDialog", "\320\233\320\265\320\272\321\206\320\270\320\270:", nullptr));
        label1->setText(QCoreApplication::translate("AddGroupDialog", "\320\237\321\200\320\260\320\272\321\202\320\270\320\272\320\270:", nullptr));
        okButton->setText(QCoreApplication::translate("AddGroupDialog", "OK", nullptr));
        cancelButton->setText(QCoreApplication::translate("AddGroupDialog", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddGroupDialog: public Ui_AddGroupDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDGROUPDIALOG_H
