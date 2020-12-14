#include "mainwindow.h"
#include <QApplication>
#include <QVariant>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Message>(); //Required for queued signal-slot connections
                                  //For creation of custom types during run-time.
    MainWindow w;
    w.show();
    return a.exec();
}
