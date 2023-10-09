#include "karaokesong.h"
#include "karaokeplayable.h"
#include "mediaplayer_gstreamer.h"

KaraokeSong::KaraokeSong(KaraokeWidget *w, const SongQueueItem &song)
{
    m_widget = w;
    m_song = song;
    mPlayer = new MediaPlayer_GStreamer(this);
}

KaraokeSong::~KaraokeSong()
{
    delete mPlayer;
}

bool KaraokeSong::open()
{
    if (KaraokePlayable::isVideoFile(m_song.file)) {
        m_musicFileName = m_song.file;
        mPlayer->loadMedia(m_musicFileName, MediaPlayer::LoadAudioStream | MediaPlayer::LoadVideoStream);
        
    } else {
        // Audio file
        return false;
    }
    return true;
}

void KaraokeSong::stop()
{
    
}
