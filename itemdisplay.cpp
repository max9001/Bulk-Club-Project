#include "itemdisplay.h"
#include "ui_itemdisplay.h"

ItemDisplay::ItemDisplay(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ItemDisplay)
{
    ui->setupUi(this);
}

ItemDisplay::~ItemDisplay()
{
    delete ui;
}
