#include "trafficlightview.h"
#include "trafficlight.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TrafficLightView view;
    view.show();

    TrafficLight trafficLight(NULL);
    trafficLight.setView(&view);

    return app.exec();
}
