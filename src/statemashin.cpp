#include "statemashin.h"
#include "statewait.h"
#include "staterotate.h"
#include "stateprize.h"

StateMashin::StateMashin(QObject *obj): QObject(obj), prize(0)
{
    state = new StateWait();
    setEnableStart(state->enableStart());
    setEnableStop(state->enableFinish());
    connect(&timer, &QTimer::timeout, this, &StateMashin::stopByTimer);
}

StateMashin::~StateMashin()
{
    if (state != nullptr) {
        delete state;
    }
}

void StateMashin::nextStep()
{
    State::TypeState tState = state->typeState();
    delete state;
    switch (tState) {
    case State::TS_Wait:
        state = new StateRotate();
        connect(state, &State::firstDrumpRotait, this, &StateMashin::firstDrumpRotait);
        connect(state, &State::secondDrumpRotait, this, &StateMashin::secondDrumpRotait);
        connect(state, &State::thirdDrumpRotait, this, &StateMashin::thirdDrumpRotait);
        timer.start(10000);
        break;
    case State::TS_RotateDrum:
        state = new StatePrize();
        timer.stop();
        emit needRaschet();
        break;
    case State::TS_SizePrize:
    default:
        timer.stop();
        state = new StateWait();
        break;
    }
    setEnableStart(state->enableStart());
    setEnableStop(state->enableFinish());
}

void StateMashin::setEnableStart(bool flag)
{
    enableStart = flag;
    enableStartChanged(flag);
}

bool StateMashin::isEnableStart() const
{
    return enableStart;
}

void StateMashin::setEnableStop(bool flag)
{
    enableStop = flag;
    enableStopChanged(enableStop);
}

bool StateMashin::isEnableStop() const
{
    return enableStop;
}

void StateMashin::setPrize(int first, int second, int third)
{
    if (first == second && first == third) {
        prize += (first + 1) * 10;
    } else if (first == second || first == third){
        prize += (first + 1) * 2;
    } else if (second == third) {
        prize += (second + 1) * 2;
    }
    prizeValueChanged(prize);
    nextStep();
}

qulonglong StateMashin::prizeValue()
{
    return prize;
}

void StateMashin::stopByTimer(){
    nextStep();
}
