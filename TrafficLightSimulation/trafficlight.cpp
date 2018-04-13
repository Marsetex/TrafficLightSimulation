#include "trafficlight.h"

TrafficLight::TrafficLight(TrafficLightView* view, QObject* parent) : QObject(parent)
{
    setUpStateMachine(view);
}

void TrafficLight::setUpStateMachine(TrafficLightView* view)
{
    QLabel* label = view->getStateOutputLabel();
    QAction* startDebugAction = view->getDebugStartAction();
    QAction* stopDebugAction = view->getDebugStopAction();

    // Erzeugung des Zustandsautomaten
    machine = new QStateMachine();

    // Erzeugung des Zustaende
    QState* trafficLightActive = new QState();
    QState* debugModeActive = new QState();
    QHistoryState* trafficLightActiveHistory = new QHistoryState(trafficLightActive);
    configureTrafficLightMachine(trafficLightActive, view);

    // Konfiguration der State Machine
    machine->addState(trafficLightActive);
    machine->addState(debugModeActive);
    machine->addDefaultAnimation(new QPropertyAnimation(label, "styleSheet"));
    machine->setInitialState(trafficLightActive);
    machine->start();

    // Konfiguration des Uebergangs zu DebugMode
    connect(startDebugAction, SIGNAL(triggered(bool)), this, SLOT(startDebugClicked()));

    PasswordTransition* transition = new PasswordTransition("secret");
    transition->setTargetState(debugModeActive);
    trafficLightActive->addTransition(transition);
    trafficLightActive->assignProperty(label, "styleSheet", "background-color:rgb(255, 255, 255);");

    // Konfiguration des Uebergangs zu TrafficLightSimMode
    debugModeActive->assignProperty(label, "styleSheet", "background-color:rgb(255,0,0);");
    debugModeActive->assignProperty(label, "text", "Debug Mode");
    debugModeActive->addTransition(stopDebugAction, SIGNAL(triggered(bool)), trafficLightActiveHistory);
}

void TrafficLight::configureTrafficLightMachine(QState* trafficLightActive, TrafficLightView* view)
{
    TrafficLightColorFactory* colorFactory = new TrafficLightColorFactory();
    QLabel* label = view->getStateOutputLabel();

    TrafficLightColor* redOnColor = colorFactory->getTrafficLightColorStateRed();
    TrafficLightState* redOn = new TrafficLightState(view, redOnColor, 5000, trafficLightActive);

    TrafficLightColor* redYellowOnColor = colorFactory->getTrafficLightColorStateRedYellow();
    TrafficLightState* redYellowOn = new TrafficLightState(view, redYellowOnColor, 2000, trafficLightActive);

    TrafficLightColor* greenOnColor = colorFactory->getTrafficLightColorStateGreen();
    TrafficLightState* greenOn = new TrafficLightState(view, greenOnColor, 7000, trafficLightActive);

    TrafficLightColor* yellowOnColor = colorFactory->getTrafficLightColorStateYellow();
    TrafficLightState* yellowOn = new TrafficLightState(view, yellowOnColor, 4000, trafficLightActive);

    redOn->assignProperty(label, "text", "Stop The Engine");
    redOn->addTransition(redOn, SIGNAL(finished()), redYellowOn);

    redYellowOn->assignProperty(label, "text", "Get Ready");
    redYellowOn->addTransition(redYellowOn, SIGNAL(finished()), greenOn);

    greenOn->assignProperty(label, "text", "Go Go Go");
    greenOn->addTransition(greenOn, SIGNAL(finished()), yellowOn);

    yellowOn->assignProperty(label, "text", "Hit The Brakes");
    yellowOn->addTransition(yellowOn, SIGNAL(finished()), redOn);

    trafficLightActive->setInitialState(redOn);
}

void TrafficLight::startDebugClicked()
{
    bool okClicked;
    QString text = QInputDialog::getText(NULL, tr("Enter the password for debug mode"), tr("Password:"), QLineEdit::Password, "", &okClicked);

    if (okClicked && !text.isEmpty()) {
        machine->postEvent(new PasswordEvent(text));
    }
}
