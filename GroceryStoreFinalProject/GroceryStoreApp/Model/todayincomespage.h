#ifndef TODAYINCOMESPAGE_H
#define TODAYINCOMESPAGE_H

#include <QDialog>
#include "databaseconnector.h"
#include <ctime>
#include "adminpage.h"

using namespace std;

namespace Ui {
class todayincomespage;
}

class todayincomespage : public QDialog
{
    Q_OBJECT

public:
    explicit todayincomespage(QWidget *parent = nullptr);
    void getCurrentDate();
    void todayTotalcalculate();
    ~todayincomespage();


private slots:
    void on_gobackButton_clicked();

private:
    Ui::todayincomespage *ui;
    databaseConnector conn;
    int currDay, currMonth,currYear;
    float credit,cash , total;
    QString currentDate;
};

#endif // TODAYINCOMESPAGE_H
