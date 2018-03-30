#ifndef TRAFFICLIGHTVIEW_H
#define TRAFFICLIGHTVIEW_H

#include "trafficlightcolorfactory.h"
#include "trafficlightcolor.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMessageBox>
#include <QAction>
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
        QLabel* getStateOutputLabel();
        QAction* getDebugStartAction();
        QAction* getDebugStopAction();
        void drawTrafficLights(TrafficLightColor* color);

    private:
        Ui::TrafficLightView* ui;
        QGraphicsScene* scene;

    private slots:
        void showAboutDialog();
        void stopApplication();

};

#endif // TRAFFICLIGHTVIEW_H
