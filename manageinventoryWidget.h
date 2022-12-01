#ifndef MANAGEINVENTORYWIDGET_H
#define MANAGEINVENTORYWIDGET_H

#include <QWidget>

namespace Ui {
class ManageInventory;
}

class ManageInventory : public QWidget
{
		Q_OBJECT

public:
		explicit ManageInventory(QWidget *parent = nullptr);
		~ManageInventory();

private:
		Ui::ManageInventory *ui;
};

#endif // MANAGEINVENTORYWIDGET_H
