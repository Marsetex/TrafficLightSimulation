#ifndef TRAFFICLIGHTVIEW_H
#define TRAFFICLIGHTVIEW_H

#include <iostream>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>

namespace Ui {
    class TrafficLightView;
}

class TrafficLightView : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrafficLightView(QWidget *parent = 0);
        ~TrafficLightView();
        void drawTrafficLights(QColor redLight, QColor yellowLight, QColor greenLight);

    private:
        Ui::TrafficLightView* ui;
        QGraphicsScene* scene;
};

#endif // TRAFFICLIGHTVIEW_H
