#include "trafficlightview.h"
#include "ui_trafficlightview.h"

TrafficLightView::TrafficLightView(QWidget* parent) :
    QMainWindow(parent),
    ui(new Ui::TrafficLightView)
{
    ui->setupUi(this);

    ui->menuItemExit->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E));
    ui->menuItemAbout->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A));

    connect(ui->menuItemAbout, SIGNAL(triggered(bool)), this, SLOT(showAboutDialog()));
    connect(ui->menuItemExit, SIGNAL(triggered(bool)), this, SLOT(stopApplication()));

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    TrafficLightColorFactory* factory = new TrafficLightColorFactory();
    TrafficLightColor* color = factory->getTrafficLightColorStateRed();
    drawTrafficLights(color);
}

TrafficLightView::~TrafficLightView()
{
    delete ui;
}

QLabel* TrafficLightView::getStateOutputLabel() {
    return ui->stateOutputLabel;
}

QAction* TrafficLightView::getDebugStartAction() {
    return ui->menuItemStartDebug;
}

void TrafficLightView::drawTrafficLights(TrafficLightColor* color)
{
    QBrush redBrush(*(color->getRedColor()), Qt::SolidPattern);
    QBrush yellowBrush(*(color->getYellowColor()), Qt::SolidPattern);
    QBrush greenBrush(*(color->getGreenColor()), Qt::SolidPattern);
    QPen pen(Qt::black);

    scene->clear();
    scene->addEllipse(40, 25, 150, 150, pen, redBrush);
    scene->addEllipse(40, 200, 150, 150, pen, yellowBrush);
    scene->addEllipse(40, 375, 150, 150, pen, greenBrush);
}

void TrafficLightView::showAboutDialog()
{
    QMessageBox::information(this,
                             tr("Traffic Light Simulation"),
                             tr("This application was developed by Marcel Gruessinger."));
}

void TrafficLightView::stopApplication()
{
    QApplication::quit();
}
