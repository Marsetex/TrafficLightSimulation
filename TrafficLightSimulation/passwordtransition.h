#ifndef PASSWORDTRANSITION_H
#define PASSWORDTRANSITION_H

#include "passwordevent.h"

#include <iostream>

#include <QAbstractTransition>
#include <QEvent>

class PasswordTransition : public QAbstractTransition
{
    Q_OBJECT

    public:
        PasswordTransition(const QString& value);

    protected:
        virtual bool eventTest(QEvent* event);
        virtual void onTransition(QEvent* event);

    private:
        QString value;

};

#endif // PASSWORDTRANSITION_H
