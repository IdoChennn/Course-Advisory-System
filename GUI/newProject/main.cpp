#include "mainwindow.h"
#include <QFile>

///
///This is the entry of the program
///
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
