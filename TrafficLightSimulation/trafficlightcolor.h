#ifndef TRAFFICLIGHTCOLOR_H
#define TRAFFICLIGHTCOLOR_H

#include <QColor>

class TrafficLightColor
{
    public:
        TrafficLightColor(QColor* red, QColor* yellow, QColor* green);
        QColor* getRedColor();
        QColor* getYellowColor();
        QColor* getGreenColor();

    private:
        QColor* red;
        QColor* yellow;
        QColor* green;
};

#endif // TRAFFICLIGHTCOLOR_H
