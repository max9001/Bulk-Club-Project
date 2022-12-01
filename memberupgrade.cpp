#include "memberupgrade.h"
#include "ui_memberupgrade.h"

MemberUpgrade::MemberUpgrade(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemberUpgrade)
{
    ui->setupUi(this);
}

MemberUpgrade::~MemberUpgrade()
{
    delete ui;
}
