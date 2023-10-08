#ifndef SONGQUEUE_H
#define SONGQUEUE_H

#include <QObject>

#include "songqueueitem.h"

class SongQueue : public QObject
{
    Q_OBJECT
public:
    explicit SongQueue(QObject *parent = nullptr);
    void addSong(const QString& singer, const QString& file);
    bool isEmpty() const;
    SongQueueItem current() const;    

signals:
    
private:
    QList<SongQueueItem *> m_queue;
    unsigned int m_currentSong;
};

extern SongQueue * pSongQueue;

#endif // SONGQUEUE_H
