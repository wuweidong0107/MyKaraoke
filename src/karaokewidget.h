#ifndef KARAOKEWIDGET_H
#define KARAOKEWIDGET_H

#include <QWidget>

class KaraokeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KaraokeWidget(QWidget *parent = nullptr);
    
public slots:
    void playCurrent();

signals:
    
};

#endif // KARAOKEWIDGET_H
