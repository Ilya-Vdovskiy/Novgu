/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QSpacerItem *verticalSpacer;
    QPushButton *btnGroup1;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnGroup2;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnGroup3;
    QSpacerItem *verticalSpacer_4;
    QPushButton *btnGroup4;
    QSpacerItem *verticalSpacer_5;
    QPushButton *btnGroup5;
    QSpacerItem *verticalSpacer_6;
    QStackedWidget *stackedWidget;
    QWidget *page_5;
    QWidget *page_6;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1313, 800);
        horizontalLayoutWidget = new QWidget(Dialog);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(-1, -1, 1321, 801));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(7);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setContentsMargins(0, -1, -1, -1);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label->setFont(font);

        verticalLayout_6->addWidget(label);

        verticalSpacer = new QSpacerItem(0, 10, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer);

        btnGroup1 = new QPushButton(horizontalLayoutWidget);
        btnGroup1->setObjectName("btnGroup1");

        verticalLayout_6->addWidget(btnGroup1);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_2);

        btnGroup2 = new QPushButton(horizontalLayoutWidget);
        btnGroup2->setObjectName("btnGroup2");

        verticalLayout_6->addWidget(btnGroup2);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_3);

        btnGroup3 = new QPushButton(horizontalLayoutWidget);
        btnGroup3->setObjectName("btnGroup3");

        verticalLayout_6->addWidget(btnGroup3);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_4);

        btnGroup4 = new QPushButton(horizontalLayoutWidget);
        btnGroup4->setObjectName("btnGroup4");

        verticalLayout_6->addWidget(btnGroup4);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_5);

        btnGroup5 = new QPushButton(horizontalLayoutWidget);
        btnGroup5->setObjectName("btnGroup5");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnGroup5->sizePolicy().hasHeightForWidth());
        btnGroup5->setSizePolicy(sizePolicy);
        btnGroup5->setMinimumSize(QSize(120, 0));

        verticalLayout_6->addWidget(btnGroup5);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);


        horizontalLayout_4->addLayout(verticalLayout_6);

        stackedWidget = new QStackedWidget(horizontalLayoutWidget);
        stackedWidget->setObjectName("stackedWidget");
        page_5 = new QWidget();
        page_5->setObjectName("page_5");
        stackedWidget->addWidget(page_5);
        page_6 = new QWidget();
        page_6->setObjectName("page_6");
        stackedWidget->addWidget(page_6);

        horizontalLayout_4->addWidget(stackedWidget);


        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "\320\223\321\200\321\203\320\277\320\277\321\213:", nullptr));
        btnGroup1->setText(QCoreApplication::translate("Dialog", "3091", nullptr));
        btnGroup2->setText(QCoreApplication::translate("Dialog", "3092", nullptr));
        btnGroup3->setText(QCoreApplication::translate("Dialog", "3093", nullptr));
        btnGroup4->setText(QCoreApplication::translate("Dialog", "3094", nullptr));
        btnGroup5->setText(QCoreApplication::translate("Dialog", "3094\320\267\320\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
