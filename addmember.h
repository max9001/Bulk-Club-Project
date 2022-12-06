#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>

namespace Ui 
{
    class AddMember;
}

class AddMember : public QWidget
{
    Q_OBJECT

    private:
        Ui::AddMember *ui;
        
    private slots:
        void on_exitWindow_clicked();
        void on_addMemberPushButton_clicked();
        void on_ExpiryLineEdit_returnPressed();

    public:
        explicit AddMember(QWidget *parent = nullptr);
        ~AddMember();
};

#endif // ADDMEMBER_H
