#ifndef TEXTDIALOG_H
#define TEXTDIALOG_H

#include <QDialog>
#include "httprequestworker.h"

namespace Ui {
class textDialog;
}

class textDialog : public QDialog
{
    Q_OBJECT

public:
    explicit textDialog(QWidget *parent = 0);
    ~textDialog();

private slots:
    void on_pushButton_2_clicked();

   void on_pushButton_clicked();
    void showTime();
    void handle_result(HttpRequestWorker *worker);
    void on_commandLinkButton_clicked();

    void on_toolButton_4_clicked();

private:
    Ui::textDialog *ui;
    QString fileName;
};

#endif // TEXTDIALOG_H
