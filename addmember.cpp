#include "addmember.h"
#include "ui_addmember.h"
#include "global.h"
#include <QRandomGenerator>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>


AddMember::AddMember(QWidget *parent) : QWidget(parent), ui(new Ui::AddMember)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}


AddMember::~AddMember() {
    delete ui;
}


void AddMember::on_exitWindow_clicked() {
    this->close();
}


void AddMember::on_addMemberPushButton_clicked()
{
    
    QString name = ui->nameLineEdit->text();
    QString type = ui->typeLineEdit->text();
    QString expiry = ui->ExpiryLineEdit->text();
    int id = QRandomGenerator::global()->bounded(11111, 99999);

    if (name == "" | type == "" | expiry == "") {
        QMessageBox::warning(this, "Empty field", "One of your fields is empty");
    }
    else
    {
        db.setDatabaseName(Path::getDBPath());

        db.open();                                                                  

        QSqlQuery query(db);
        query.prepare("INSERT INTO Members VALUES ((:name),(:id),(:type),(:expiry),(:cost),(:rebate))");

        query.bindValue(":name", name);
        query.bindValue(":id", id);
        query.bindValue(":type", type);
        query.bindValue(":expiry", expiry);

        if (type.toLower() == "regular") {
            query.bindValue(":cost",65);
        }
        else { query.bindValue(":cost",120); }

        query.bindValue(":rebate", 0);

        if (!query.exec()) {
            QMessageBox::warning(this, "Query Error", "Query not executed");
        }
        else {
            QMessageBox::information(this, "Success", "Member added successfully");
        }

        this->close();
    }
}


void AddMember::on_ExpiryLineEdit_returnPressed() {
    on_addMemberPushButton_clicked();
}

