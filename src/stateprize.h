#ifndef STATEPRIZE_H
#define STATEPRIZE_H

#include "state.h"



class StatePrize : public State
{
    Q_OBJECT
public:
    StatePrize(QObject* obj = 0);

    // State interface
    TypeState typeState() override;
    bool enableStart() override;
    bool enableFinish() override;
};

#endif // STATEPRIZE_H
