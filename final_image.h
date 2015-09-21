#ifndef FINAL_IMAGE_H
#define FINAL_IMAGE_H

#include <QDialog>

namespace Ui {
class final_image;
}

class final_image : public QDialog
{
    Q_OBJECT

public:
    explicit final_image(QWidget *parent = 0);
    ~final_image();

private slots:
    void on_pushButton_2_clicked();
    void showTime();
   // void handle_result(HttpRequestWorker *worker);



    void on_toolButton_4_clicked();

private:
    Ui::final_image *ui;
};

#endif // FINAL_IMAGE_H
