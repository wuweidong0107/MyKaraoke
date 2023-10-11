#ifndef KARAOKEPLAYABLE_H
#define KARAOKEPLAYABLE_H

#include <QString>

class KaraokePlayable
{
public:
    KaraokePlayable(const QString& baseFile, QTextCodec* filenameDecoder);
    virtual ~KaraokePlayable();
    
    static bool isVideoFile(const QString& filename);
    static KaraokePlayable* create( const QString& baseFile, QTextCodec* filenameDecoder = 0 );
    
    bool parse4Video();
    QString musicObject() const;

private:
    QString m_baseFile;
    QTextCodec* m_filenameDecoder;
    QString m_musicObject;
};

#endif // KARAOKEPLAYABLE_H
