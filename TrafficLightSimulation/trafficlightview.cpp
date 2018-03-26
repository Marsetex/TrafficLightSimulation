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

    QColor red(255, 0, 0);
    QColor yellow(255, 255, 0);
    QColor green(0, 255, 0);
    drawTrafficLights(red, yellow, green);
}

TrafficLightView::~TrafficLightView()
{
    delete ui;
}

void TrafficLightView::drawTrafficLights(QColor redLight, QColor yellowLight, QColor greenLight)
{
    QBrush redBrush(redLight, Qt::SolidPattern);
    QBrush yellowBrush(yellowLight, Qt::SolidPattern);
    QBrush greenBrush(greenLight, Qt::SolidPattern);
    QPen pen(Qt::black);

    scene->clear();
    scene->addEllipse(40, 25, 150, 150, pen, redBrush);
    scene->addEllipse(40, 200, 150, 150, pen, yellowBrush);
    scene->addEllipse(40, 375, 150, 150, pen, greenBrush);

    std::cout << "Re-drawn traffic lights\n";
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
