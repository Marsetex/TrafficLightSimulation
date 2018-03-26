#include "trafficlight.h"

TrafficLight::TrafficLight(QObject* parent) : QObject(parent)
{   
    timer = new QTimer();
    timer->setInterval(2000);
    timer->setSingleShot(true);

    QStateMachine *machine = new QStateMachine(NULL);

    QState* red = new QState();
    QState* redYellow = new QState();
    QState* green = new QState();
    QState* yellow = new QState();

    //s1->assignProperty(timer, "text", "Outside");
    red->addTransition(timer, SIGNAL(timeout()), redYellow);
    connect(red, SIGNAL(entered()), this, SLOT(draw1()));

    //s2->assignProperty(button, "text", "Inside");
    redYellow->addTransition(timer, SIGNAL(timeout()), green);
    connect(redYellow, SIGNAL(entered()), this, SLOT(draw2()));

    //s3->assignProperty(button, "text", "Pressing...");
    green->addTransition(timer, SIGNAL(timeout()), yellow);
    connect(green, SIGNAL(entered()), this, SLOT(draw3()));

    //s3->assignProperty(button, "text", "Pressing...");
    yellow->addTransition(timer, SIGNAL(timeout()), red);
    connect(yellow, SIGNAL(entered()), this, SLOT(draw4()));

    machine->addState(red);
    machine->addState(redYellow);
    machine->addState(yellow);
    machine->addState(green);

    machine->setInitialState(red);
    machine->start();
    timer->start();
}

TrafficLight::~TrafficLight()
{
    delete timer;
}

void TrafficLight::setView(TrafficLightView* view)
{
    this->view = view;
}

void TrafficLight::draw1()
{
    QColor red(255, 0, 0, 255);
    QColor yellow(255, 255, 0, 50);
    QColor green(0, 255, 0, 50);
    view->drawTrafficLights(red, yellow, green);
    timer->start();
}

void TrafficLight::draw2()
{
    QColor red(255, 0, 0, 255);
    QColor yellow(255, 255, 0, 255);
    QColor green(0, 255, 0, 50);
    view->drawTrafficLights(red, yellow, green);
    timer->start();
}

void TrafficLight::draw3()
{
    QColor red(255, 0, 0, 50);
    QColor yellow(255, 255, 0, 50);
    QColor green(0, 255, 0, 255);
    view->drawTrafficLights(red, yellow, green);
    timer->start();
}

void TrafficLight::draw4()
{
    QColor red(255, 0, 0, 50);
    QColor yellow(255, 255, 0, 255);
    QColor green(0, 255, 0, 50);
    view->drawTrafficLights(red, yellow, green);
    timer->start();
}
