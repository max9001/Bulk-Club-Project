#ifndef MANAGEMEMBERS_H
#define MANAGEMEMBERS_H

#include <QWidget>
#include "addmember.h"
#include <QSqlDatabase>

namespace Ui {
class managemembers;
}

class managemembers : public QWidget
{
    Q_OBJECT
        
    private:
        Ui::managemembers *ui;
        AddMember* addMemberWindow = NULL;
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    private slots:
        void on_searchPushButton_clicked();
        void on_AddMemberButton_clicked();
        void on_deletePushButton_clicked();
        void on_DisplayAllPushButton_clicked();
        void on_searchLineEdit_returnPressed();
        void on_deleteMemberLineEdit_returnPressed();
        void on_ExitButton_clicked();

    public:
        explicit managemembers(QWidget *parent = nullptr);
        ~managemembers();

};

#endif // MANAGEMEMBERS_H
