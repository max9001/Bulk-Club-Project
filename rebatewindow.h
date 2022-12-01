#ifndef REBATEWINDOW_H
#define REBATEWINDOW_H

#include <QWidget>

namespace Ui {
class RebateWindow;
}

class RebateWindow : public QWidget
{
    Q_OBJECT

public:
    explicit RebateWindow(QWidget *parent = nullptr);
    ~RebateWindow();

private:
    Ui::RebateWindow *ui;
};

#endif // REBATEWINDOW_H
