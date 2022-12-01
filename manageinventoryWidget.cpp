#include "manageinventoryWidget.h"
#include "ui_manageinventory.h"

ManageInventory::ManageInventory(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::ManageInventory)
{
		ui->setupUi(this);
}

ManageInventory::~ManageInventory()
{
		delete ui;
}
