#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H


#include "adminwindowWidget.h"
#include "managerwindow.h"
#include <QDialog>

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QDialog
{
		Q_OBJECT

public:
		explicit LoginWindow(QWidget *parent = nullptr);
		~LoginWindow();

private:
		Ui::LoginWindow *ui;


		int checked = 0;

		ManagerWindow *managerWindow;
		AdminWindow *adminWindow;

private slots:
		void on_loginPushButton_clicked();
		void on_adminCheckBox_stateChanged(int arg1);
};

#endif // LOGINWINDOW_H
