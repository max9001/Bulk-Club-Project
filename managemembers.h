#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <QDialog>

namespace Ui {
class ManageMembers;
}

class ManageMembers : public QDialog
{
		Q_OBJECT

public:
		explicit ManageMembers(QWidget *parent = nullptr);
		~ManageMembers();

private:
		Ui::ManageMembers *ui;
};

#endif // MANAGEMEMBERS_H
