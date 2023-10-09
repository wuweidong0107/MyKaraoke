#ifndef MEDIAPLAYER_H
#define MEDIAPLAYER_H

#include <QIODevice>
#include <QPainter>

class MediaPlayer
{
    public:
        MediaPlayer( QObject * ) {}
        virtual ~MediaPlayer() {}

        // Player state
        enum State
        {
            StateReset,
            StateStopped,
            StatePlaying,
            StatePaused,
        };

        // Options used in loadMedia
        enum LoadOption
        {
            LoadAudioStream = 0x1,
            LoadVideoStream = 0x2
        };

        // Capabilities used in getCapabilities and changeCapability
        enum Capability
        {
            CapChangeVolume = 0x1,
            CapChangePitch = 0x2,
            CapChangeTempo = 0x4,
            CapVoiceRemoval = 0x8,
        };

        Q_DECLARE_FLAGS(LoadOptions, LoadOption)
        Q_DECLARE_FLAGS(Capabilities, Capability)        

    signals:
        // The media file is loaded, and is ready to play
        // (this however does not guarantee it will be played)
        virtual void    loaded() = 0;

        // The media file has finished naturally
        virtual void    finished() = 0;

        // The media file cannot be loaded, or finished with an error
        virtual void    error( QString text ) = 0;

        // Media tags are available
        virtual void    tagsChanged( QString artist, QString title ) = 0;

        // Media duration changed/became available
        virtual void    durationChanged() = 0;

        // For logging
        virtual void    logging( const QString& facility, const QString& message ) = 0;

    public:

        // Returns pointer to the player's QObject (which can be used to connect to signals)
        // This is necessary since MediaPlayer_GStreamer interface is not inherited from QObject, and
        // thus the applicaiton code will not otherwise allow connection without dynamic_cast.
        virtual QObject* qObject() = 0;

        // Loads the media file, and plays audio, video or both
        virtual void    loadMedia( const QString &file, LoadOptions options ) = 0;

        // Loads the media file, and plays audio, video or both from a device.
        // Takes ownership of the device, and will delete it upon end
        virtual void    loadMedia( QIODevice * device, LoadOptions options ) = 0;

        //
        // Player actions
        //
        virtual void    play() = 0;
        virtual void    pause() = 0;
        virtual void    seekTo( qint64 pos ) = 0;
        virtual void    stop() = 0;

        // Reports player media position and duration. Returns -1 if unavailable.
        virtual qint64  position() = 0;
        virtual qint64  duration() = 0;

        // Reports current player state
        virtual State   state() const = 0;

        // Gets the media tags (if available)
        virtual void    mediaTags( QString& artist, QString& title ) = 0;

        // Sets the player capacity. The parameter is a value which differs:
        // CapChangeVolume: supports range from 0 (muted) - 100 (full)
        // CapChangePitch: supports range from -50 to +50 up to player interpretation
        // CapChangeTempo: supports range from -50 to +50 up to player interpretation
        // CapVoiceRemoval: supports values 0 (disabled) or 1 (enabled)
        virtual bool    setCapabilityValue( Capability cap, int value ) = 0;

        // Returns the supported player capabilities, which are settable (if available)
        virtual Capabilities capabilities() = 0;

        // Draws a last video frame using painter p on a rect. Does nothing if video is
        // not played, or not available.
        virtual void    drawVideoFrame( QPainter& p, const QRect& rect ) = 0;
};

Q_DECLARE_OPERATORS_FOR_FLAGS(MediaPlayer::LoadOptions)
Q_DECLARE_OPERATORS_FOR_FLAGS(MediaPlayer::Capabilities)
Q_DECLARE_INTERFACE( MediaPlayer, "MediaPlayer" )

#endif // MEDIAPLAYER_H
