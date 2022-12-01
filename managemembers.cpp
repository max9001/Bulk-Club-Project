#include "managemembers.h"
#include "ui_managemembers.h"

ManageMembers::ManageMembers(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::ManageMembers)
{
		ui->setupUi(this);
}

ManageMembers::~ManageMembers()
{
		delete ui;
}
