#include "managemembers.h"
#include "ui_managemembers.h"
#include "global.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QMessageBox>
#include "addmember.h"


managemembers::managemembers(QWidget *parent) : QWidget(parent), ui(new Ui::managemembers)
{
    ui->setupUi(this);

    // Set up the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the model
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);

    // Prepare the query
    query.prepare("SELECT * FROM Members");
    query.exec();
    model->setQuery(std::move(query));

    // Set the model
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}


managemembers::~managemembers()
{
    delete ui;
}


void managemembers::on_searchPushButton_clicked()
{
    QString input = ui->searchLineEdit->text();

    // Set up the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the model
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);

    // Prepare the query
    query.prepare("SELECT * FROM Members WHERE Membership_ID =(:input)");
    query.bindValue(":input", input);
    query.exec();

    // Set the model
    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
}


void managemembers::on_DisplayAllPushButton_clicked()
{
    // Set up the database
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    // Set up the model
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query(db);

    // Prepare the query
    query.prepare("SELECT * FROM Members");
    query.exec();

    // Set the model
    model->setQuery(std::move(query));
    ui->tableView->setModel(model);
}


void managemembers::on_AddMemberButton_clicked()
{
    addMemberWindow = new AddMember;
    addMemberWindow->show();
}


void managemembers::on_deletePushButton_clicked()
{
    QString id = ui->deleteMemberLineEdit->text();

    if( QMessageBox::question(this, "Remove Member", "Are you sure you want to delete this member?"))
    {
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");     // Set up the database
        QSqlQueryModel * model = new QSqlQueryModel();              // Set up the model

        // Prepare the database
        db.setDatabaseName(Path::getDBPath());
        db.open();                                                                  

        // Prepare the query
        QSqlQuery query(db);
        query.prepare("DELETE FROM Members WHERE MEMBERSHIP_ID = (:id)" );
        query.bindValue(":id", id);
        query.exec();

        if (!query.exec() ) { QMessageBox::warning(this, "Query Error", "Query not executed"); }
        else
        { QMessageBox::information(this, "Member Deleted", "Success"); }

        // Prepare the query
        query.prepare("SELECT * FROM Members");
        query.exec();

        // Set the model
        model->setQuery(std::move(query));
        ui->tableView->setModel(model);

    }
}


void managemembers::on_searchLineEdit_returnPressed()
{
    managemembers::on_searchPushButton_clicked();
}


void managemembers::on_deleteMemberLineEdit_returnPressed()
{
    managemembers::on_deletePushButton_clicked();
}


void managemembers::on_ExitButton_clicked()
{
    this->close();
}

