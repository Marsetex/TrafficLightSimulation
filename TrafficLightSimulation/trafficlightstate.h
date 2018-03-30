#ifndef TRAFFICLIGHTSTATE_H
#define TRAFFICLIGHTSTATE_H

#include "trafficlightview.h"
#include "trafficlightcolor.h"

#include <QTimer>
#include <QState>
#include <QFinalState>
#include <QLabel>

class TrafficLightState : public QState
{
    public:
        explicit TrafficLightState(TrafficLightView* view, TrafficLightColor* color, int durationInMs, QState* parent = 0);
        ~TrafficLightState();

    protected:
        virtual void onEntry(QEvent* event);

    private:
        QTimer* timer;
        TrafficLightView* view;
        TrafficLightColor* color;

    public slots:
        void drawTrafficLights();

};

#endif // TRAFFICLIGHTSTATE_H
