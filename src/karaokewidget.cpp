#include <QPainter>

#include "karaokewidget.h"
#include "actionhandler.h"
#include "songqueue.h"
#include "logger.h"
#include "karaokesong.h"
#include "playerrenderer.h"

KaraokeWidget::KaraokeWidget(QWidget *parent) : QWidget(parent)
{
    m_karaoke = nullptr;
    connect(pActionHandler, &ActionHandler::actionKaraokePlayerStart, this, &KaraokeWidget::playCurrent);    

    // 0 is set as draw image
    m_images[0] = new QImage(100, 100, QImage::Format_ARGB32);
    m_images[0]->fill( Qt::black );
    m_drawImageIndex = 0;

    // 1 as render image
    m_images[1] = new QImage(100, 100, QImage::Format_ARGB32);
    m_renderer = new PlayerRenderer(m_images[1], this );
    m_renderer->start();
}

void KaraokeWidget::playCurrent()
{
    if (pSongQueue->isEmpty()) {
        return;
    }
    
    SongQueueItem current = pSongQueue->current();   
    Logger::debug("%s", __FUNCTION__);
    if (current.state == SongQueueItem::STATE_READY) {
        KaraokeSong *karfile = new KaraokeSong(this, current);
        Logger::debug("%s 2", __FUNCTION__);
        if (!karfile->open()) {
            delete karfile;
            return;
        }
        Logger::debug("%s 3", __FUNCTION__);
        m_karaokeMutex.lock();
    
        if (m_karaoke) {
            qWarning("BUG: new karaoke is started while the old is not stoppped!");
            m_karaoke->stop();
            delete m_karaoke;
        }
    
        m_karaoke = karfile;
        m_karaokeMutex.unlock();
    
        Logger::debug("KaraokeWidget: waiting for the song being loaded");
    }
}

void KaraokeWidget::karaokeSongLoaded()
{
    Logger::debug("KaraokeWidget: song loaded successfully, starting");
    m_karaoke->start();
}

void KaraokeWidget::paintEvent(QPaintEvent *)
{
    QPainter p( this );
    QRect prect = QRect( 0, 0, width(), height() );

    m_imageMutex.lock();
    Logger::debug("%s %d. %dx%d", __FUNCTION__, m_drawImageIndex, m_images[ m_drawImageIndex ]->width(), m_images[ m_drawImageIndex ]->height());
    p.drawImage( prect, *m_images[ m_drawImageIndex ] );
    m_imageMutex.unlock();
}


QImage *KaraokeWidget::switchImages()
{
    int newRenderImage;

    // The current draw image, however, can be touched in draw(),
    // so we should not touch it until we switch the pointer
    m_imageMutex.lock();

    if ( m_drawImageIndex == 0 )
    {
        newRenderImage = 0;
        m_drawImageIndex = 1;
    }
    else
    {
        newRenderImage = 1;
        m_drawImageIndex = 0;
    }

    m_imageMutex.unlock();

    // We have switched the draw image which now uses our image; see if we need to resize the current QImage before returning it
    if ( m_images[newRenderImage]->size() != size() )
    {
        delete m_images[newRenderImage];
        m_images[newRenderImage] = new QImage( size(), QImage::Format_ARGB32 );
    }

    // Queue a refresh event for ourselves - note Qt::QueuedConnection as we're calling from a different thread!
    QMetaObject::invokeMethod( this, "update", Qt::QueuedConnection );

    return m_images[newRenderImage];
}
