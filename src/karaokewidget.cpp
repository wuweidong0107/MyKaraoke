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
    }
}
