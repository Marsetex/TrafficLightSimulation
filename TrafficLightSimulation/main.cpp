#include "trafficlightview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    TrafficLightView view;
    view.show();

    return app.exec();
}
