#include <QApplication>

#include "mainwindow.h"
#include "logger.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Set data for QSettings
    QCoreApplication::setOrganizationName("MyKaraoke");
    QCoreApplication::setOrganizationDomain("MyKaraoke.com");
    QCoreApplication::setApplicationName("MyKaraoke");
    
    Logger::init();
    Logger::debug("Hello, there!");
    
    MainWindow w;
    w.show();
    return a.exec();
}
