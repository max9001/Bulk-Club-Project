#ifndef MEMBERPURCHASES_H
#define MEMBERPURCHASES_H

#include <QWidget>

namespace Ui {
class memberPurchases;
}

class memberPurchases : public QWidget
{
    Q_OBJECT

    private:
        Ui::memberPurchases *ui;

    private slots:
        void on_idSearchButton_clicked();
        void on_nameSearchButton_clicked();
        void on_cancelButton_clicked();
        void on_DisplayAllPushButton_clicked();
        void on_memberIDLineEdit_returnPressed();
        void on_memberNameLineEdit_returnPressed();

    public:
        explicit memberPurchases(QWidget *parent = nullptr);
        ~memberPurchases();
};

#endif // MEMBERPURCHASES_H
