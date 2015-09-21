#include "login.h"
#include "ui_login.h"
#include "sql.h"
#include "models/usermodel.h"
#include <QMessageBox>
#include "signup.h"
#include "welcomepage.h"
#include "generapage.h"
#include <QTimer>
#include <QDateTime>
#include <QDebug>
#include <QDialog>
#include <QtSql/QSql>
#include <QMessageBox>
#include <QFileInfo>
#include <QJsonDocument>
#include <QJsonObject>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <Qtsql/QSqlDatabase>
#include "httprequestworker.h"

#include <QSql>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlDatabase>

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();


}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked()
{
    QString nickname, password;
    nickname=ui->txtnickname->text();
    password= ui->txtpassword->text();

    QString url_str = "http://iqubebase.com/pollvogue-api/public/login";

    HttpRequestInput input(url_str, "POST");
    input.add_var("nickname", nickname);
    input.add_var("password", password);

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);


            }


void login:: showTime()
{


    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");

    if((time.second()%2)==0)
    {
        time_text[8]=' ';
    }
    if((time.minute()%2)==0)
    {
        time_text[3]=' ';
    }

    ui->clck->setText(time_text);
}

void login::handle_result(HttpRequestWorker *worker)
{
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        QJsonDocument jsonResponse = QJsonDocument::fromJson(worker->response);
        QJsonObject jsonResponseObject = jsonResponse.object();

        QJsonObject metaObject = jsonResponseObject["meta"].toObject();
        int status = metaObject["status"].toInt();
        msg = metaObject["message"].toString();


        if(status == 0)
        {
            this->hide();

            //save user data
            QJsonObject dataObject = jsonResponseObject["data"].toObject()["user"].toObject();
            QString userId = dataObject["id"].toString();
            QStringList valuesList;
            valuesList.append(userId);
            valuesList.append(dataObject["nickname"].toString());
            valuesList.append(dataObject["phonenumber"].toString());
            valuesList.append(dataObject["token"].toString());

            QStringList fieldsList;
            UserModel::Field f;
            fieldsList.append(f.ID);
            fieldsList.append(f.NICKNAME);
            fieldsList.append(f.PHONE);
            fieldsList.append(f.TOKEN);

            //TODO: 'new UserModel()' is not efficient. Fix with probably a ModelManager class
            //that returns only a single instance of each model at a time
            sql::getInstance()->dropTable(new UserModel());
            sql::getInstance()->createTable(new UserModel());

            if(sql::getInstance()->insert(new UserModel(), fieldsList, valuesList))
            {
                //open welcome page
                welcomepage welcam;
                welcam.setModal(true);
                welcam.exec();
            }
            else
            {
                QMessageBox::warning(this, "Warning", "Could not log you in. Check logs.");
            }
        }
        else
        {
            this->hide();
             signup main;
             main.setModal(true);
             main.exec();
        }

    }
    else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }

    QMessageBox::information(this, "", msg);
}
