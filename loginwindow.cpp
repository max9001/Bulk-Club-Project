#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
		QDialog(parent),
		ui(new Ui::LoginWindow)
{
		ui->setupUi(this);
}

LoginWindow::~LoginWindow()
{
		delete ui;
}

void LoginWindow::on_loginPushButton_clicked(){
	if (checked) {
		adminWindow = new AdminWindow(this);                  // Create a new HelpWindow object
		adminWindow->show();
		this->hide();
	}
	else {
		managerWindow = new ManagerWindow(this);                  // Create a new HelpWindow object
		managerWindow->show();
		this->hide();
	}

}

void LoginWindow::on_adminCheckBox_stateChanged(int arg1)
{
	checked = arg1;
}

