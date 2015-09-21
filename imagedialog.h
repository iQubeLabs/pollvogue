#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include <QFileDialog>
#include <QString>
#include <QLabel>
#include "httprequestworker.h"


namespace Ui {
class ImageDialog;
}

class ImageDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ImageDialog(QWidget *parent = 0);
    ~ImageDialog();

private slots:
    void on_pushButton_clicked();
    void showTime();
    void handle_result(HttpRequestWorker *worker);



    void on_commandLinkButton_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::ImageDialog *ui;
};

#endif // IMAGEDIALOG_H
