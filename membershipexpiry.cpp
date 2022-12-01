#include "membershipexpiry.h"
#include "ui_membershipexpiry.h"

MembershipExpiry::MembershipExpiry(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MembershipExpiry)
{
    ui->setupUi(this);
}

MembershipExpiry::~MembershipExpiry()
{
    delete ui;
}
