#include "trafficlightview.h"
#include "ui_trafficlightview.h"

TrafficLightView::TrafficLightView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrafficLightView)
{
    ui->setupUi(this);
}

TrafficLightView::~TrafficLightView()
{
    delete ui;
}
