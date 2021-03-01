#ifndef SIGNIN_H
#define SIGNIN_H

#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include<QtDebug>
#include<qfileinfo.h>
#include "customerpage.h"
#include "adminpage.h"
#include "databaseconnector.h"

namespace Ui {
class Signin;
}

class Signin : public QDialog
{
    Q_OBJECT

public:
    int getUserId();
    void setUserId(int id);
    QString getFirstName();
    void setFirstName(QString name);
    explicit Signin(QWidget *parent = nullptr);
    ~Signin();
private slots:

    void on_LoginButton_clicked();

private:
    Ui::Signin *ui;
    int user_id;
    QString userFirstName;
    databaseConnector conn;
};

#endif // SIGNIN_H


