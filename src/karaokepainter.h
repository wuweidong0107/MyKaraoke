#ifndef KARAOKEPAINTER_H
#define KARAOKEPAINTER_H

#include <QPainter>

class KaraokePainter : public QPainter
{
public:
    KaraokePainter(QImage* img);
    QSize size() const { return m_rect.size(); }
    QRect rect() const { return m_rect; }
    void setClipAreaMain();
    
private:
    QImage* m_image;
    QRect m_rect;
};

#endif // KARAOKEPAINTER_H
