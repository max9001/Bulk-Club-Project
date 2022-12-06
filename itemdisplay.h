#ifndef ITEMDISPLAY_H
#define ITEMDISPLAY_H

#include <QDialog>

namespace Ui 
{
    class itemDisplay;
}

class itemDisplay : public QDialog
{
    Q_OBJECT

    private:
        Ui::itemDisplay *ui;
        
    private slots:
        void on_searchButton_clicked();
        void on_pushButton_clicked();

    public:
        explicit itemDisplay(QWidget *parent = nullptr);
        ~itemDisplay();
};

#endif // ITEMDISPLAY_H
