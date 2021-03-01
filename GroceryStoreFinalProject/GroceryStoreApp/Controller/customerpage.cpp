#include "customerpage.h"
#include "ui_customerpage.h"

customerpage::customerpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customerpage)
{
    ui->setupUi(this);


    QSqlQueryModel * modalPharm=new QSqlQueryModel();
    QSqlQueryModel * modalDairy=new QSqlQueryModel();
    QSqlQueryModel * modalCleaning=new QSqlQueryModel();
    QSqlQueryModel * modalAlcohol=new QSqlQueryModel();

    conn.connOpen();
        QSqlQuery* qryPharm=new QSqlQuery(conn.mydb);
        QSqlQuery* qryDairy=new QSqlQuery(conn.mydb);
        QSqlQuery* qryCleaning=new QSqlQuery(conn.mydb);
        QSqlQuery* qryaAlcohol=new QSqlQuery(conn.mydb);
        QSqlQuery* qryTemp=new QSqlQuery(conn.mydb);

        qryTemp->prepare("select (max(cart_id)+1) from Purchase" );
        qryTemp->exec();
        qryTemp->next();
        maxCartId = qryTemp->value(0).toString();

        qryPharm->prepare("select name, price from Products where department='Pharm'" );
        qryPharm->exec();
        modalPharm->setQuery(*qryPharm);
        ui->tableProducts->setModel(modalPharm);

        qryDairy->prepare("select name, price from Products where department='Dairy'");
        qryDairy->exec();
        modalDairy->setQuery(*qryDairy);
        ui->tableDairy->setModel(modalDairy);

        qryCleaning->prepare("select name, price from Products where department='Cleaning'");
        qryCleaning->exec();
        modalCleaning->setQuery(*qryCleaning);
        ui->tableCleaning->setModel(modalCleaning);

        qryaAlcohol->prepare("select name, price from Products where department='Alcohol'");
        qryaAlcohol->exec();
        modalAlcohol->setQuery(*qryaAlcohol);
        ui->tableAlcohol->setModel(modalAlcohol);

}


customerpage::~customerpage()
{
    conn.connClose();
    delete ui;
}

void customerpage::on_addButton_clicked()
{
    bool isAlreadyExist = false;
    QSqlQuery qryCart;
    QString var2 = QString::number(user_id);
    qryCart.prepare("Select quantity from Purchase where cart_id = '"+maxCartId+"' and item_value = '"+itemValue+"'");

    if(!qryCart.exec()){
    }
    isAlreadyExist=qryCart.next();

    if(isAlreadyExist){
        qryCart.exec("UPDATE Purchase SET quantity=quantity+1 WHERE cart_id='"+maxCartId+"' and item_value='"+itemValue+"'");
    }
    else{
      qryCart.exec("Insert into Purchase (cart_id, user_id, item_value, item_price,quantity) values('"+maxCartId+"','"+var2+"','"+itemValue+"','"+price+"',1)");
    }

    setShopModal();

    QSqlQueryModel * modalPrice=new QSqlQueryModel();
    QSqlQuery* qryPrice=new QSqlQuery(conn.mydb);

    qryPrice->prepare("Select sum(item_price*quantity) as Total from Purchase where cart_id = "+ maxCartId);
    qryPrice->exec();
    modalPrice->setQuery(*qryPrice);

    totalPrice = modalPrice->record(0).value(0).toString();
    ui->TotalPriceValue->setText(totalPrice);


}


void customerpage::on_tableProducts_pressed(const QModelIndex &index)
{
    int prow = index.row();
    itemValue = ui->tableProducts->model()->index(prow,0).data().toString();
    price = ui->tableProducts->model()->index(prow,1).data().toString();

}


void customerpage::on_tableDairy_clicked(const QModelIndex &index)
{
    int prow = index.row();
    itemValue = ui->tableDairy->model()->index(prow,0).data().toString();
    price = ui->tableDairy->model()->index(prow,1).data().toString();

}

void customerpage::on_tableCleaning_clicked(const QModelIndex &index)
{
    int prow = index.row();
    itemValue = ui->tableCleaning->model()->index(prow,0).data().toString();
    price = ui->tableCleaning->model()->index(prow,1).data().toString();
}

void customerpage::on_tableAlcohol_clicked(const QModelIndex &index)
{
    int prow = index.row();
    itemValue = ui->tableAlcohol->model()->index(prow,0).data().toString();
    price = ui->tableAlcohol->model()->index(prow,1).data().toString();

}

void customerpage::setUserId(int value){
    user_id= value;
}

void customerpage::setItemId(QString value){
    this->itemId = value;
}




void customerpage::on_delete_button_clicked()
{
    bool quantityIsOne = false;
    QSqlQuery qryCart;
    qryCart.prepare("Select quantity from Purchase where cart_id = '"+maxCartId+"' and item_value = '"+itemValue+"' and quantity > 1");
    qryCart.exec();

    quantityIsOne=qryCart.next();

    if(quantityIsOne){
       qryCart.exec("UPDATE Purchase SET quantity=quantity-1 WHERE cart_id='"+maxCartId+"' and item_value='"+itemValue+"'");
    }
    else{
        qryCart.exec("Delete from Purchase where cart_id='"+maxCartId+"' and item_value='"+itemValue+"'");
    }
    setShopModal();


}

void customerpage::setShopModal()
{
    QSqlQueryModel * modalShop=new QSqlQueryModel();
    QSqlQuery* qryShop=new QSqlQuery(conn.mydb);
    qryShop->prepare("Select item_value as item, item_price as price, quantity from Purchase where cart_id = "+ maxCartId);
    qryShop->exec();
    modalShop->setQuery(*qryShop);
    ui->table_cart->setModel(modalShop);
}

void customerpage::on_table_cart_clicked(const QModelIndex &index)
{
    int prow = index.row();
    itemValue = ui->table_cart->model()->index(prow,0).data().toString();
}

void customerpage::on_checkout_clicked()
{

    this->hide();
    CheckoutPage check;
    check.setModal(true);
    check.setUserId(user_id);
    check.setCartId(maxCartId);
    check.setTotalPrice(totalPrice);
    check.exec();
}


