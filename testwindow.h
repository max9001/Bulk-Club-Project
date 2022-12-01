#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QDialog>

namespace Ui {
class TestWindow;
}

class TestWindow : public QDialog
{
		Q_OBJECT

public:
		explicit TestWindow(QWidget *parent = nullptr);
		~TestWindow();

private:
		Ui::TestWindow *ui;
};

#endif // TESTWINDOW_H
