#include "Event.hpp"

#include <stdexcept>
#include <utility>

Event::Event(std::string eventId,
             std::string eventName,
             std::string eventType,
             double registrationFee)
    : event_id_(std::move(eventId)),
      event_name_(std::move(eventName)),
      event_type_(std::move(eventType)),
      registration_fee_(registrationFee)
{

}

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

void Event::setEventId(std::string event_id)
{
    event_id_ = event_id;
}

void Event::setEventName(std::string event_name)
{
    event_name_ = event_name;
}

void Event::setEventType(std::string event_type)
{
    event_type_ = event_type;
}

void Event::setRegistrationFee(double registration_fee)
{
    if (registration_fee < 0)
    {
        throw std::invalid_argument("Registration fee cannot be negative.");
    }

    registration_fee_ = registration_fee;
}

