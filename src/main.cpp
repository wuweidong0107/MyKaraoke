#include <QApplication>
#include <QScopedPointer>
#include <QTranslator>
#include <QCommandLineParser>
#include <QRect>
#include <QScreen>

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
    
    QScopedPointer<MainWindow> p (new MainWindow());
    p.data()->show();
    
    QCommandLineParser parser;
    const QCommandLineOption fullScreenOption(
                QStringList() << "fs" << "fullScreen",
                QCoreApplication::tr("Toggle full screen")
                );
    const QCommandLineOption fileNameOption(
                QStringList() << "file" << "fileName",
                QCoreApplication::tr("File name to play"),
                QCoreApplication::tr("File name to play")
                );
    const QCommandLineOption displayOption(
                QStringList() << "d" << "displayNumber",
                QCoreApplication::tr("Display number"),
                QCoreApplication::tr("Screen")
                );
    
    parser.addOption(fullScreenOption);
    parser.addOption(fileNameOption);
    parser.addOption(displayOption);
    parser.addHelpOption();
    parser.process(a);
    
    const int displayNumber = parser.value(displayOption).toInt();

    if (displayNumber && displayNumber < a.screens().size()) {
        const QRect resolution = a.screens()[displayNumber]->availableGeometry();
        p.data()->move(resolution.x(),resolution.y());
    }

    MainWindow w;
    w.show();
    return a.exec();
}
