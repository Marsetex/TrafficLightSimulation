#ifndef TRAFFICLIGHTVIEW_H
#define TRAFFICLIGHTVIEW_H

#include <QMainWindow>

namespace Ui {
class TrafficLightView;
}

class TrafficLightView : public QMainWindow
{
    Q_OBJECT

public:
    explicit TrafficLightView(QWidget *parent = 0);
    ~TrafficLightView();

private:
    Ui::TrafficLightView *ui;
};

#endif // TRAFFICLIGHTVIEW_H
