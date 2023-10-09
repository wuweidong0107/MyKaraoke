#include "karaokeplayable.h"

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
