#include "finaldialog.h"
#include "ui_finaldialog.h"
#include "sql.h"
#include <QMessageBox>
#include "imagedialog.h"
#include "welcomepage.h"
#include "textdialog.h"
#include "generapage.h"
#include <QTimer>
#include <QDateTime>
#include "httprequestworker.h"

finalDialog::finalDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::finalDialog)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

finalDialog::~finalDialog()
{
    delete ui;
}

void finalDialog::on_pushButton_2_clicked()
{
    this->hide();
    textDialog texta;
    texta.setModal(true);
    texta.exec();
}

void finalDialog:: showTime()
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

   ui->clck_2->setText(time_text);
}

void finalDialog::on_toolButton_4_clicked()
{
    this->hide();
    Generapage gen;
    gen.setModal(true);
    gen.exec();
}
