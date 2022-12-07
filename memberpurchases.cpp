#include "memberpurchases.h"
#include "ui_memberpurchases.h"
#include "global.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

memberPurchases::memberPurchases(QWidget *parent) : QWidget(parent), ui(new Ui::memberPurchases)
{
    ui->setupUi(this);

    // Set up the database connection
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the model
    QSqlQueryModel * model0 = new QSqlQueryModel();
    QSqlQuery query(db);

    // Set up the query
    query.prepare("SELECT Membership_Number, (SELECT Member_Name from Members WHERE Members.Membership_ID=Sales_Record.Membership_Number) as Member_Name, SUM (sales_price* quantity_purchased * 1.0775) as Total_Purchases FROM Sales_Record GROUP BY Membership_number ORDER BY Membership_number");
    query.exec();
    model0->setQuery(std::move(query));

    // Set up the table view
    ui->tableView->setModel(model0);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Set up the total label
    QSqlRecord totalMemberSalesRecord;
    int totalSalesIterator = 0;
    double salesPrice = 0;
    double runningTotal = 0;

    do
    {
        totalMemberSalesRecord = model0->record(totalSalesIterator);
        salesPrice = totalMemberSalesRecord.value(1).toDouble();
        runningTotal += salesPrice;
        totalSalesIterator++;
    }while (!totalMemberSalesRecord.isNull(1));

    QString finalTotal = finalTotal.number(runningTotal,'f',2);
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);
}


memberPurchases::~memberPurchases()
{
    delete ui;
}


void memberPurchases::on_idSearchButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QString ID = ui->memberIDLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Sales_Record WHERE Membership_Number=(:ID)");
    query.bindValue(":ID",ID);
    query.exec();
    model->setQuery(std::move(query));

    QSqlRecord totalSalesRecord;
    int totalSalesIterator = 0;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do
    {
        totalSalesRecord = model->record(totalSalesIterator); 
        salesPrice = totalSalesRecord.value(3).toDouble(); 
        salesQuantity = totalSalesRecord.value(4).toDouble(); 
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while(!totalSalesRecord.isNull(3));
    runningTotal += runningTotal * 0.0775;

    QString finalTotal = finalTotal.number(runningTotal,'f',2);
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);

    ui->tableView->setModel(model);
}


void memberPurchases::on_nameSearchButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QString name = ui->memberNameLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    QSqlRecord record;
    query.prepare("SELECT * FROM Members WHERE Member_Name=(:name)");
    query.bindValue(":name",name);
    query.exec();
    model->setQuery(std::move(query));
    record = model->record(0);
    QString id = record.value(1).toString();
    QSqlQuery query2(db);
    query2.prepare("SELECT * FROM Sales_Record WHERE Membership_Number=(:ID)");
    query2.bindValue(":ID",id);
    query2.exec();
    model->setQuery(std::move(query2));

    QSqlRecord totalSalesRecord;
    int totalSalesIterator = 0;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do
    {
        totalSalesRecord = model->record(totalSalesIterator); 
        salesPrice = totalSalesRecord.value(3).toDouble(); 
        salesQuantity = totalSalesRecord.value(4).toDouble(); 
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while(!totalSalesRecord.isNull(3));
    runningTotal += runningTotal * 0.0775;

    QString finalTotal = finalTotal.number(runningTotal,'f',2);
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);

    ui->tableView->setModel(model);
}


void memberPurchases::on_cancelButton_clicked()
{
    close();
}


void memberPurchases::on_DisplayAllPushButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QSqlQueryModel * model0 = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT Membership_Number, (SELECT Member_Name from Members WHERE Members.Membership_ID=Sales_Record.Membership_Number) as Member_Name, SUM (sales_price* quantity_purchased * 1.0775) as Total_Purchases FROM Sales_Record GROUP BY Membership_number ORDER BY Membership_number");

    query.exec();

    model0->setQuery(std::move(query));

    ui->tableView->setModel(model0);

    QSqlRecord totalMemberSalesRecord;
    int totalSalesIterator = 0;
    double salesPrice = 0;
    double runningTotal = 0;
    do
    {
        totalMemberSalesRecord = model0->record(totalSalesIterator); 
        salesPrice = totalMemberSalesRecord.value(1).toDouble(); 
        runningTotal += salesPrice;
        totalSalesIterator++;
    }while(!totalMemberSalesRecord.isNull(1));

    QString finalTotal = finalTotal.number(runningTotal,'f',2);
    finalTotal.prepend("Total Purchases + tax: ");
    ui->totalLabel->setText(finalTotal);
}


void memberPurchases::on_memberIDLineEdit_returnPressed()
{
    memberPurchases::on_idSearchButton_clicked();
}


void memberPurchases::on_memberNameLineEdit_returnPressed()
{
    memberPurchases::on_nameSearchButton_clicked();
}

