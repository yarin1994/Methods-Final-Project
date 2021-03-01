#ifndef FINISHPAGE_H
#define FINISHPAGE_H

#include <QDialog>
#include "checkoutpage.h"
namespace Ui {
class finishpage;
}

class finishpage : public QDialog
{
    Q_OBJECT

public:
    explicit finishpage(QWidget *parent = nullptr);
    ~finishpage();

private slots:

    void on_ByeBtn_clicked();

    void on_shopAgainBtn_clicked();

private:
    Ui::finishpage *ui;
};

#endif // FINISHPAGE_H
