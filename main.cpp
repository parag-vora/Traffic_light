#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "trafficlightcontroller.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    TrafficLightController trafficLightController;
    engine.rootContext()->setContextProperty("trafficLightController", &trafficLightController);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Traffic_light", "Main");

    trafficLightController.startSequence(); // Start the traffic light

    return app.exec();
}
