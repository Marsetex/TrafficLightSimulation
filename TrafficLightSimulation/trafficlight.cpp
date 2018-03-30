#include "trafficlight.h"

TrafficLight::TrafficLight(TrafficLightView* view, QObject *parent) : QObject(parent)
{
    machine = new QStateMachine();

    QLabel* label = view->getStateOutputLabel();
    QAction* startDebugAction = view->getDebugStartAction();
    QAction* stopDebugAction = view->getDebugStopAction();

    connect(startDebugAction, SIGNAL(triggered(bool)), this, SLOT(startDebugClicked()));

    QState* trafficLightActive = new QState();
    QState* debugModeActive = new QState();
    QHistoryState* trafficLightActiveHistory = new QHistoryState(trafficLightActive);

    configureTrafficLightMachine(trafficLightActive, view);

    PasswordTransition* transition = new PasswordTransition("Hello");
    transition->setTargetState(debugModeActive);
    trafficLightActive->addTransition(transition);
    trafficLightActive->assignProperty(label, "styleSheet", "background-color:rgb(255, 255, 255);");

    debugModeActive->assignProperty(label, "styleSheet", "background-color:rgb(255,0,0);");
    debugModeActive->assignProperty(label, "text", "Debug mode");
    debugModeActive->addTransition(stopDebugAction, SIGNAL(triggered(bool)), trafficLightActiveHistory);

    machine->addState(trafficLightActive);
    machine->addState(debugModeActive);
    machine->addDefaultAnimation(new QPropertyAnimation(label, "styleSheet"));

    machine->setInitialState(trafficLightActive);
    machine->start();
}

void TrafficLight::configureTrafficLightMachine(QState* trafficLightActive, TrafficLightView* view)
{
    TrafficLightColorFactory* colorFactory = new TrafficLightColorFactory();
    QLabel* label = view->getStateOutputLabel();

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
}

void TrafficLight::startDebugClicked()
{
    bool okClicked;
    QString text = QInputDialog::getText(NULL, tr("Enter the password for debug mode"), tr("Password:"), QLineEdit::Normal, "", &okClicked);

    if (okClicked && !text.isEmpty()) {
        machine->postEvent(new PasswordEvent(text));
    }
}
