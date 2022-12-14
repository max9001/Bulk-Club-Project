#include "newpurchase.h"
#include "ui_newpurchase.h"
#include "global.h"

newPurchase::newPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::newPurchase)
{
    ui->setupUi(this);
    db.setDatabaseName(Path::getDBPath());
    db.open();

    QSqlQueryModel * model = new QSqlQueryModel();

    QSqlQuery query(db);

    query.prepare("SELECT * FROM Inventory");
    query.exec();
    model->setQuery(std::move(query));
    int inventoryIterator = 0;
    QSqlRecord record;
    QStringList itemList;
    do{
        record = model->record(inventoryIterator);
        itemList.append(record.value(0).toString());
        inventoryIterator++;
    }while(!record.isNull(0));
    ui->itemBox->addItems(itemList);
}

newPurchase::~newPurchase()
{
    delete ui;
}


void newPurchase::on_cancelButton_clicked()
{
    close();
}


void newPurchase::on_SubmitButton_clicked()
{
    QString purchaseDate = ui->dateLineEdit->text();
    int memberId = ui->idLineEdit->text().toInt();
    int quantity = ui->quantityLineEdit->text().toInt();
    QString itemName = ui->itemBox->currentText();
    QSqlRecord record;
    db.setDatabaseName(Path::getDBPath());
    db.open();

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT Product_Price FROM Inventory WHERE Product_Name=(:name)");
    query.bindValue(":name",itemName);
    query.exec();
    model->setQuery(std::move(query));
    record = model->record(0);
    double price = record.value(0).toDouble();
    // qDebug() << record.value(0).toString();

    QSqlQuery query2(db);
    query2.prepare("INSERT INTO Sales_Record VALUES ((:date),(:id),(:name),(:price),(:quantity))");
    query2.bindValue(":date",purchaseDate);
    query2.bindValue(":id",memberId);
    query2.bindValue(":name",itemName);
    query2.bindValue(":price",price);
    query2.bindValue(":quantity",quantity);
    query2.exec();
}

