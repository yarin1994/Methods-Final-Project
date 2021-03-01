#include "todayincomespage.h"
#include "ui_todayincomespage.h"

todayincomespage::todayincomespage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::todayincomespage)
{
    ui->setupUi(this);

}
void todayincomespage:: getCurrentDate(){
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

   currDay= timePtr->tm_mday;
   currMonth =timePtr->tm_mon+1;
   currYear =timePtr->tm_year+1900;
   if(currMonth<10 && currDay<10){
     currentDate= QString::number(currYear)+"-0"+QString::number(currMonth)+"-0"+QString::number(currDay);
   }
   else if(currMonth<10){
      currentDate= QString::number(currYear)+"-0"+QString::number(currMonth)+"-"+QString::number(currDay);
   }
   else if(currDay<10)
   {
      currentDate= QString::number(currYear)+"-"+QString::number(currMonth)+"-0"+QString::number(currDay);
   }
   else{
   currentDate= QString::number(currYear)+"-"+QString::number(currMonth)+"-"+QString::number(currDay);
   }
}
void todayincomespage::todayTotalcalculate(){
    getCurrentDate();
    conn.connOpen();
    QSqlQuery qry;
    qry.prepare("SELECT sum(pu.item_price*pu.quantity) from Purchase pu JOIN Payments pa on pu.date BETWEEN '"+currentDate+" 00:00:00' AND '"+currentDate+" 23:59:59'  and pa.cart_id = pu.cart_id WHERE pa.payment_method = 'creditCard'");
    QSqlQueryModel * modalPrice=new QSqlQueryModel();
    qry.exec();
    modalPrice->setQuery(qry);
    credit = modalPrice->record(0).value(0).toFloat();

    qry.prepare("SELECT sum(pu.item_price*pu.quantity) from Purchase pu JOIN Payments pa on pu.date BETWEEN  '"+currentDate+" 00:00:00' AND '"+currentDate+" 23:59:59'  and pa.cart_id = pu.cart_id WHERE pa.payment_method = 'cash'");
    qry.exec();
    modalPrice->setQuery(qry);
    cash = modalPrice->record(0).value(0).toFloat();

    ui->TodayCredit->setText(QString::number(credit));
    ui->todayCash->setText(QString::number(cash));
    total= credit + cash;
     qry.exec("Insert into dailyIncomes (date, credit, cash,total) values('"+currentDate+"','"+QString::number(credit)+"','"+QString::number(cash)+"','"+QString::number(total)+"')");
    ui->TodayTotal->setText(QString::number(total));

    conn.connClose();
}
todayincomespage::~todayincomespage()
{
    delete ui;
}

void todayincomespage::on_gobackButton_clicked()
{
        this->hide();
        adminPage admin;
        admin.exec();

}
