#include "trafficlight.h"

TrafficLight::TrafficLight(TrafficLightView* view)
{
    TrafficLightColorFactory* colorFactory = new TrafficLightColorFactory();
    QLabel* label = view->getStateOutputLabel();
    QStateMachine* machine = new QStateMachine();

    TrafficLightColor* redOnColor = colorFactory->getTrafficLightColorStateRed();
    TrafficLightState* redOn = new TrafficLightState(view, redOnColor, 1000);

    TrafficLightColor* redYellowOnColor = colorFactory->getTrafficLightColorStateRedYellow();
    TrafficLightState* redYellowOn = new TrafficLightState(view, redYellowOnColor, 2000);

    TrafficLightColor* greenOnColor = colorFactory->getTrafficLightColorStateGreen();
    TrafficLightState* greenOn = new TrafficLightState(view, greenOnColor, 3000);

    TrafficLightColor* yellowOnColor = colorFactory->getTrafficLightColorStateYellow();
    TrafficLightState* yellowOn = new TrafficLightState(view, yellowOnColor, 1000);

    redOn->assignProperty(label, "text", "Rot");
    redOn->addTransition(redOn, SIGNAL(finished()), redYellowOn);

    redYellowOn->assignProperty(label, "text", "Rot-Gelb");
    redYellowOn->addTransition(redYellowOn, SIGNAL(finished()), greenOn);

    greenOn->assignProperty(label, "text", "Grün");
    greenOn->addTransition(greenOn, SIGNAL(finished()), yellowOn);

    yellowOn->assignProperty(label, "text", "Gelb");
    yellowOn->addTransition(yellowOn, SIGNAL(finished()), redOn);

    machine->addState(redOn);
    machine->addState(redYellowOn);
    machine->addState(yellowOn);
    machine->addState(greenOn);

    machine->setInitialState(redOn);
    machine->start();
}
