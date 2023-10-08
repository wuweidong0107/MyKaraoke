#include "songqueue.h"

SongQueue *pSongQueue;

SongQueue::SongQueue(QObject *parent) : QObject(parent)
{
    m_currentSong = 0;
}

void SongQueue::addSong(const QString &singer, const QString &file)
{
    SongQueueItem *entry = new SongQueueItem();

    entry->file = file;
    entry->singer = singer;
    entry->state = SongQueueItem::STATE_READY;
    
    m_queue.append(entry);
}

bool SongQueue::isEmpty() const
{
    return m_queue.isEmpty();
}

SongQueueItem SongQueue::current() const
{
    return *m_queue[m_currentSong];
}
