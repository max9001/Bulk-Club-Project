#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H

#include <QDialog>

namespace Ui {
class ItemDisplay;
}

class ItemDisplay : public QDialog
{
    Q_OBJECT

public:
    explicit ItemDisplay(QWidget *parent = nullptr);
    ~ItemDisplay();

private:
    Ui::ItemDisplay *ui;
};

#endif // ITEMDISPLAY_H
