#ifndef MEMBERUPGRADE_H
#define MEMBERUPGRADE_H

#include <QDialog>

namespace Ui {
class MemberUpgrade;
}

class MemberUpgrade : public QDialog
{
    Q_OBJECT

public:
    explicit MemberUpgrade(QWidget *parent = nullptr);
    ~MemberUpgrade();

private:
    Ui::MemberUpgrade *ui;
};

#endif // MEMBERUPGRADE_H
