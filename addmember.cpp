#include "addmember.h"
#include "ui_addmember.h"

AddMember::AddMember(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);
}

AddMember::~AddMember()
{
    delete ui;
}
