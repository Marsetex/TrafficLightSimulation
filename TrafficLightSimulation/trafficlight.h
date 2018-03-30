#ifndef TrafficLight_H
#define TrafficLight_H

#include "trafficlightview.h"
#include "trafficlightstate.h"
#include "trafficlightcolor.h"
#include "trafficlightcolorfactory.h"

#include <QStateMachine>
#include <QLabel>

class TrafficLight
{
    public:
        TrafficLight(TrafficLightView* view);

};

#endif // TrafficLight_H
