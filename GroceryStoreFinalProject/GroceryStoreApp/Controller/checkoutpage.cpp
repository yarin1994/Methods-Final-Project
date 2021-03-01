#include "checkoutpage.h"
#include "ui_checkoutpage.h"
#include "finishpage.h"

CheckoutPage::CheckoutPage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckoutPage)
{
    ui->setupUi(this);


}
void CheckoutPage::setUserId(int value){
    user_id=value;
};

void CheckoutPage::setTotalPrice(QString price){
    this->totalPrice=price;
    ui->priceLabel->setText(totalPrice);
};
void CheckoutPage::setCartId(QString cart){
 cart_id=cart;
};
CheckoutPage::~CheckoutPage()
{
    delete ui;
}



void CheckoutPage::on_creditPayment_clicked()
{
    conn.connOpen();
    QString var2 = QString::number(user_id);

    QSqlQuery* qryPayment=new QSqlQuery(conn.mydb);
    qryPayment->prepare("Insert into Payments (cart_id, user_id, payment_method) values('"+cart_id+"','"+var2+"', 'creditCard')");
    qryPayment->exec();
    finish();
    conn.connClose();

}

void CheckoutPage::on_cashPayment_clicked()
{
    conn.connOpen();
    QString var2 = QString::number(user_id);

    QSqlQuery* qryPayment=new QSqlQuery(conn.mydb);
    qryPayment->prepare("Insert into Payments (cart_id, user_id, payment_method) values('"+cart_id+"','"+var2+"', 'cash')");
    qryPayment->exec();
    finish();
    conn.connClose();
}

void CheckoutPage::finish(){
    this->hide();
    finishpage page;
    page.setModal(true);
    page.exec();
}
