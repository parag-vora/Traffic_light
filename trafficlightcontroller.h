#ifndef TRAFFICLIGHTCONTROLLER_H
#define TRAFFICLIGHTCONTROLLER_H

#include <QObject>
#include <QTimer>

class TrafficLightController : public QObject
{
    Q_OBJECT

public:
    explicit TrafficLightController(QObject *parent = nullptr);

    Q_INVOKABLE void Button(); // Trigger for buttom

signals:
    void redLight();       // Signal for red light
    void yellowLight();    // Signal for yellow light
    void greenLight();     // Signal for green light

public slots:
    void startSequence();   // start

private slots:
    void updateState();    // update state of the signal

private:
    enum State { Red, YellowToGreen, Green, YellowToRed };
    State g_currentState;
    QTimer g_timer;
    bool g_triggerActivated;
};

#endif // TRAFFICLIGHTCONTROLLER_H
