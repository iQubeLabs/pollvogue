#include "d_main.h"
#include "QWidget"
#include <QWidget>
#include <QApplication>

int main(int argc, char *argv[])
{
   // Q_INIT_RESOURCE(pollvo);
    QApplication a(argc, argv);
    d_main w;
   // w.showMaximized();
    //win.resize(800, 600);


    w.show();
   //xformWidget.sh
    return a.exec();
}
