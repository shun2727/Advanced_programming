#include "Event.hpp"

Event::Event(std::string eventId, std::string eventName, std::string eventType, double registrationFee)
    : event_id_(std::move(eventId)),
      event_name_(std::move(eventName)),
      event_type_(std::move(eventType)),
      registration_fee_(registrationFee)
{

}
/*
	Accessors
*/
const std::string& Event::getEventId() const
{
    return event_id_;
}

const std::string& Event::getEventName() const
{
    return event_name_;
}

const std::string& Event::getEventType() const
{
    return event_type_;
}

double Event::getRegistrationFee() const
{
    return registration_fee_;
}

/*
	Mutators, use std::move here
*/
void Event::setEventId(std::string event_id)
{
    if (event_id.empty())
    {
        throw std::invalid_argument("Event ID cannot be empty.");
    }

    event_id_ = std::move(event_id);
}

void Event::setEventName(std::string event_name)
{
    if (event_name.empty())
    {
        throw std::invalid_argument("Event name cannot be empty.");
    }

    event_name_ = std::move(event_name);
}

void Event::setEventType(std::string event_type)
{
    if (event_type.empty())
    {
        throw std::invalid_argument("Event type cannot be empty.");
    }

    event_type_ = std::move(event_type);
}

void Event::setRegistrationFee(double registration_fee)
{
    if (registration_fee < 0)
    {
        throw std::invalid_argument("Registration fee cannot be negative.");
    }

    registration_fee_ = registration_fee;   // double: nothing to move
}

