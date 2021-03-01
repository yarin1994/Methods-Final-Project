#ifndef MANAGEPRODUCTS_H
#define MANAGEPRODUCTS_H

#include <QDialog>
#include "databaseconnector.h"
#include "adminpage.h"


namespace Ui {
class manageproducts;
}

class manageproducts : public QDialog
{
    Q_OBJECT

public:
    explicit manageproducts(QWidget *parent = nullptr);
    void showAll();
    ~manageproducts();

private slots:

    void on_DeleteItemBtn_clicked();

    void on_allProds_clicked(const QModelIndex &index);

    void on_priceEditBtn_clicked();

    void on_backBtn_clicked();

private:
    Ui::manageproducts *ui;
    databaseConnector conn;
    QString itemId;

};

#endif // MANAGEPRODUCTS_H
