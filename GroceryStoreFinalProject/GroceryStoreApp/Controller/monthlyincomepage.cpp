#include "monthlyincomepage.h"
#include "ui_monthlyincomepage.h"

monthlyincomepage::monthlyincomepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::monthlyincomepage)
{
    ui->setupUi(this);
}

monthlyincomepage::~monthlyincomepage()
{
    delete ui;
}

void monthlyincomepage::on_yearSelect_valueChanged(int arg1)
{
    selectedYear= arg1;
}

void monthlyincomepage::on_monthSelect_valueChanged(int arg1)
{
    selectMonth= arg1;
    selectedMonth=QString::number(selectMonth);
    if(selectMonth<10){
        selectedMonth="0"+QString::number(selectMonth);
    }
    else selectedMonth=QString::number(selectMonth);
}



void monthlyincomepage::on_selectedButton_clicked()
{
    conn.connOpen();

    QSqlQuery qry;
    qry.prepare("select sum(credit) from dailyIncomes where date BETWEEN '"+QString::number(selectedYear)+"-"+selectedMonth+"-01'  and '"+QString::number(selectedYear)+"-"+selectedMonth+"-31'");
    QSqlQueryModel * modalPrice=new QSqlQueryModel();
    qry.exec();
    modalPrice->setQuery(qry);
    credit = modalPrice->record(0).value(0).toFloat();

    qry.prepare("select sum(cash) from dailyIncomes where date BETWEEN '"+QString::number(selectedYear)+"-"+selectedMonth+"-01' and '"+QString::number(selectedYear)+"-"+selectedMonth+"-31'");
    qry.exec();
    modalPrice->setQuery(qry);
    cash = modalPrice->record(0).value(0).toFloat();

    ui->monthlyCash->setText(QString::number(cash));
    ui->monthlyCredit->setText(QString::number(credit));
    total= credit + cash;

    ui->monthlyIncomes->setText(QString::number(total));

    conn.connClose();
}

void monthlyincomepage::on_pushButton_clicked()
{
    this->hide();
    adminPage admin;
    admin.exec();
}
