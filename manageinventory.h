#ifndef MANAGEINVENTORY_H
#define MANAGEINVENTORY_H

#include <QDialog>

namespace Ui {
class ManageInventory;
}

class ManageInventory : public QDialog
{
		Q_OBJECT

public:
		explicit ManageInventory(QWidget *parent = nullptr);
		~ManageInventory();

private:
		Ui::ManageInventory *ui;
};

#endif // MANAGEINVENTORY_H
