#ifndef STATEMASHIN_H
#define STATEMASHIN_H

#include "state.h"
#include <QObject>
#include <QTimer>


class StateMashin: public QObject
{
    Q_OBJECT
public:
    StateMashin(QObject *obj = nullptr);
    ~StateMashin();
    Q_INVOKABLE void nextStep();
    void setEnableStart(bool);
    bool isEnableStart ( ) const;
    void setEnableStop(bool);
    bool isEnableStop ( ) const;
    Q_INVOKABLE void setPrize(int first, int second, int third);
    qulonglong prizeValue();
signals:
    void firstDrumpRotait();
    void secondDrumpRotait();
    void thirdDrumpRotait();
    void enableStartChanged(bool);
    void enableStopChanged(bool);
    void prizeValueChanged(qulonglong);
    void needRaschet();
private slots:
    void stopByTimer();
private:
    State *state;
    Q_PROPERTY (bool enableStart WRITE setEnableStart READ isEnableStart NOTIFY enableStartChanged)
    bool enableStart;
    Q_PROPERTY (bool enableStop WRITE setEnableStop READ isEnableStop NOTIFY enableStopChanged)
    bool enableStop;
    Q_PROPERTY(qulonglong prize READ prizeValue NOTIFY prizeValueChanged)
    qulonglong prize;
    QTimer timer;
};

#endif // STATEMASHIN_H
