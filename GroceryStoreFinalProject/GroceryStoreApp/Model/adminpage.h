#ifndef ADMINPAGE_H
#define ADMINPAGE_H

#include <QDialog>


namespace Ui {
class adminPage;
}

class adminPage : public QDialog
{
    Q_OBJECT

public:
    explicit adminPage(QWidget *parent = nullptr);
    void setFirstName(QString name);
    ~adminPage();

private slots:

    void on_todayIncome_clicked();

    void on_monthlyIncome_clicked();

    void on_showProducts_clicked();



private:
    Ui::adminPage *ui;
    QString userFirstName;
};

#endif // ADMINPAGE_H
