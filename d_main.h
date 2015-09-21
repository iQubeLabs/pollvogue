#ifndef D_MAIN_H
#define D_MAIN_H
#include "httprequestworker.h"
#include <QMainWindow>

namespace Ui {
class d_main;
}

class d_main : public QMainWindow
{
    Q_OBJECT

public:
    explicit d_main(QWidget *parent = 0);
    ~d_main();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void showTime();

   // void handle_result(HttpRequestWorker *worker);



    void on_toolButton_4_clicked();

private:
    Ui::d_main *ui;
};

#endif // D_MAIN_H
