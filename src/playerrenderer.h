#ifndef PLAYERRENDERER_H
#define PLAYERRENDERER_H

#include <QThread>
#include <QImage>

class KaraokeWidget;

class PlayerRenderer : public QThread
{
public:
    explicit PlayerRenderer(QImage *render, KaraokeWidget *parent);
    
private:
    void run();
    
    QAtomicInt m_continue;
    KaraokeWidget *m_widget;
    QImage* m_renderImage;
};

#endif // PLAYERRENDERER_H
