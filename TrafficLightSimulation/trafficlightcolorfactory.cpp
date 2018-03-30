#include "trafficlightcolorfactory.h"

TrafficLightColorFactory::TrafficLightColorFactory()
{
    redOn = new QColor(255, 0, 0, 255);
    redOff = new QColor(255, 0, 0, 50);
    greenOn = new QColor(0, 255, 0, 255);
    greenOff = new QColor(0, 255, 0, 50);
    yellowOn = new QColor(255, 255, 0, 255);
    yellowOff = new QColor(255, 255, 0, 50);
}

TrafficLightColor* TrafficLightColorFactory::getTrafficLightColorStateRed()
{
    return new TrafficLightColor(redOn, yellowOff, greenOff);
}

TrafficLightColor* TrafficLightColorFactory::getTrafficLightColorStateRedYellow()
{
    return new TrafficLightColor(redOn, yellowOn, greenOff);
}

TrafficLightColor* TrafficLightColorFactory::getTrafficLightColorStateGreen()
{
    TrafficLightColor* color = new TrafficLightColor(redOff, yellowOff, greenOn);
    return color;
}

TrafficLightColor* TrafficLightColorFactory::getTrafficLightColorStateYellow()
{
    return new TrafficLightColor(redOff, yellowOn, greenOff);
}
