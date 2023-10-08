#include <QFileDialog>
#include <QDir>

#include "mainwindow.h"
#include "actionhandler.h"
#include "logger.h"
#include "songqueue.h"
#include "currentstate.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), Ui::MainWindow()
{
    setupUi(this);
    
    pCurrentState = new CurrentState( this );
    
    pActionHandler = new ActionHandler(this);
    connect(actionPlay_file, &QAction::triggered, this, &MainWindow::menuOpenKaraoke);

    pSongQueue = new SongQueue(this);
}

MainWindow::~MainWindow()
{
}

void MainWindow::enqueueSong(const QString &fileName)
{
    if (fileName.isEmpty())
        return;
    
    pActionHandler->enqueueSong("", fileName);
}

void MainWindow::menuOpenKaraoke()
{
    const QString file = QFileDialog::getOpenFileName(
                0,
                "Open File",
                QDir::homePath(),
                "*.*"
                );

    enqueueSong(file);
}

