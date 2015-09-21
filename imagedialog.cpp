#include "imagedialog.h"
#include "ui_imagedialog.h"
#include "sql.h"
#include <QMessageBox>
#include "finaldialog.h"
#include "welcomepage.h"
#include "final_image.h"
#include "generapage.h"
#include <QTimer>
#include <QDateTime>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include <httprequestworker.h>

ImageDialog::ImageDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImageDialog)
{
    ui->setupUi(this);
    QPixmap pi("/Users/DELL/Desktop/pics/jega.jpg");
    ui->pic_uploader->setPixmap(pi);
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),
             this,SLOT(showTime()));
    timer->start();
}

ImageDialog::~ImageDialog()
{
    delete ui;
}

void ImageDialog::on_pushButton_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Open Images"), "/",
                                                     tr("Image Files(*.png *.xpm *.jpg *.bmp)"));
    if(!fileName.isEmpty())
    {
        QImage image(fileName);
        ui->pic_uploader->setPixmap(QPixmap::fromImage(image));
    }
}
void ImageDialog:: showTime()
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


void ImageDialog::on_commandLinkButton_clicked()
{
    QString text;
          // QFile image;
    text=ui->textimage->text();
    QString mimeType = "image/png";

    ui->pic_uploader->setPixmap(QPixmap::fromImage(QImage(text)));

    QString url_str = "http://iqubebase.com/pollvogue-api/public/text/post";

    HttpRequestInput input(url_str, "POST");
    input.add_var("text", text);
    input.add_file("image", "",NULL,mimeType);

    HttpRequestWorker *worker = new HttpRequestWorker(this);
    connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
    worker->execute(&input);



}

void ImageDialog::on_toolButton_4_clicked()
{
    this->hide();
    Generapage gen;
    gen.setModal(true);
    gen.exec();
}

void ImageDialog::handle_result(HttpRequestWorker *worker)
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
            final_image fin;
            fin.setModal(true);
            fin.exec();
        }
        else
        {
            this->hide();
            ImageDialog iman;
             iman.setModal(true);
             iman.exec();
        }

    }
  else {
        // an error occurred
        msg = "Error: " + worker->error_str;
    }

    QMessageBox::information(this, "", msg);
}
