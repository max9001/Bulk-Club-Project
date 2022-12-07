#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QWidget>
#include <QSqlDatabase>

namespace Ui 
{
    class AddMember;
}

class AddMember : public QWidget
{
    Q_OBJECT

    private:
        Ui::AddMember *ui;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        
    private slots:
        void on_exitWindow_clicked();
        void on_addMemberPushButton_clicked();
        void on_ExpiryLineEdit_returnPressed();

    public:
        explicit AddMember(QWidget *parent = nullptr);
        ~AddMember();
};

#endif // ADDMEMBER_H
