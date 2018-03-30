#include "trafficlightstate.h"

#include <iostream>

TrafficLightState::TrafficLightState(TrafficLightView* view, TrafficLightColor* color, int durationInMs, QState* parent) : QState(parent)
{
    this->view = view;
    this->color = color;

    timer = new QTimer();
    timer->setInterval(durationInMs);
    timer->setSingleShot(true);

    QState* innerTimer = new QState(this);
    QFinalState* innerTimerDone = new QFinalState(this);

    this->setInitialState(innerTimer);
    innerTimer->addTransition(timer, SIGNAL(timeout()), innerTimerDone);
    connect(innerTimer, SIGNAL(entered()), timer, SLOT(start()));
}

TrafficLightState::~TrafficLightState()
{
    delete timer;
}

void TrafficLightState::onEntry(QEvent* event)
{
    view->drawTrafficLights(color);
}
