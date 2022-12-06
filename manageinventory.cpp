#include "manageinventory.h"
#include "ui_manageinventory.h"
#include "global.h"
#include <QModelIndex>
#include <QMessageBox>


ManageInventory::ManageInventory(QWidget *parent) : QWidget(parent), ui(new Ui::ManageInventory)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    // Set up the model
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path::getDBPath());

    // Open the database
    db.open();                                                                  
    model = new QSqlTableModel(NULL,db);
    model->setTable("Inventory");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    // Set the model and hide the ID column
    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableView->show();
}


ManageInventory::~ManageInventory()
{
    delete ui;
}


void ManageInventory::on_SaveButton_clicked()
{
    model->submitAll();
    QMessageBox::information(this, "Save", "Success, all changes saved");
}


void ManageInventory::on_Cancelbutton_clicked()
{
    model->revertAll();
    close();
}


void ManageInventory::on_AddRowButton_clicked()
{
    model->insertRows(model->rowCount(invalidIndex),1);
    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
}


void ManageInventory::on_DelRowButton_clicked()
{
    model->removeRows(ui->RowToDel->value()-1,1,invalidIndex);
    ui->RowToDel->setMaximum(model->rowCount(invalidIndex));
    model->submitAll();
}

