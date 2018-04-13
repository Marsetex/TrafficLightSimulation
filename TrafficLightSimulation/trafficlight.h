#ifndef TrafficLight_H
#define TrafficLight_H

#include "trafficlightview.h"
#include "trafficlightstate.h"
#include "trafficlightcolor.h"
#include "trafficlightcolorfactory.h"
#include "passwordevent.h"
#include "passwordtransition.h"

#include <QStateMachine>
#include <QState>
#include <QHistoryState>

#include <QPropertyAnimation>
#include <QLabel>
#include <QAction>
#include <QInputDialog>
#include <QLineEdit>

class TrafficLight : public QObject
{
    Q_OBJECT

    public:
        explicit TrafficLight(TrafficLightView* view, QObject* parent = nullptr);

    private:
        void setUpStateMachine(TrafficLightView* view);
        void configureTrafficLightMachine(QState* trafficLightActive, TrafficLightView* view);
        QStateMachine* machine;

    private slots:
        void startDebugClicked();

};

#endif // TrafficLight_H
