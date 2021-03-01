#include "manageproducts.h"
#include "ui_manageproducts.h"
#include "adminpage.h"

manageproducts::manageproducts(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::manageproducts)
{
    ui->setupUi(this);
    showAll();



}
void manageproducts::showAll(){
    conn.connOpen();
    QSqlQuery* allQry=new QSqlQuery(conn.mydb);
    allQry->prepare("select * from Products");
    QSqlQueryModel * modalQry=new QSqlQueryModel();
    allQry->exec();
    modalQry->setQuery(*allQry);
    ui->allProds->setModel(modalQry);

    conn.connClose();
}
manageproducts::~manageproducts()
{
    delete ui;
}



void manageproducts::on_DeleteItemBtn_clicked()
{
    conn.connOpen();
    QSqlQuery* DelQry=new QSqlQuery(conn.mydb);
    DelQry->prepare("Delete from Products where id='"+itemId+"'");
    QSqlQueryModel * modalDel=new QSqlQueryModel();
    DelQry->exec();
    modalDel->setQuery(*DelQry);
    ui->allProds->setModel(modalDel);
    showAll();
    conn.connClose();
}

void manageproducts::on_allProds_clicked(const QModelIndex &index)
{
    int prow = index.row();
    itemId = ui->allProds->model()->index(prow,0).data().toString();
}

void manageproducts::on_priceEditBtn_clicked()
{
    QString name, price, quantity, department;

    name = ui->prodName->text();
    price = ui->prodPrice->text();
    quantity= ui->prodQuantity->text();
    department= ui->prodDepartment->currentText();

    conn.connOpen();
    QSqlQuery* NewQry=new QSqlQuery(conn.mydb);
    NewQry->prepare("Insert into Products ( name, price, quantity, department) values('"+name+"','"+price+"','"+quantity+"','"+department+"')");
    QSqlQueryModel * modalAdd=new QSqlQueryModel();
    NewQry->exec();
    modalAdd->setQuery(*NewQry);
    ui->allProds->setModel(modalAdd);
    showAll();
    conn.connClose();

}

void manageproducts::on_backBtn_clicked()
{
    this->hide();
    adminPage admin;
    admin.exec();
}
