#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

class KaraokeWidget;

class MainWindow : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void enqueueSong(const QString &fileName);
        
public slots:
    void menuOpenKaraoke();
    
private:
    KaraokeWidget *m_widget;
};
#endif // MAINWINDOW_H
