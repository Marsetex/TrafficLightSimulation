#include "trafficlightview.h"
#include "ui_trafficlightview.h"

TrafficLightView::TrafficLightView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrafficLightView)
{
    ui->setupUi(this);

    QGraphicsScene* scene2 = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene2);

    QBrush redBrush(Qt::SolidPattern);
    redBrush.setColor(Qt::red);

    QBrush yellowBrush(Qt::SolidPattern);
    yellowBrush.setColor(Qt::yellow);

    QBrush greenBrush(Qt::SolidPattern);
    greenBrush.setColor(Qt::green);

    QPen pen(Qt::black);
    pen.setWidth(1);

    scene2->addEllipse(40, 25, 150, 150, pen, redBrush);
    scene2->addEllipse(40, 200, 150, 150, pen, yellowBrush);
    scene2->addEllipse(40, 375, 150, 150, pen, greenBrush);
}

TrafficLightView::~TrafficLightView()
{
    delete ui;
}
