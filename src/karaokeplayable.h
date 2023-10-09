#ifndef KARAOKEPLAYABLE_H
#define KARAOKEPLAYABLE_H

#include <QString>

class KaraokePlayable
{
public:
    KaraokePlayable(const QString& baseFile, QTextCodec* filenameDecoder);
    virtual ~KaraokePlayable();
    
    static bool isVideoFile(const QString& filename);
    
private:
    QString m_baseFile;
    QTextCodec* m_filenameDecoder;
};

#endif // KARAOKEPLAYABLE_H
