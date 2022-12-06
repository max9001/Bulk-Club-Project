#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H


#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QLineEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QStringList>
#include <QDebug>
#include <QSqlDatabase>
#include "storemanager.h"
#include "admin.h"



class LoginDialog : public QDialog {
    Q_OBJECT

    private:
        QLabel* labelUsername;
        QLabel* labelPassword;
        QLineEdit* editUsername;
        QLineEdit* editPassword;
        QDialogButtonBox* buttons;
        StoreManager* StoreManagerWindow = NULL;
        Admin* adminWindow = NULL;

        void setUpGUI();

    signals:
        void acceptLogin( QString& username, QString& password );
        
    public:
        explicit LoginDialog(QWidget* parent = nullptr);
        void setUsername( QString& username );
        void setPassword( QString& password );
        QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    public slots:
        void slotAcceptLogin();
};

#endif // LOGINDIALOG_H
