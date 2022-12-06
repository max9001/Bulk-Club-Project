#ifndef MEMBERUPGRADE_H
#define MEMBERUPGRADE_H

#include <QDialog>
#include <QModelIndex>
#include <QSqlDatabase>

namespace Ui {
class memberupgrade;
}

class memberupgrade : public QDialog
{
    Q_OBJECT

public:
    explicit memberupgrade(QWidget *parent = nullptr);
    ~memberupgrade();

private slots:
    void on_cancelButton_clicked();

private:
    Ui::memberupgrade *ui;
    QModelIndex invalidIndex;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // MEMBERUPGRADE_H
