#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
   QString login = ui->login->text();
   QString password = ui->password->text();

   if (login == "admin" && password == "admin") {
        hide();
        admin = new Admin(this);
        admin->show();
    } else {
        hide();
        table = new Dialog(this);
        table->show();
    }

}

