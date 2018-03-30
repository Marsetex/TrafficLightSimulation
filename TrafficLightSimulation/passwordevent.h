#ifndef PASSWORDEVENT_H
#define PASSWORDEVENT_H

#include <QEvent>
#include <QString>

class PasswordEvent : public QEvent
{
    public:
        PasswordEvent(const QString& value) : QEvent(QEvent::Type(QEvent::User+1))
        {
            this->value = value;
        }
        QString value;

};

#endif // PASSWORDEVENT_H
