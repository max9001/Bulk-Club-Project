#include "loginwindow.h"
#include <string>
using namespace std;

LoginWindow::LoginWindow(QWidget *parent)
{
    ui->setupUi(this);
    username = "\0";
    password = "\0";
}
LoginWindow::~LoginWindow() {}

void LoginWindow::onLoginButtonClicked()
{
    password = ui->passwordInput->text().toStdString();
    username = ui->usernameInput->text().toStdString();
    //first finds username in DB and uses it to verify password

    if(password == passwordInDB)
    {
        AdminWindow->show();
    }
    else{}//password incorrect
}
