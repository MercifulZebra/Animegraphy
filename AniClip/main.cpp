#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{

    QString appData_path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);


    QApplication a(argc, argv);
    MainWindow w("aniclip_config.txt");
    w.show();



    return a.exec();
}
