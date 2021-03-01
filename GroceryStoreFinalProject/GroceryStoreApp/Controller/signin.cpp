#include "signin.h"
#include "ui_signin.h"

Signin::Signin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Signin)
{
    ui->setupUi(this);

    QPixmap pix("/Users/yarinmizrahi/GroceryStoreApp/images/123.png"); // You need to change the image path in order to see it
    ui->img_signin->setPixmap(pix);

    if(!conn.connOpen())
        qDebug()<<("Faild to open the database");
    else
        qDebug()<<("Connected...");

}

Signin::~Signin()
{
    delete ui;
}


void Signin::on_LoginButton_clicked()
{
    QString Email, Password;

    Email= ui->lineEdit_email->text();
    Password= ui->lineEdit_password->text();

    if(!conn.mydb.isOpen()){
        qDebug()<<"Failed to open the database";
        return;
    }

    conn.connOpen();
    QSqlQuery qry;
    int admin = 1;

    if(qry.exec("select isAdmin,ID,fName from Login where Email='"+Email+"'and Password='"+Password+"'") == admin){
        QStringList tmp;
        int count = 0;
        while(qry.next()){
            count++;
            QSqlRecord rec = qry.record();
            setUserId(rec.value(1).toInt());
            setFirstName(rec.value(2).toString());
            tmp<<rec.value(0).toString();

        }
           if(count == 1){
               ui->label->setText("username and password are correct");
               conn.connClose();
               if(tmp[0]=="true"){
                   this->hide();
                   adminPage admin;
                   admin.setModal(true);
                   admin.setFirstName(userFirstName);
                   admin.exec();
               }
               else{
                   this->hide();
                   customerpage customer;
                   customer.setModal(true);
                   customer.setUserId(user_id);
                   customer.exec();

               }
           }
           if(count > 1){
               ui->label->setText("Duplicate username and password");
           }
           if(count < 1){
               ui->label->setText("username and password are not correct");
           }
       }

    else
         ui->label->setText("1");
}

int Signin::getUserId(){
    return user_id;
}
QString Signin::getFirstName(){
    return userFirstName;
}
void Signin::setFirstName(QString name){
  userFirstName=name;
}


void Signin::setUserId(int id){
    user_id = id;
}


