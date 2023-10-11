#include "karaokepainter.h"
#include "logger.h"

KaraokePainter::KaraokePainter(QImage *img)
    : QPainter( img )
{
    m_image = img;
    m_rect = img->rect();
}

void KaraokePainter::setClipAreaMain()
{
    Logger::debug("%s %d x %d", __FUNCTION__, m_image->width(), m_image->height());
    m_rect = QRect( 0, 0, m_image->width(), m_image->height());
}
