#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include<QtDebug>
#include<qfileinfo.h>
#include "customerpage.h"
#include "adminpage.h"
#include "databaseconnector.h"


namespace Ui {
class Signup;
}

class Signup : public QDialog
{
    Q_OBJECT

public:
    QSqlDatabase mydb;

    explicit Signup(QWidget *parent = nullptr);
    ~Signup();

private slots:
    void on_signupBtn_clicked();

private:
    Ui::Signup *ui;

};

#endif // SIGNUP_H
