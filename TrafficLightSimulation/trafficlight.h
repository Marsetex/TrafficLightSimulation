#ifndef TrafficLight_H
#define TrafficLight_H

#include "trafficlightview.h"

#include <iostream>

#include <QTimer>
#include <QState>
#include <QStateMachine>

class TrafficLight : QObject
{
    Q_OBJECT

    public:
        explicit TrafficLight(QObject* parent = nullptr);
        ~TrafficLight();
        void setView(TrafficLightView* view);

    private:
        TrafficLightView* view;
        QTimer* timer;

    public slots:
        void draw1();
        void draw2();
        void draw3();
        void draw4();

};

#endif // TrafficLight_H
