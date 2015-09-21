#ifndef GENERAPAGE_H
#define GENERAPAGE_H

#include <QDialog>

namespace Ui {
class Generapage;
}

class Generapage : public QDialog
{
    Q_OBJECT

public:
    explicit Generapage(QWidget *parent = 0);
    ~Generapage();

private slots:
    void on_tableView_viewportEntered();
    
private:
    Ui::Generapage *ui;
};

#endif // GENERAPAGE_H
