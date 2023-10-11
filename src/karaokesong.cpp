#include "karaokesong.h"
#include "karaokeplayable.h"
#include "mediaplayer_gstreamer.h"
#include "logger.h"
#include "karaokewidget.h"
#include "currentstate.h"
#include "karaokepainter.h"

KaraokeSong::KaraokeSong(KaraokeWidget *w, const SongQueueItem &song)
{
    m_widget = w;
    m_song = song;
    mPlayer = new MediaPlayer_GStreamer(this);
    connect(mPlayer, SIGNAL(loaded()), this, SLOT(songLoaded()));
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
        Logger::debug( "KaraokeSong: video file is being loaded" );
        
        QScopedPointer<KaraokePlayable> karaoke(KaraokePlayable::create( m_song.file ));
        Logger::debug("%s 1", __FUNCTION__);
        if (!karaoke || !karaoke->parse4Video())
            return false;
        Logger::debug("%s 2", __FUNCTION__);
    } else {
        // Audio file
        return false;
    }
    Logger::debug("%s end", __FUNCTION__);
    return true;
}

void KaraokeSong::stop()
{
    pCurrentState->playerState = CurrentState::PLAYERSTATE_STOPPED;
}

qint64 KaraokeSong::draw(KaraokePainter &p)
{
    if (KaraokePlayable::isVideoFile(m_song.file)) {
        Logger::debug("%s 1", __FUNCTION__);
        mPlayer->drawVideoFrame(p, p.rect());
        Logger::debug("%s 2", __FUNCTION__);
    }
    Logger::debug("%s 3", __FUNCTION__);
    return 0;
}

void KaraokeSong::start()
{
    pCurrentState->playerState = CurrentState::PLAYERSTATE_PLAYING;
    mPlayer->play();
}

void KaraokeSong::songLoaded()
{
    m_widget->karaokeSongLoaded();
}
