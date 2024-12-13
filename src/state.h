#ifndef STATE_H
#define STATE_H

#include <QObject>



class State: public QObject
{
    Q_OBJECT
public:
    enum TypeState {
        TS_Wait,
        TS_RotateDrum,
        TS_SizePrize
    };

    State(QObject* obj = 0);
    virtual ~State();
    virtual TypeState typeState() = 0;
    virtual bool enableStart() = 0;
    virtual bool enableFinish() = 0;
signals:
    void firstDrumpRotait();
    void secondDrumpRotait();
    void thirdDrumpRotait();
};

#endif // STATE_H
