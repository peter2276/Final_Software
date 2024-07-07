#include "mainwindow.h"
#include "systemmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    SystemManager* Manager = SystemManager::getInstance();
    Manager->CreateController();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
