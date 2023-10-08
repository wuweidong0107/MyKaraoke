#ifndef SONGQUEUEITEM_H
#define SONGQUEUEITEM_H

#include <QString>

class SongQueueItem
{
public:
    SongQueueItem();
    
    enum State
    {
        STATE_NOT_READY,    // Song is not present in the local storage and cannot be played
        STATE_GETTING_READY,// Song is getting ready - converting or downloading
        STATE_READY,        // Song is ready for playing
        STATE_PLAYING,      // Song is being played
    };
    
    int         id;         
    int         songid;     
    QString     file;       
    QString     title;      
    QString     artist;     
    QString     singer;     
    State       state;      
    int         readiness;      
};

#endif // SONGQUEUEITEM_H
