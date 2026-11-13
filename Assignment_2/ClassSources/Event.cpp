#include "Event.hpp"

Event::Event(std::string eventId, std::string eventName, std::string eventType, double registrationFee)
    : event_id_(std::move(eventId)), event_name_(std::move(eventName)), event_type_(std::move(eventType)), registration_fee_(registrationFee)
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
    event_id_ = std::move(event_id);
}

void Event::setEventName(std::string event_name)
{
    event_name_ = std::move(event_name);
}

void Event::setEventType(std::string event_type)
{
    event_type_ = std::move(event_type);
}

void Event::setRegistrationFee(double registration_fee)
{
    registration_fee_ = registration_fee;   // double: nothing to move
}
/*
	operational fucntions
	- although some functions behave similarly with the accessors,
	 due to the fact that its a requirement by the base funciton due to it being an
	  abstract class and participant is a virtual class, funciton like getKey() is
	    used based on the base class
*/

/**
 * @brief creates a unqiue pointer based on the object type
 * 
 * @return std::unique_ptr<MainData> 
 */
std::unique_ptr<MainData> Event::makeUniquePointer() const
{
    return std::make_unique<Event>();
}

/**
 * @brief Deconstructs the line by delimeter ; and assign the values to the event's feild
 * 
 * @param line 
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
        throw std::runtime_error{"Invalid registration fee"};
    }

    if (pos != fee_text.size() || registration_fee_ < 0)
        throw std::runtime_error{"Invalid registration fee"};
}

/**
 * @brief returns the event_id based on the event object
 * 
 * @return std::string 
 */
std::string Event::getKey() const
{
	return event_id_;
}

/**
 * @brief overloaded + operator to calculate registration fee just by passing event object
 * 
 * @param other 
 * @return double 
 */
double Event::operator+(const Event& other) const
{
	return registration_fee_ + other.registration_fee_;
}

/**
 * @brief overloaded + operator to calculate total registration fee just by passing event object
 * 
 * @param total 
 * @param e 
 * @return double 
 */
double operator+(double total, const Event& e)
{
	return total + e.registration_fee_;
}

/**
 * @brief displayes using the overloaded << operator
 * 
 */
void Event::display() const
{
	std::cout << *this << "\n";
}

/**
 * @brief prints the header for event file
 * 
 */
void Event::printHeader() const
{
	std::cout << std::left
			<< std::setw(8)  << "ID"         << " | "
			<< std::setw(30) << "Event Name" << " | "
			<< std::setw(14) << "Type"       << " | "
			<< std::setw(10) << "Fee (RM)"   << "\n"
			<< std::string(71, '-') << "\n";
}

/**
 * @brief overload the << operator belonging to the output stream
 * 
 * @param os 
 * @param e 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Event& e)
{
	return os << std::left
			<< std::setw(8)  << e.event_id_   << " | "
			<< std::setw(30) << e.event_name_ << " | "
			<< std::setw(14) << e.event_type_ << " | "
			<< std::setw(10) << e.registration_fee_;
}
