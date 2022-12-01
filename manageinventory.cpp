#include "manageinventory.h"
#include "ui_manageinventory.h"

ManageInventory::ManageInventory(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::ManageInventory)
{
		ui->setupUi(this);
}

ManageInventory::~ManageInventory()
{
		delete ui;
}
