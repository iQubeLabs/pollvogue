#ifndef SIGNUP_H
#define SIGNUP_H
#include "login.h"

#include <QDialog>

#include <Qtsql/QSql>
#include <QMessageBox>
#include <QFileInfo>
#include <Qtsql/QSqlQuery>
#include <Qtsql/QSqlDatabase>
#include "httprequestworker.h"
#include <QtNetwork/QNetworkAccessManager>



namespace Ui {
class signup;
}

class signup : public QDialog
{
    Q_OBJECT

public:
    explicit signup(QWidget *parent = 0);
    ~signup();

private slots:
    void on_pushButton_clicked();
     void showTime();
     void handle_result(HttpRequestWorker *worker);



private:
    Ui::signup *ui;
};

#endif // SIGNUP_H
