#include "actionhandler.h"
#include "songqueue.h"
#include "currentstate.h"
#include "logger.h"

ActionHandler *pActionHandler;
ActionHandler::ActionHandler(QObject *parent) : QObject(parent)
{
    
}

void ActionHandler::enqueueSong(QString singer, QString path)
{
    pSongQueue->addSong(singer, path);

    if (pCurrentState->playerState == CurrentState::PLAYERSTATE_STOPPED) {
        Logger::debug("%s 2", __FUNCTION__);
        emit actionKaraokePlayerStart();
    }
}
