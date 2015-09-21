#include "d_main.h"
#include "ui_d_main.h"
#include "signup.h"
#include "login.h"
#include "generapage.h"
#include "sql.h"
#include <QMessageBox>
#include "finaldialog.h"
#include "welcomepage.h"
#include <QTimer>
#include <QDateTime>

d_main::d_main(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::d_main)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

d_main::~d_main()
{
    delete ui;
}

void d_main::on_pushButton_clicked()
{
    this->hide();
    login log;
    log.setModal(true);
    log.exec();
}

void d_main::on_pushButton_2_clicked()
{
    this->hide();
    signup sign;
    sign.setModal(true);
    sign.exec();
}

void d_main:: showTime()
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


void d_main::on_toolButton_4_clicked()
{
    this->hide();
    Generapage gen;
    gen.setModal(true);
    gen.exec();
}
