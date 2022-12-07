#ifndef MEMBERSHIPEXPIRY_H
#define MEMBERSHIPEXPIRY_H

#include <QDialog>
#include <QSqlDatabase>

namespace Ui {
class MembershipExpiry;
}

class MembershipExpiry : public QDialog
{
    Q_OBJECT

public:
    explicit MembershipExpiry(QWidget *parent = nullptr);
    ~MembershipExpiry();

private slots:

    void on_searchButton_clicked();

    void on_cancelButton_clicked();

    void on_DisplayAllButton_clicked();

private:
    Ui::MembershipExpiry *ui;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
};

#endif // MEMBERSHIPEXPIRY_H
