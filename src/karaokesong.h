#ifndef KARAOKESONG_H
#define KARAOKESONG_H

#include <QObject>
#include "songqueue.h"

class KaraokeWidget;

class KaraokeSong : public QObject
{
    Q_OBJECT
public:
    KaraokeSong(KaraokeWidget * w, const SongQueueItem& song);
    
signals:
    
private:
    KaraokeWidget *m_widget;
    SongQueueItem m_song;
};

#endif // KARAOKESONG_H
