#ifndef TrafficLight_H
#define TrafficLight_H

#include "trafficlightview.h"
#include "trafficlightstate.h"
#include "trafficlightcolor.h"
#include "trafficlightcolorfactory.h"

#include <QStateMachine>
#include <QState>
#include <QHistoryState>
#include <QLabel>
#include <QAction>

class TrafficLight
{
    public:
        TrafficLight(TrafficLightView* view);

};

#endif // TrafficLight_H
