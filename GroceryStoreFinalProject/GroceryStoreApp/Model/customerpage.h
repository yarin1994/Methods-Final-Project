#ifndef CUSTOMERPAGE_H
#define CUSTOMERPAGE_H

#include <QDialog>
#include <QGridLayout>
#include <QLabel>
#include <QWidget>
#include <time.h>
#include <stdlib.h>
#include "databaseconnector.h"
#include "signin.h"
#include "checkoutpage.h"

using namespace std;
namespace Ui {
class customerpage;
}

class customerpage : public QDialog
{
    Q_OBJECT

public:
    explicit customerpage(QWidget *parent = nullptr);
    void setUserId(int value);
    void setItemId(QString value);
    ~customerpage();

private slots:


    void on_addButton_clicked();
    void on_tableProducts_pressed(const QModelIndex &index);
    void on_tableDairy_clicked(const QModelIndex &index);
    void on_tableCleaning_clicked(const QModelIndex &index);
    void on_tableAlcohol_clicked(const QModelIndex &index);
    void on_delete_button_clicked();
    void on_table_cart_clicked(const QModelIndex &index);
    void setShopModal();
    void on_checkout_clicked();

private:
    databaseConnector conn;
    Ui::customerpage *ui;
    int user_id;
    QString itemId, itemValue, price,totalPrice,maxCartId;

};

#endif // CUSTOMERPAGE_H
