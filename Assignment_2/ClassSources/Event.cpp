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
/*
	operational fucntions
*/
void Event::parseLine(const std::string& line)
{
    std::istringstream 	stream{line};
    std::string 		fee_text;
	std::size_t 		pos{};

    if (!(std::getline(stream, event_id_, ';') &&
          std::getline(stream, event_name_, ';') &&
          std::getline(stream, event_type_, ';') &&
          std::getline(stream, fee_text)))
        throw std::runtime_error{"Invalid event record: " + line};

    try
    {
        registration_fee_ = std::stod(fee_text, &pos);
    }
    catch (const std::exception&)
    {
        throw std::runtime_error{"Invalid registration fee: " + fee_text};
    }

    if (pos != fee_text.size() || registration_fee_ < 0)
        throw std::runtime_error{"Invalid registration fee: " + fee_text};
}

void Event::display() const
{
    std::cout << *this << "\n";          // uses the friend operator<< below
}

std::string Event::getKey() const
{
    return event_id_;                    // what findIndex and duplicate checks compare
}

std::unique_ptr<MainData> Event::create() const
{
    return std::make_unique<Event>();    // a blank Event for loadFile to fill
}

double Event::operator+(const Event& other) const
{
    return registration_fee_ + other.registration_fee_;
}

double operator+(double total, const Event& e)
{
    return total + e.registration_fee_;  // friend: reads the private fee directly
}

std::ostream& operator<<(std::ostream& os, const Event& e)
{
    return os << e.event_id_ << " | " << e.event_name_ << " | " << e.event_type_ << " | RM" << e.registration_fee_;
}
