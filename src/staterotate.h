#ifndef STATEROTATE_H
#define STATEROTATE_H

#include "state.h"



class StateRotate: public State
{
    Q_OBJECT
public:
    StateRotate(QObject* obj = 0);

    // State interface
public:
    TypeState typeState() override;
    bool enableStart() override;
    bool enableFinish() override;
};

#endif // STATEROTATE_H
