#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "managemembers.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
		Q_OBJECT

public:
		explicit AdminWindow(QWidget *parent = nullptr);
		~AdminWindow();

private slots:
		void on_manageMembersPushButton_clicked();

private:
		Ui::AdminWindow *ui;
		ManageMembers *manageMembers;
};

#endif // ADMINWINDOW_H
