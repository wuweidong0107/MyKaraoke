#ifndef CURRENTSTATE_H
#define CURRENTSTATE_H

#include <QObject>

class CurrentState : public QObject
{
    Q_OBJECT
public:
    enum
    {
        PLAYERSTATE_STOPPED,
        PLAYERSTATE_PLAYING,
        PLAYERSTATE_PAUSED
    };
    
    explicit CurrentState(QObject *parent = nullptr);
    QAtomicInt playerState;
    
signals:
    
};

extern CurrentState *pCurrentState;

#endif // CURRENTSTATE_H
