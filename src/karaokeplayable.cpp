#include "karaokeplayable.h"
#include "karaokeplayable_file.h"

KaraokePlayable::KaraokePlayable(const QString &baseFile, QTextCodec *filenameDecoder)
{
    m_baseFile = baseFile;
    m_filenameDecoder = filenameDecoder;
}

KaraokePlayable::~KaraokePlayable()
{
    
}

bool KaraokePlayable::isVideoFile(const QString &filename)
{
    static const char * extlist[] = { ".mp4", ".mov", ".avi", ".mkv", ".3gp", ".flv", ".wmv", 0 };

    for (int i = 0; extlist[i]; i++) {
        if (filename.endsWith(extlist[i], Qt::CaseInsensitive)) {
            return true;
        }
    }

    return false;
}

KaraokePlayable *KaraokePlayable::create(const QString &baseFile, QTextCodec *filenameDecoder)
{
    KaraokePlayable* obj = nullptr;
    obj = new KaraokePlayable_File(baseFile, filenameDecoder);
    return obj;
}

bool KaraokePlayable::parse4Video()
{
    if (isVideoFile(m_baseFile))
        m_musicObject = m_baseFile;
    
    return true;
}

QString KaraokePlayable::musicObject() const
{
    return m_musicObject;
}
