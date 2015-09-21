#include "welcomepage.h"
#include "ui_welcomepage.h"
#include "imagedialog.h"
#include "textdialog.h"
#include "sql.h"
#include "generapage.h"
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include "login.h"

#include "models/usermodel.h"

welcomepage::welcomepage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::welcomepage)
{
    ui->setupUi(this);
    QPixmap pi("/Users/DELL/Desktop/pics/kk2.png");
    ui->pic_uploader->setPixmap(pi);

    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    //load user content
    QMap<QString, QVariant> userData = sql::getInstance()->findFirst(new UserModel());

    QString welcomeText = ui->label->text();
    welcomeText.replace("**nickname**", userData[UserModel::Field().NICKNAME].toString());
    ui->label->setText(welcomeText);
}

welcomepage::~welcomepage()
{
    delete ui;
}

void welcomepage::on_pushButton_clicked()
{
    ImageDialog image;
    image.setModal(true);
    image.exec();
}

void welcomepage::on_pushButton_2_clicked()
{
    textDialog texta;
    texta.setModal(true);
    texta.exec();
}

void welcomepage:: showTime()
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


void welcomepage::on_pushButton_3_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Images"), "/Users/DELL/Desktop/pics",
                                                     tr("Image Files(*.png *.xpm *.jpg *.bmp)"));
    if(!fileName.isEmpty())
    {
        QImage image(fileName);
        ui->pic_uploader->setPixmap(QPixmap::fromImage(image));
    }
}

void welcomepage::on_toolButton_6_clicked()
{
   // this->hide();
    login loga;
    loga.setModal(true);
    loga.exec();
}

void welcomepage::on_toolButton_11_clicked()
{
    this->hide();
    Generapage gen;
    gen.setModal(true);
    gen.exec();
}
