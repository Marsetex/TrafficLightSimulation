#include "passwordtransition.h"

PasswordTransition::PasswordTransition(const QString& value)
{
    this->value = value;
}

bool PasswordTransition::eventTest(QEvent* event)
{
    if (event->type() != QEvent::Type(QEvent::User+1)) {
        return false;
    }

    PasswordEvent* pe = static_cast<PasswordEvent*>(event);
    return (value == pe->value);
}

void PasswordTransition::onTransition(QEvent* event)
{
    std::cout << "Entering debug mode \n";
}
