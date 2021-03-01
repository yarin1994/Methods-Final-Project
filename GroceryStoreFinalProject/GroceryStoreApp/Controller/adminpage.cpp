#include "adminpage.h"
#include "ui_adminpage.h"
#include "todayincomespage.h"
#include "monthlyincomepage.h"
#include "manageproducts.h"

adminPage::adminPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminPage)
{
    ui->setupUi(this);
}

adminPage::~adminPage()
{
    delete ui;
}



void adminPage::on_todayIncome_clicked()
{
    this->hide();
    todayincomespage today;
    today.setModal(true);
    today.todayTotalcalculate();
    today.exec();
}

void adminPage::on_monthlyIncome_clicked()
{
    this->hide();
    monthlyincomepage month;
    month.setModal(true);
    month.exec();
}

void adminPage::on_showProducts_clicked()
{
    this->hide();
    manageproducts manage;
    manage.setModal(true);
    manage.showAll();
    manage.exec();

}
void adminPage::setFirstName(QString name){
    userFirstName=name;
    ui->adminName->setText(userFirstName);
}

