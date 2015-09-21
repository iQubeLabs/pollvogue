#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include <QString>
#include <QDialog>

namespace Ui {
class welcomepage;
}

class welcomepage : public QDialog
{
    Q_OBJECT

public:
    explicit welcomepage(QWidget *parent = 0);
    ~welcomepage();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void showTime();

    void on_pushButton_3_clicked();

    void on_toolButton_6_clicked();
   // void handle_result(HttpRequestWorker *worker);



    void on_toolButton_11_clicked();

private:
    Ui::welcomepage *ui;
};

#endif // WELCOMEPAGE_H
