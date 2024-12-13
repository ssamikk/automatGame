#include "statewait.h"

StateWait::StateWait(QObject *obj): State(obj)
{

}

State::TypeState StateWait::typeState()
{
    return State::TS_Wait;
}

bool StateWait::enableStart()
{
    return true;
}

bool StateWait::enableFinish()
{
    return false;
}
