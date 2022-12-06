#ifndef NEWPURCHASE_H
#define NEWPURCHASE_H

#include <QWidget>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlDatabase>

namespace Ui {
class newPurchase;
}

class newPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit newPurchase(QWidget *parent = nullptr);
    ~newPurchase();

private slots:


    void on_cancelButton_clicked();

    void on_SubmitButton_clicked();

private:
    Ui::newPurchase *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // NEWPURCHASE_H
