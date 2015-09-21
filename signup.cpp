#include "signup.h"
#include "ui_signup.h"
#include "d_main.h"
#include "sql.h"
#include <QMessageBox>
#include "login.h"
#include <QTimer>
#include "generapage.h"
#include <QDateTime>
#include <QMessageBox>
#include <Qtsql/QSqlError>
#include <Qtsql/QSqlQuery>
#include <QString>
#include <QJsonDocument>
#include <QJsonObject>
#include <Qtsql/QSqlQuery>
#include <Qtsql/QSqlDatabase>
#include "httprequestworker.h"



signup::signup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signup)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

signup::~signup()
{
    delete ui;
}

void signup::on_pushButton_clicked()
{
    //login conn;
    QString name, password, number;
    name=ui->txtnickname->text();
    password= ui->txtpassword->text();
    number=ui->number->text();

    QString url_str = "http://iqubebase.com/pollvogue-api/public/register";

    HttpRequestInput input(url_str, "POST");

        input.add_var("nickname", name);
        input.add_var("password", password);
         input.add_var("phonenumber",  number);

        HttpRequestWorker *worker = new HttpRequestWorker(this);
        connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
        worker->execute(&input);
        qDebug()<<"Sending Request";

//    this->hide();
//    login loga;
//    loga.setModal(true);
//    loga.exec();

    //goto ska;
//}
//else{
    QMessageBox::warning(this,tr("Signup Request"), "Sending Request");
//}

//ska: ;
}

void signup:: showTime()
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
  // ui->lab->setText(time_text);
}

void signup::handle_result(HttpRequestWorker *worker)
{
    QString msg;

    if (worker->error_type == QNetworkReply::NoError) {
        // communication was successful
        QJsonDocument jsonResponse = QJsonDocument::fromJson(worker->response);
        QJsonObject jsonResponseObject = jsonResponse.object();

        QJsonObject metaObject = jsonResponseObject["meta"].toObject();
        int status = metaObject["status"].toInt();
        msg = metaObject["message"].toString();
        qDebug() << QString(jsonResponse.toJson());
        if(status == 0)
        {
            this->hide();
            login loga;
            loga.setModal(true);
            loga.exec();
        }

        else
        {
            QMessageBox::warning(this,tr("Save"), "there is an error in the inputted value");

            this->hide();
             signup main;
             main.setModal(true);
             main.exec();
        }
}
}
