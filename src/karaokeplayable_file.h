#ifndef KARAOKEPLAYABLE_FILE_H
#define KARAOKEPLAYABLE_FILE_H

#include "karaokeplayable.h"

class KaraokePlayable_File : public KaraokePlayable
{
public:
    KaraokePlayable_File(const QString &baseFile, QTextCodec* filenameDecoder);
};

#endif // KARAOKEPLAYABLE_FILE_H
