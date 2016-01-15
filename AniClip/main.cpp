#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QStandardPaths>
#include <QDebug>

int main(int argc, char *argv[])
{

    QString appData_path = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    QDir dir(appData_path);
    if (!dir.exists()){
        dir.mkpath(appData_path);
    }
    if (!dir.exists("AniClip")){
        dir.mkpath("AniClip");
    }

    dir.cd("AniClip");
    QDir::setCurrent(dir.absolutePath());
    qDebug()<<QDir::current();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}
