#ifndef MONTHLYINCOMEPAGE_H
#define MONTHLYINCOMEPAGE_H

#include <QDialog>
#include "databaseconnector.h"
#include "adminpage.h"


namespace Ui {
class monthlyincomepage;
}

class monthlyincomepage : public QDialog
{
    Q_OBJECT

public:
    explicit monthlyincomepage(QWidget *parent = nullptr);
    ~monthlyincomepage();

private slots:


    void on_yearSelect_valueChanged(int arg1);

    void on_monthSelect_valueChanged(int arg1);

    void on_selectedButton_clicked();

    void on_pushButton_clicked();

private:
    Ui::monthlyincomepage *ui;
    databaseConnector conn;
    int selectMonth,selectedYear;
    QString selectedMonth;
    float credit,cash , total;
};

#endif // MONTHLYINCOMEPAGE_H
