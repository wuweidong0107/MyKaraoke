#ifndef KARAOKESONG_H
#define KARAOKESONG_H

#include <QObject>
#include "songqueue.h"

class KaraokeWidget;
class MediaPlayer_GStreamer;

class KaraokeSong : public QObject
{
    Q_OBJECT
public:
    KaraokeSong(KaraokeWidget * w, const SongQueueItem& song);
    ~KaraokeSong();
    
    bool open();
    void stop();

signals:
    
private:
    KaraokeWidget *m_widget;
    SongQueueItem m_song;
    QString m_musicFileName;
    MediaPlayer_GStreamer *mPlayer;
};

#endif // KARAOKESONG_H
