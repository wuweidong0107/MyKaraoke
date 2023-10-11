#ifndef KARAOKESONG_H
#define KARAOKESONG_H

#include <QObject>
#include "songqueue.h"

class KaraokeWidget;
class MediaPlayer_GStreamer;
class KaraokePainter;

class KaraokeSong : public QObject
{
    Q_OBJECT
public:
    KaraokeSong(KaraokeWidget * w, const SongQueueItem& song);
    ~KaraokeSong();
    
    bool open();
    void stop();
    qint64 draw(KaraokePainter& p);
    
public slots:
    void start();
    
signals:
    
private slots:
    void songLoaded();

private:
    KaraokeWidget *m_widget;
    SongQueueItem m_song;
    QString m_musicFileName;
    MediaPlayer_GStreamer *mPlayer;
};

#endif // KARAOKESONG_H
