#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/Irfan Rahman/OneDrive/Desktop/HP image/b1.jpg");
    int w = ui->B1->width();
    int h = ui->B1->height();
    ui->B1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_LogIn_clicked()
{
    QString username = ui->lineEdit_un->text();
    QString password = ui->lineEdit_ps->text();

    if(username == "Bmcc" && password == "CSC211H") {
//        QMessageBox::information(this,"LogIn", "Username and password is correct");
        hide();
        userInfo = new UserInfo(this);
        userInfo->show();
    }
    else {
        QMessageBox::warning(this,"LogIn", "Username and passwords is not correct");
    }
}



