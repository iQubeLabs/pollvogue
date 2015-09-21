#include "generapage.h"
#include "sql.h"
#include "ui_generapage.h"
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

Generapage::Generapage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Generapage)
{
    ui->setupUi(this);
}

Generapage::~Generapage()
{
    delete ui;
}

void Generapage::on_tableView_viewportEntered()
{
    QString textimage,yes,no,maybe,poll_titlemage,ratioImage,
     created_at;
     QFile image;
//     image=ui->pic_uploader->setPixmap(QPixmap::fromImage(image));
     
//    poll_titlemage=ui->tableView->text();
//    textimage=ui->tableView->text();
//    yes=ui->tableView->text();
//    no=ui->tableView->text();
//    maybe=ui->tableView->text();
//    ratioImage=ui->tableView->text();
//    created_at=ui->tableView->text();
    
    QString url_str = "http://iqubebase.com/pollvogue-api/public/image/list";
    
        HttpRequestInput input(url_str, "GET");
    
//        input.add_var("poll_titlemage", poll_titlemage);
//        input.add_var("textimage", textimage);
//        input.add_var(" yes",  yes);
//        input.add_var("no", no);
//        input.add_var("maybe", maybe);
//        input.add_var("maybe", textimage);
//        input.add_var("ratioImage", ratioImage);
//        input.add_var("created_at", created_at);
//        input.add_file("image", "..\/contents\/imagesforpoll\/eccbc87e4b5ce2fe28308fd9f2a7baf3.jpg",NULL, "image");
        
    
        HttpRequestWorker *worker = new HttpRequestWorker(this);
        connect(worker, SIGNAL(on_execution_finished(HttpRequestWorker*)), this, SLOT(handle_result(HttpRequestWorker*)));
        worker->execute(&input);
}
