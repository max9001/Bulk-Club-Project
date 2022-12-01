#include "memberconversionsWidget.h"
#include "ui_memberconversions.h"

MemberConversions::MemberConversions(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::MemberConversions)
{
		ui->setupUi(this);
}

MemberConversions::~MemberConversions()
{
		delete ui;
}
