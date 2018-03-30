#include "trafficlight.h"

#include <QPropertyAnimation>

TrafficLight::TrafficLight(TrafficLightView* view)
{
    TrafficLightColorFactory* colorFactory = new TrafficLightColorFactory();
    QLabel* label = view->getStateOutputLabel();
    QAction* startDebugAction = view->getDebugStartAction();

    QStateMachine* machine = new QStateMachine();

    QState* trafficLightActive = new QState();
    QState* debugModeActive = new QState();

    QHistoryState* trafficLightActiveHistory = new QHistoryState(trafficLightActive);

    TrafficLightColor* redOnColor = colorFactory->getTrafficLightColorStateRed();
    TrafficLightState* redOn = new TrafficLightState(view, redOnColor, 1000, trafficLightActive);

    TrafficLightColor* redYellowOnColor = colorFactory->getTrafficLightColorStateRedYellow();
    TrafficLightState* redYellowOn = new TrafficLightState(view, redYellowOnColor, 2000, trafficLightActive);

    TrafficLightColor* greenOnColor = colorFactory->getTrafficLightColorStateGreen();
    TrafficLightState* greenOn = new TrafficLightState(view, greenOnColor, 3000, trafficLightActive);

    TrafficLightColor* yellowOnColor = colorFactory->getTrafficLightColorStateYellow();
    TrafficLightState* yellowOn = new TrafficLightState(view, yellowOnColor, 1000, trafficLightActive);

    redOn->assignProperty(label, "text", "Rot");
    redOn->addTransition(redOn, SIGNAL(finished()), redYellowOn);

    redYellowOn->assignProperty(label, "text", "Rot-Gelb");
    redYellowOn->addTransition(redYellowOn, SIGNAL(finished()), greenOn);

    greenOn->assignProperty(label, "text", "Grün");
    greenOn->addTransition(greenOn, SIGNAL(finished()), yellowOn);

    yellowOn->assignProperty(label, "text", "Gelb");
    yellowOn->addTransition(yellowOn, SIGNAL(finished()), redOn);

    trafficLightActive->setInitialState(redOn);

    trafficLightActive->assignProperty(label, "styleSheet", "background-color:rgb(255, 255, 255);");
    trafficLightActive->addTransition(startDebugAction, SIGNAL(triggered(bool)), debugModeActive);

    debugModeActive->assignProperty(label, "styleSheet", "background-color:rgb(255,0,0);");
    debugModeActive->assignProperty(label, "text", "Debug mode");
    debugModeActive->addTransition(startDebugAction, SIGNAL(triggered(bool)), trafficLightActiveHistory);

    machine->addState(trafficLightActive);
    machine->addState(debugModeActive);
    machine->addDefaultAnimation(new QPropertyAnimation(label, "styleSheet"));

    machine->setInitialState(trafficLightActive);
    machine->start();
}
