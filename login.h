#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QDebug>
#include <QFileInfo>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include "signup.h"
#include "httprequestworker.h"
#include <QtNetwork/QNetworkAccessManager>

namespace Ui {
class login;
}

class login : public QDialog
{
    Q_OBJECT

public:
    //to set connection in such a way that I can access db in other .cpp files
   QSqlDatabase mydb;
    void connClose()
    {
        mydb.close();
        mydb.removeDatabase(QSqlDatabase::defaultConnection);
    }

    bool connOpen()
    {
        mydb =QSqlDatabase::addDatabase("QMYSQL");
        mydb.setHostName("localhost");
        mydb.setDatabaseName("poll");
        mydb.setPort(3306);
        mydb.setUserName("root");
        mydb.setPassword("");

        if(!mydb.open()){
            qDebug()<< ("database not open");
            return false;}
        else{
            qDebug()<< ("Connected...");
            return true;
        }

    }


public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_pushButton_clicked();
    void showTime();
    void handle_result(HttpRequestWorker *worker);



private:
    Ui::login *ui;
};

#endif // LOGIN_H
