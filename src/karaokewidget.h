#ifndef KARAOKEWIDGET_H
#define KARAOKEWIDGET_H

#include <QWidget>
#include <QMutex>

class KaraokeSong;

class KaraokeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KaraokeWidget(QWidget *parent = nullptr);
    
public slots:
    void playCurrent();

signals:

private:
    KaraokeSong *m_karaoke;
    mutable QMutex m_karaokeMutex;    
};

#endif // KARAOKEWIDGET_H
