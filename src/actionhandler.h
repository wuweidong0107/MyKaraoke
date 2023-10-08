#ifndef ACTIONHANDLER_H
#define ACTIONHANDLER_H

#include <QObject>

class ActionHandler : public QObject
{
    Q_OBJECT
public:
    explicit ActionHandler(QObject *parent = nullptr);
    void enqueueSong(QString singer, QString path);
    
signals:
    void actionKaraokePlayerStart();
};

extern ActionHandler *pActionHandler;

#endif // ACTIONHANDLER_H
