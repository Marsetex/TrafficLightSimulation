#include "trafficlightcolor.h"

TrafficLightColor::TrafficLightColor(QColor* red, QColor* yellow, QColor* green)
{
    this->red = red;
    this->yellow = yellow;
    this->green = green;
}

QColor* TrafficLightColor::getRedColor()
{
    return red;
}

QColor* TrafficLightColor::getYellowColor()
{
    return yellow;
}

QColor* TrafficLightColor::getGreenColor()
{
    return green;
}
