#include "salesreport.h"
#include "ui_salesreport.h"
#include "global.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>



SalesReport::SalesReport(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SalesReport)
{
    ui->setupUi(this);

    db.setDatabaseName(Path::getDBPath()); 

    db.open();                                                                  

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Sales_Record");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 1;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do{
        totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
        salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while (!totalSalesRecord.isNull(3));
    runningTotal += runningTotal * 0.0775;
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->totalSalesNum->setText(finalTotal);


}

SalesReport::~SalesReport()
{
    delete ui;
}

void SalesReport::on_MemberTypePushButton_clicked()
{
    if (ui->MemberTypeComboBox->currentText() == "Regular")
    {
        db.setDatabaseName(Path::getDBPath());
        db.open();                                                                  

        QSqlQueryModel * model = new QSqlQueryModel();
       //model is readonly access to query results
        QSqlQuery query(db);
        query.prepare("SELECT Purchase_Date, Membership_Number, Item_Purchased, Sales_Price, Quantity_Purchased FROM Sales_Record, Members WHERE Sales_Record.Membership_Number = Members.Membership_ID AND Members.Membership_Type = 'Regular' ORDER BY Purchase_Date");

        query.exec(); //query must be active before being moved into the model
        model->setQuery(std::move(query));

        QSqlRecord totalSalesRecord;//this record will hold an individual user data row
        int totalSalesIterator = 1;
        double salesPrice;
        double salesQuantity;
        double runningTotal = 0;
        do{
            totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
            salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
            salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
            runningTotal += salesPrice * salesQuantity;
            totalSalesIterator++;
        }while (!totalSalesRecord.isNull(3));
        runningTotal += runningTotal * 0.0775;
        QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

        ui->tableView->setModel(model);

        ui->totalSalesNum->setText(finalTotal);

    }

    if (ui->MemberTypeComboBox->currentText() == "Executive")
    {
        db.setDatabaseName(Path::getDBPath());
        db.open();                                                                  

        QSqlQueryModel * model = new QSqlQueryModel();
       //model is readonly access to query results
        QSqlQuery query(db);
        query.prepare("SELECT Purchase_Date, Membership_Number, Item_Purchased, Sales_Price, Quantity_Purchased FROM Sales_Record, Members WHERE Sales_Record.Membership_Number = Members.Membership_ID AND Members.Membership_Type = 'Executive' ORDER BY Purchase_Date");

        query.exec(); //query must be active before being moved into the model
        model->setQuery(std::move(query));

        QSqlRecord totalSalesRecord;//this record will hold an individual user data row
        int totalSalesIterator = 1;
        double salesPrice;
        double salesQuantity;
        double runningTotal = 0;
        do{
            totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
            salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
            salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
            runningTotal += salesPrice * salesQuantity;
            totalSalesIterator++;
        }while (!totalSalesRecord.isNull(3));
        runningTotal += runningTotal * 0.0775;
        QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
        ui->totalSalesNum->setText(finalTotal);

    }


}


void SalesReport::on_DatePushButton_clicked()
{
    QString date = ui->DatelineEdit->text();
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT Sales_Record.Purchase_Date,Members.Member_Name,Members.Membership_Type,Sales_Record.Membership_Number,Sales_Record.Item_Purchased,Sales_Record.Sales_Price,Sales_Record.Quantity_Purchased FROM Sales_Record LEFT JOIN Members ON Sales_Record.Membership_Number = Members.Membership_ID WHERE Purchase_Date=(:date)");
    query.bindValue(":date", date);

    query.exec(); //query must be active before being moved into the model
    model->setQuery(std::move(query));

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 1;
    int execAmount=0;
    int regAmount=0;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do{
        totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
        salesPrice = totalSalesRecord.value(5).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesRecord.value(6).toDouble(); //value at index 4 in the row should be Quantity_Purchased
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
        if(totalSalesRecord.value(2).toString()=="Executive"){
            execAmount++;
        }
        else{
            regAmount++;
        }
    }while (!totalSalesRecord.isNull(4));
    runningTotal += runningTotal * 0.0775;
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

    ui->execAmtLabel->setText(QString::number(execAmount));
    ui->regAmtLabel->setText(QString::number(regAmount));

    ui->tableView->setModel(model);

    ui->totalSalesNum->setText(finalTotal);

}


void SalesReport::on_DatelineEdit_returnPressed()
{
    SalesReport::on_DatePushButton_clicked();
}


void SalesReport::on_ExitButton_clicked()
{
    this->close();
}


void SalesReport::on_AllTimeButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QSqlQueryModel * model = new QSqlQueryModel();
   //model is readonly access to query results
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Sales_Record");

    query.exec(); //query must be active before being moved into the model

    model->setQuery(std::move(query));

    QSqlRecord totalSalesRecord;//this record will hold an individual user data row
    int totalSalesIterator = 1;
    double salesPrice;
    double salesQuantity;
    double runningTotal = 0;
    do{
        totalSalesRecord = model->record(totalSalesIterator); //sets record to the row of the iterator in the model
        salesPrice = totalSalesRecord.value(3).toDouble(); //value at index 3 in the row should be Sales_Price
        salesQuantity = totalSalesRecord.value(4).toDouble(); //value at index 4 in the row should be Quantity_Purchased
        runningTotal += salesPrice * salesQuantity;
        totalSalesIterator++;
    }while (!totalSalesRecord.isNull(3));
    runningTotal += runningTotal * 0.0775;
    QString finalTotal = finalTotal.number(runningTotal,'f',2);//sets a formatted total to a string that can be passed to the totalSalesNum label

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->totalSalesNum->setText(finalTotal);

}
