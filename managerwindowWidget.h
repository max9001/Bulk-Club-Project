#ifndef MANAGERWINDOWWIDGET_H
#define MANAGERWINDOWWIDGET_H

#include <QWidget>

namespace Ui {
class ManagerWindow;
}

class ManagerWindow : public QWidget
{
		Q_OBJECT

public:
		explicit ManagerWindow(QWidget *parent = nullptr);
		~ManagerWindow();

private:
		Ui::ManagerWindow *ui;
};

#endif // MANAGERWINDOWWIDGET_H
