#include "mainwindow.h"
#include "systemmanager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    SystemManager* Manager = SystemManager::getInstance();
    Manager->CreateController();

    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("./casa.png"));
    MainWindow w(SystemManager::getInstance());
    w.show();
    return a.exec();
}
