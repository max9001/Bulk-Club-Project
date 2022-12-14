#include "logindialog.h"
#include "global.h"
#include <QSql>
//#include <QSqlDatabase>
//#include <QSqlError>
//#include <QSqlQuery>
//#include <QSqlQueryModel>
#include <QTableView>
//#include <QSqlRecord>


LoginDialog::LoginDialog(QWidget* parent) : QDialog(parent)
{
    setUpGUI();                                     // Set up the GUI
    setWindowTitle( tr("User Login") );             // Set the window title
    setModal( true );                               // Set the dialog to be modal
}


void LoginDialog::setUpGUI(){


    QGridLayout* formGridLayout = new QGridLayout( this );


    editUsername = new QLineEdit( this );
    editPassword = new QLineEdit( this );
    editPassword->setEchoMode( QLineEdit::Password );

    labelUsername = new QLabel( this );
    labelUsername->setText( tr( "Username" ) );
    labelUsername->setBuddy( editUsername );

    labelPassword = new QLabel( this );
    labelPassword->setText( tr( "Password" ) );
    labelPassword->setBuddy( editPassword );


    buttons = new QDialogButtonBox( this );
    buttons->addButton( QDialogButtonBox::Ok );
    buttons->addButton( QDialogButtonBox::Cancel );
    buttons->button( QDialogButtonBox::Ok )->setText( tr("Login") );
    buttons->button( QDialogButtonBox::Cancel )->setText( tr("Cancel") );

    connect( buttons->button( QDialogButtonBox::Cancel ),
        SIGNAL (clicked()),
        this,
        SLOT (close())
        );

    connect( buttons->button( QDialogButtonBox::Ok ),
        SIGNAL (clicked()),
        this,
        SLOT (slotAcceptLogin()) );


    formGridLayout->addWidget( labelUsername, 0, 0 );
    formGridLayout->addWidget( editUsername, 0, 1 );
    formGridLayout->addWidget( labelPassword, 1, 0 );
    formGridLayout->addWidget( editPassword, 1, 1 );
    formGridLayout->addWidget( buttons, 2, 0, 1, 2 );
    setLayout( formGridLayout );

}

void LoginDialog::setUsername(QString &username){

   editUsername->setText(username);
}

void LoginDialog::setPassword(QString &password){

    editPassword->setText( password );
}

void LoginDialog::slotAcceptLogin(){
    QString notFound = "Profile not found, check login information";
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

    db.setDatabaseName(Path::getDBPath());

    db.open();

    QString username = editUsername->text(); //pulls the values from the text edit lines
    QString password = editPassword->text();

    QSqlQueryModel model;//model is readonly access to query results
    QSqlRecord record;//record accesses records returned by a query
    QSqlQuery query(db);
    query.prepare("SELECT * FROM users WHERE username=(:name)");
    query.bindValue(":name",username);
    query.exec(); //query must be active before being moved into the model

    model.setQuery(std::move(query));
    record = model.record(0); //sets the record to the first record in the query results


    if (password == record.value(1).toString()){
        qDebug().noquote() << "correct login";
        bool admin = record.value(2).toBool();

        if(admin){
            qDebug().noquote() << "Logging in as admin";
            adminWindow = new Admin;
            adminWindow->show();
        }
        else {
            qDebug().noquote() << "Logging in as a user";
            StoreManagerWindow = new StoreManager;
            StoreManagerWindow->show();
        }
    }
    else { qDebug().noquote() << notFound; }

        this->close();
}
