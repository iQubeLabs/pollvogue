#include "final_image.h"
#include "ui_final_image.h"
#include <QMessageBox>
#include "finaldialog.h"
#include "generapage.h"
#include "welcomepage.h"
#include "d_main.h"
#include "imagedialog.h"
#include "sql.h"
#include <QTimer>
#include <QDateTime>


final_image::final_image(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::final_image)
{
    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();
}

final_image::~final_image()
{
    delete ui;
}
void final_image:: showTime()
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

void final_image::on_pushButton_2_clicked()
{
    this->hide();
    ImageDialog image;
    image.setModal(true);
    image.exec();
}

void final_image::on_toolButton_4_clicked()
{
    this->hide();
    Generapage gen;
    gen.setModal(true);
    gen.exec();
}
