#ifndef STATEWAIT_H
#define STATEWAIT_H

#include "state.h"



class StateWait: public State
{
    Q_OBJECT
public:
    StateWait(QObject* obj = 0);

    // State interface
public:
    TypeState typeState() override;
    bool enableStart() override;
    bool enableFinish() override;
};

#endif // STATEWAIT_H
