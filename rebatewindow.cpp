#include "rebatewindow.h"
#include "ui_rebatewindow.h"

RebateWindow::RebateWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RebateWindow)
{
    ui->setupUi(this);
}

RebateWindow::~RebateWindow()
{
    delete ui;
}
