#ifndef MEMBERSHIPEXPIRY_H
#define MEMBERSHIPEXPIRY_H

#include <QDialog>

namespace Ui {
class MembershipExpiry;
}

class MembershipExpiry : public QDialog
{
    Q_OBJECT

public:
    explicit MembershipExpiry(QWidget *parent = nullptr);
    ~MembershipExpiry();

private:
    Ui::MembershipExpiry *ui;
};

#endif // MEMBERSHIPEXPIRY_H
