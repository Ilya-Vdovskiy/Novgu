#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QSpinBox>
#include <QCheckBox>
#include <QSqlError>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);

    initDatabase();
    createTestData();

    connect(ui->btnGroup1, &QPushButton::clicked, this, &Dialog::showGroup1);
    connect(ui->btnGroup2, &QPushButton::clicked, this, &Dialog::showGroup2);
    qDebug() << "Кнопки подключены";
}

Dialog::~Dialog() {
    delete ui;
    db.close();
}

void Dialog::initDatabase() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("students1.db");

    if (!db.open()) {
        qDebug() << "Ошибка подключения к БД:" << db.lastError().text();
    }
}

void Dialog::createTestData() {
    QSqlQuery query;

    if (!query.exec("CREATE TABLE IF NOT EXISTS students ("
                    "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                    "name TEXT NOT NULL, "
                    "group_id INTEGER NOT NULL)")) {
        qDebug() << "Ошибка создания таблицы:" << query.lastError().text();
    }

    query.exec("INSERT OR IGNORE INTO students (name, group_id) VALUES "
               "('Иванов Никита', 1), "
               "('Вдовский Илья', 1), "
               "('Кобылинский Сергей', 2)");
}

void Dialog::showGroup1() {
    if(ui->stackedWidget->count() > 0) {
        QWidget* oldWidget = ui->stackedWidget->currentWidget();
        ui->stackedWidget->removeWidget(oldWidget);
        delete oldWidget;
    }

    QTabWidget* groupTabs = createGroupTab(1);
    ui->stackedWidget->addWidget(groupTabs);
    ui->stackedWidget->setCurrentWidget(groupTabs);
    qDebug() << "Вкладки для группы 1 созданы";
}

void Dialog::showGroup2() {
    if(ui->stackedWidget->count() > 0) {
        QWidget* oldWidget = ui->stackedWidget->currentWidget();
        ui->stackedWidget->removeWidget(oldWidget);
        delete oldWidget;
    }

    QTabWidget* groupTabs = createGroupTab(2);
    ui->stackedWidget->addWidget(groupTabs);
    ui->stackedWidget->setCurrentWidget(groupTabs);
}

QTabWidget* Dialog::createGroupTab(int groupId) {
    QTabWidget *tabWidget = new QTabWidget;

    QWidget *gradesTab = new QWidget;
    QVBoxLayout *gradesLayout = new QVBoxLayout(gradesTab);
    QTableWidget *gradesTable = new QTableWidget;
    setupGradesTable(gradesTable, groupId);
    QPushButton *saveGradesButton = new QPushButton("Сохранить оценки");
    gradesLayout->addWidget(gradesTable);
    gradesLayout->addWidget(saveGradesButton);
    tabWidget->addTab(gradesTab, "Оценки");

    QWidget *attendanceTab = new QWidget;
    QVBoxLayout *attendanceLayout = new QVBoxLayout(attendanceTab);
    QTableWidget *attendanceTable = new QTableWidget;
    setupAttendanceTable(attendanceTable, groupId);
    QPushButton *saveAttendanceButton = new QPushButton("Сохранить посещаемость");
    attendanceLayout->addWidget(attendanceTable);
    attendanceLayout->addWidget(saveAttendanceButton);
    tabWidget->addTab(attendanceTab, "Посещаемость");

    return tabWidget;
}

void Dialog::setupGradesTable(QTableWidget *table, int groupId) {
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"Студент", "Практика 1", "Практика 2", "Практика 3", "Практика 4", "Итого"});

    QSqlQuery query;
    query.prepare("SELECT name FROM students WHERE group_id = ?");
    query.addBindValue(groupId);
    query.exec();

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        QString name = query.value(0).toString();

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        nameItem->setFlags(nameItem->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, 0, nameItem);

        QSpinBox *prak1Spin = new QSpinBox;
        prak1Spin->setRange(-5, 100);
        table->setCellWidget(row, 1, prak1Spin);

        QSpinBox *prak2Spin = new QSpinBox;
        prak2Spin->setRange(-5, 100);
        table->setCellWidget(row, 2, prak2Spin);

        QSpinBox *prak3Spin = new QSpinBox;
        prak3Spin->setRange(-5, 100);
        table->setCellWidget(row, 3, prak3Spin);

        QSpinBox *prak4Spin = new QSpinBox;
        prak4Spin->setRange(-5, 100);
        table->setCellWidget(row, 4, prak4Spin);

        QTableWidgetItem *totalItem = new QTableWidgetItem("0");
        totalItem->setFlags(totalItem->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, 5, totalItem);

        connect(prak1Spin, QOverload<int>::of(&QSpinBox::valueChanged), [=](){
            int total = prak1Spin->value() + prak2Spin->value() + prak3Spin->value() + prak4Spin->value();
            table->item(row, 5)->setText(QString::number(total));
        });

        connect(prak2Spin, QOverload<int>::of(&QSpinBox::valueChanged), [=](){
            int total = prak1Spin->value() + prak2Spin->value() + prak3Spin->value() + prak4Spin->value();
            table->item(row, 5)->setText(QString::number(total));
        });

        connect(prak3Spin, QOverload<int>::of(&QSpinBox::valueChanged), [=](){
            int total = prak1Spin->value() + prak2Spin->value() + prak3Spin->value() + prak4Spin->value();
            table->item(row, 5)->setText(QString::number(total));
        });

        connect(prak4Spin, QOverload<int>::of(&QSpinBox::valueChanged), [=](){
            int total = prak1Spin->value() + prak2Spin->value() + prak3Spin->value() + prak4Spin->value();
            table->item(row, 5)->setText(QString::number(total));
        });

        row++;
    }
}

void Dialog::setupAttendanceTable(QTableWidget *table, int groupId) {
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"Студент", "Лекция 1", "Лекция 2", "Лекция 3", "Лекция 4", "Пропущено"});

    QSqlQuery query;
    query.prepare("SELECT name FROM students WHERE group_id = ?");
    query.addBindValue(groupId);
    query.exec();

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        QString name = query.value(0).toString();

        QTableWidgetItem *nameItem = new QTableWidgetItem(name);
        nameItem->setFlags(nameItem->flags() ^ Qt::ItemIsEditable);
        table->setItem(row, 0, nameItem);

        QCheckBox *lek1 = new QCheckBox;
        table->setCellWidget(row, 1, lek1);

        QCheckBox *lek2 = new QCheckBox;
        table->setCellWidget(row, 2, lek2);

        QCheckBox *lek3 = new QCheckBox;
        table->setCellWidget(row, 3, lek3);

        QCheckBox *lek4 = new QCheckBox;
        table->setCellWidget(row, 4, lek4);

        QLabel *missedLabel = new QLabel("0");
        auto updateMissed = [=]() {
            int missed = 0;
            if (!lek1->isChecked()) missed++;
            if (!lek2->isChecked()) missed++;
            if (!lek3->isChecked()) missed++;
            if (!lek4->isChecked()) missed++;
            missedLabel->setText(QString::number(missed));
        };
        table->setCellWidget(row, 5, missedLabel);

        connect(lek1, &QCheckBox::stateChanged, updateMissed);
        connect(lek2, &QCheckBox::stateChanged, updateMissed);
        connect(lek3, &QCheckBox::stateChanged, updateMissed);
        connect(lek4, &QCheckBox::stateChanged, updateMissed);

        row++;
    }
}
