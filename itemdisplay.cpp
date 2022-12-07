#include "itemdisplay.h"
#include "ui_itemdisplay.h"
#include "global.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>


itemDisplay::itemDisplay(QWidget *parent) : QDialog(parent), ui(new Ui::itemDisplay)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    // Set up the database
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the query
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);

    // Prepare the query
    query.prepare("SELECT item_purchased, SUM(sales_price* quantity_purchased) AS Total_Price , SUM(quantity_purchased) AS Total_Quantity FROM Sales_Record GROUP BY Item_Purchased ORDER BY Total_Price DESC");
    query.exec();
    model->setQuery(std::move(query));

    // Set the model
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


itemDisplay::~itemDisplay()
{
    delete ui;
}


void itemDisplay::on_searchButton_clicked()
{
    // Set up the database
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the query
    QString item = ui->itemSearchBar->text();
    QSqlQueryModel * model2 = new QSqlQueryModel();
    QSqlQuery query(db);

    // Prepare the query
    query.prepare("SELECT * FROM sales_record WHERE Item_Purchased=(:item)");
    query.bindValue(":item",item);
    query.exec();

    // Set the model
    model2->setQuery(std::move(query));
    ui->tableView->setModel(model2);

    // Set the header file
    QSqlRecord totalSalesAndQuantityRecord;
    int totalSalesIterator = 0;
    double salesPrice = 0;
    int salesQuantity = 0;
    double priceTotal = 0;
    int totalQuantity = 0;

    do 
    {
        totalSalesAndQuantityRecord = model2 -> record(totalSalesIterator);     // Sets record to the row of the iterator in the model
        salesPrice = totalSalesAndQuantityRecord.value(3).toDouble();           // Value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesAndQuantityRecord.value(4).toInt();           // Value at index 4 in the row should be Quantity_Purchased
        priceTotal += salesPrice * salesQuantity;                               // Adds the total price of the item
        totalQuantity += salesQuantity;                                         // Adds the total quantity of the item
        totalSalesIterator++;                                                   // Increments the iterator

    }while (!totalSalesAndQuantityRecord.isNull(3));                            // Loops until the record is null

    // Set the total price and total quantity
    QString finalPriceTotal = finalPriceTotal.number(priceTotal, 'f', 2);
    finalPriceTotal.prepend("Total revenue for item: ");

    // Set the total quantity
    QString finalQuantityTotal =  finalQuantityTotal.number(totalQuantity, 'f', 0);
    finalQuantityTotal.prepend("Total quantity for item: ");

    // Set the labels
    ui->itemQuantityTotal->setText(finalQuantityTotal);
    ui->itemPriceTotal->setText(finalPriceTotal);
}


void itemDisplay::on_pushButton_clicked()
{
    this->close();
}

