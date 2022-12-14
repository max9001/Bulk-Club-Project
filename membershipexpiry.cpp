#include "membershipexpiry.h"
#include "ui_membershipexpiry.h"
#include "global.h"
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QSqlRecord>

MembershipExpiry::MembershipExpiry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MembershipExpiry)
{
    ui->setupUi(this);

    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  //the .db file should be kept within the repository for no

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members");
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MembershipExpiry::~MembershipExpiry()
{
    delete ui;
}

void MembershipExpiry::on_searchButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  

    QString date = ui->dateLineEdit->text();
    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members WHERE Membership_Expiry=(:date)");
    query.bindValue(":date",date);
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);

}

void MembershipExpiry::on_cancelButton_clicked()
{
    close();
}

void MembershipExpiry::on_DisplayAllButton_clicked()
{
    db.setDatabaseName(Path::getDBPath());
    db.open();                                                                  //the .db file should be kept within the repository for no

    QSqlQueryModel * model = new QSqlQueryModel();
    QSqlQuery query(db);
    query.prepare("SELECT * FROM Members");
    query.exec();

    model->setQuery(std::move(query));

    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}
