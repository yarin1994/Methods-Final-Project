#include "finishpage.h"
#include "ui_finishpage.h"
#include "checkoutpage.h"
#include "customerpage.h"

finishpage::finishpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finishpage)
{
    ui->setupUi(this);
}

finishpage::~finishpage()
{
    delete ui;
}



void finishpage::on_ByeBtn_clicked()
{
    this->close();
}

void finishpage::on_shopAgainBtn_clicked()
{
    this->hide();
    customerpage customer;
    customer.setModal(true);
    customer.exec();
}
