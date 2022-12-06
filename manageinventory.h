#ifndef MANAGEINVENTORY_H
#define MANAGEINVENTORY_H

#include <QWidget>
#include <QSqlTableModel>

namespace Ui 
{
    class ManageInventory;
}

class ManageInventory : public QWidget
{
    Q_OBJECT

    private:
        Ui::ManageInventory *ui;
        QSqlTableModel* model = NULL;
        QModelIndex invalidIndex;

    private slots:
        void on_SaveButton_clicked();
        void on_Cancelbutton_clicked();
        void on_AddRowButton_clicked();
        void on_DelRowButton_clicked();

    public:
        explicit ManageInventory(QWidget *parent = nullptr);
        ~ManageInventory();
};

#endif // MANAGEINVENTORY_H
