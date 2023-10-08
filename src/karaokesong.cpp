#include "karaokesong.h"

KaraokeSong::KaraokeSong(KaraokeWidget *w, const SongQueueItem &song)
{
    m_widget = w;
    m_song = song;
}
