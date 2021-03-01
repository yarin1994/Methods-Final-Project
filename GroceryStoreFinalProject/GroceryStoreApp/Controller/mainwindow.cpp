#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/Users/yarinmizrahi/GroceryStoreApp/images/openPage.png"); // You need to change the image path
    ui->label->setPixmap(pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_login_clicked()
{
    this->hide();
    Signin signin;
    signin.setModal(true);
    signin.exec();
 }

void MainWindow::on_pushButton_signup_clicked()
{
    this->hide();
    Signup  signup;
    signup.setModal(true);
    signup.exec();
}
