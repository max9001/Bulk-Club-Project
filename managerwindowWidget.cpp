#include "managerwindowWidget.h"
#include "ui_managerwindow.h"

ManagerWindow::ManagerWindow(QWidget *parent) :
		QWidget(parent),
		ui(new Ui::ManagerWindow)
{
		ui->setupUi(this);
}

ManagerWindow::~ManagerWindow()
{
		delete ui;
}
