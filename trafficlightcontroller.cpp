#include "trafficlightcontroller.h"
#include <QDebug>

TrafficLightController::TrafficLightController(QObject *parent)
    : QObject(parent), g_currentState(Red), g_triggerActivated(false) {
    connect(&g_timer, &QTimer::timeout, this, &TrafficLightController::updateState);
}

void TrafficLightController::startSequence() {
    g_currentState = Red;
    emit redLight(); // initially red light
    g_timer.start(30000); // red light for 30 S
}

void TrafficLightController::Button() {
    qDebug() << "Triggered";
    if (g_currentState == Green) {  // if it is green then immediatially change to yellow
        g_currentState = YellowToRed;
        qDebug() << "Triggered: Green to Yellow";
        g_timer.stop();          // Stop the timer of green
        g_timer.start(5000);     // yellow light for 5 S
        emit yellowLight();
        g_triggerActivated = false;
    } else {
        g_triggerActivated = true;
    }
}

void TrafficLightController::updateState() {
    if (g_triggerActivated) {
        if (g_currentState == YellowToGreen || g_currentState == YellowToRed) {
            qDebug() << "Triggered: Wait for Yellow to finish";
            g_triggerActivated = false;
            return;
        } else if (g_currentState == Red) {
            qDebug() << "Triggered: Red remains Red";
            g_timer.start(30000); // Extend the time of red light for 30 S
            emit redLight();
            g_triggerActivated = false;
            return;
        }
    }

    // Handle normal state transitions
    switch (g_currentState) {
    case Red:
        g_currentState = YellowToGreen;
        qDebug() << "Normal: Red to Yellow";
        g_timer.start(2000); // yellow light for 2 S
        emit yellowLight();
        break;
    case YellowToGreen:
        g_currentState = Green;
        qDebug() << "Normal: Yellow to Green";
        g_timer.start(30000); // green light for 30 S
        emit greenLight();
        break;
    case Green:
        g_currentState = YellowToRed;
        qDebug() << "Normal: Green to Yellow";
        g_timer.start(5000); // yellow light for 30 S
        emit yellowLight();
        break;
    case YellowToRed:
        g_currentState = Red;
        qDebug() << "Normal: Yellow to Red";
        g_timer.start(30000); // red light for 30 S
        emit redLight();
        break;
    }
}
