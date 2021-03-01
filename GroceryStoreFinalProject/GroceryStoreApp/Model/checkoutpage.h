#ifndef CHECKOUTPAGE_H
#define CHECKOUTPAGE_H
#include "customerpage.h"
#include "databaseconnector.h"
#include <QDialog>

namespace Ui {
class CheckoutPage;
}

class CheckoutPage : public QDialog
{
    Q_OBJECT

public:
    explicit CheckoutPage(QWidget *parent = nullptr);
    void setUserId(int value);
     void setTotalPrice(QString price);
     void setCartId(QString cart);
     void finish();
    ~CheckoutPage();


private slots:
     void on_creditPayment_clicked();

     void on_cashPayment_clicked();

private:
    databaseConnector conn;
    Ui::CheckoutPage *ui;
    int user_id;
    QString totalPrice,cart_id;
};

#endif // CHECKOUTPAGE_H
