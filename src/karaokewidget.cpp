#include "karaokewidget.h"
#include "actionhandler.h"
#include "songqueue.h"
#include "logger.h"
#include "karaokesong.h"

KaraokeWidget::KaraokeWidget(QWidget *parent) : QWidget(parent)
{
    connect(pActionHandler, &ActionHandler::actionKaraokePlayerStart, this, &KaraokeWidget::playCurrent);    
}

void KaraokeWidget::playCurrent()
{
    if (pSongQueue->isEmpty()) {
        return;
    }
    
    SongQueueItem current = pSongQueue->current();
    
    if (current.state == SongQueueItem::STATE_READY) {
        KaraokeSong *karfile = new KaraokeSong(this, current);
        if (!karfile->open()) {
            delete karfile;
            return;
        }
        
        m_karaokeMutex.lock();
    
        if ( m_karaoke )
        {
            qWarning("BUG: new karaoke is started while the old is not stoppped!");
            m_karaoke->stop();
            delete m_karaoke;
        }
    
        m_karaoke = karfile;
        m_karaokeMutex.unlock();
    
        Logger::debug("KaraokeWidget: waiting for the song being loaded");
    }
}
