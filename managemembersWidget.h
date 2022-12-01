#ifndef MANAGEMEMBERSWIDGET_H
#define MANAGEMEMBERSWIDGET_H

#include <QWidget>

namespace Ui {
class ManageMembers;
}

class ManageMembers : public QWidget
{
		Q_OBJECT

public:
		explicit ManageMembers(QWidget *parent = nullptr);
		~ManageMembers();

private:
		Ui::ManageMembers *ui;
};

#endif // MANAGEMEMBERSWIDGET_H
