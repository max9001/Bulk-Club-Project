#include "memberpurchase.h"
#include "ui_memberpurchase.h"

MemberPurchase::MemberPurchase(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MemberPurchase)
{
    ui->setupUi(this);
}

MemberPurchase::~MemberPurchase()
{
    delete ui;
}
