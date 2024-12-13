#include "staterotate.h"

#include <QTimer>

StateRotate::StateRotate(QObject* obj): State(obj)
{
    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &StateRotate::firstDrumpRotait);
    timer->start(100);
    QTimer *timerSecond = new QTimer(this);
    connect(timerSecond, &QTimer::timeout, this, &StateRotate::secondDrumpRotait);
    timerSecond->start(90);
    QTimer *timerThird = new QTimer(this);
    connect(timerThird, &QTimer::timeout, this, &StateRotate::thirdDrumpRotait);
    timerThird->start(110);
}

State::TypeState StateRotate::typeState()
{
    return State::TS_RotateDrum;
}

bool StateRotate::enableStart()
{
    return false;
}

bool StateRotate::enableFinish()
{
    return true;
}
