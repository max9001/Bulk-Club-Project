#include "memberconversions.h"
#include "ui_memberconversions.h"

MemberConversions::MemberConversions(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::MemberConversions)
{
		ui->setupUi(this);
}

MemberConversions::~MemberConversions()
{
		delete ui;
}
