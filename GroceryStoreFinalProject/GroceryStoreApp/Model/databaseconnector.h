#ifndef DATABASECONNECTOR_H
#define DATABASECONNECTOR_H
#include <QDialog>
#include <QMainWindow>
#include <QtSql>
#include<QtDebug>
#include<qfileinfo.h>

class databaseConnector
{
public:
    QSqlDatabase mydb;
    databaseConnector();
    void connClose(){
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }
    bool connOpen()
    {
        mydb = QSqlDatabase::addDatabase("QSQLITE");

        mydb.setDatabaseName("/Users/yarinmizrahi/Desktop/database.db"); // You need to change the DB path for connection

        if(!mydb.open()){
            qDebug()<<("Faild to open the table");
            return false;
        }
        else{
            return true;
            }
    }

};

#endif // DATABASECONNECTOR_H
