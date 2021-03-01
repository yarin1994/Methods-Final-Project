#include "signup.h"
#include "ui_signup.h"
#include "signin.h"
#include <QMessageBox>

Signup::Signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signup)
{
    ui->setupUi(this);
}

Signup::~Signup()
{
    delete ui;
}



void Signup::on_signupBtn_clicked()
{
    databaseConnector conn;
    QString Fname, Lname, Email, Password;

    Fname = ui->lineEdit_firstname->text();
    Lname = ui->lineEdit_lastname->text();
    Email= ui->lineEdit_email->text();
    Password= ui->lineEdit_password->text();



    if(!conn.connOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    QSqlQuery qry;
    if(qry.exec("Insert into Login (ID, fName, lName,Email,Password) values((SELECT max(ID) FROM Login) +1 ,'"+Fname+"','"+Lname+ "','"+Email+"' , '"+Password+"')")){
        this->hide();
        customerpage customer;
        customer.setModal(true);
        customer.exec();
        conn.connClose();
    }
    else{
        QMessageBox::critical(this,tr("error::"),qry.lastError().text());

    }
}
