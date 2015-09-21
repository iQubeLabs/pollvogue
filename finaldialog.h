#ifndef FINALDIALOG_H
#define FINALDIALOG_H
#include "httprequestworker.h"
#include <QDialog>

namespace Ui {
class finalDialog;
}

class finalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit finalDialog(QWidget *parent = 0);
    ~finalDialog();

private slots:
    void on_pushButton_2_clicked();
    void showTime();
//    void handle_result(HttpRequestWorker *worker);



    void on_toolButton_4_clicked();

private:
    Ui::finalDialog *ui;
};

#endif // FINALDIALOG_H
