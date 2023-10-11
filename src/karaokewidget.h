#ifndef KARAOKEWIDGET_H
#define KARAOKEWIDGET_H

#include <QWidget>
#include <QMutex>
#include "playerrenderer.h"

class KaraokeSong;

class KaraokeWidget : public QWidget
{
    Q_OBJECT
public:
    explicit KaraokeWidget(QWidget *parent = nullptr);
    
public slots:
    void playCurrent();
    void karaokeSongLoaded();

protected:
    void paintEvent(QPaintEvent *);
signals:

private:
    friend class PlayerRenderer;
    
    QImage* switchImages();
    
    KaraokeSong* m_karaoke;
    mutable QMutex m_karaokeMutex;
    PlayerRenderer* m_renderer;
    QImage* m_images[2];
    int m_drawImageIndex;
    QMutex m_imageMutex;
};

#endif // KARAOKEWIDGET_H
