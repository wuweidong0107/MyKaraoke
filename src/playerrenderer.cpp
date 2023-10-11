#include <QTime>
#include "playerrenderer.h"
#include "currentstate.h"
#include "karaokepainter.h"
#include "karaokewidget.h"
#include "karaokesong.h"
#include "logger.h"

PlayerRenderer::PlayerRenderer(QImage * render, KaraokeWidget *parent)
{
    m_widget = parent;
    m_continue = 1;
    m_renderImage = render;
}

void PlayerRenderer::run()
{
    QTime next_cycle;
    while (m_continue) {
        next_cycle = QTime::currentTime().addMSecs( 1000 / 60 );
        m_renderImage->fill(Qt::yellow);
        KaraokePainter p(m_renderImage);
        p.setClipAreaMain();
        
        if (pCurrentState->playerState == CurrentState::PLAYERSTATE_PLAYING) {
            m_widget->m_karaokeMutex.lock();
            m_widget->m_karaoke->draw(p);
            
            m_widget->m_karaokeMutex.unlock();
            p.end();
            m_renderImage = m_widget->switchImages();
        }
        
        Logger::debug("--------->%d", m_widget->m_drawImageIndex);
        // When should we have next tick?
        int remainingms = qMax( QTime::currentTime().msecsTo( next_cycle ), 5 );
        msleep( remainingms );
    }
}
