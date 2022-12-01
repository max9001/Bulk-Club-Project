#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>

namespace Ui {
class AddMember;
}

class AddMember : public QWidget
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent = nullptr);
    ~AddMember();

private:
    Ui::AddMember *ui;
};

#endif // ADDMEMBER_H
