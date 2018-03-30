#ifndef TRAFFICLIGHTCOLORFACTORY_H
#define TRAFFICLIGHTCOLORFACTORY_H

#include "trafficlightcolor.h"
#include <QColor>

class TrafficLightColorFactory
{
    public:
        TrafficLightColorFactory();
        TrafficLightColor* getTrafficLightColorStateRed();
        TrafficLightColor* getTrafficLightColorStateRedYellow();
        TrafficLightColor* getTrafficLightColorStateGreen();
        TrafficLightColor* getTrafficLightColorStateYellow();

    private:
        QColor* redOn;
        QColor* redOff;
        QColor* greenOn;
        QColor* greenOff;
        QColor* yellowOn;
        QColor* yellowOff;

};

#endif // TRAFFICLIGHTCOLORFACTORY_H
