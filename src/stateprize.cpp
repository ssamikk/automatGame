#include "stateprize.h"

StatePrize::StatePrize(QObject *obj): State(obj)
{

}

State::TypeState StatePrize::typeState()
{
    return State::TS_SizePrize;
}

bool StatePrize::enableStart()
{
    return false;
}

bool StatePrize::enableFinish()
{
    return false;
}
