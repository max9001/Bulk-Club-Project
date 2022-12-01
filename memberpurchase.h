#ifndef MEMBERPURCHASE_H
#define MEMBERPURCHASE_H

#include <QWidget>

namespace Ui {
class MemberPurchase;
}

class MemberPurchase : public QWidget
{
    Q_OBJECT

public:
    explicit MemberPurchase(QWidget *parent = nullptr);
    ~MemberPurchase();

private:
    Ui::MemberPurchase *ui;
};

#endif // MEMBERPURCHASE_H
