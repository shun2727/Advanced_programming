#include "Registration.hpp"

Registration::Registration(const std::string& participant_id, const std::string& event_id)
    : participant_id_{std::move(participant_id)}, event_id_{std::move(event_id)}
{

}

/*
	Accessors
*/
const std::string& Registration::getParticipantId() const
{
    return participant_id_;
}

const std::string& Registration::getEventId() const
{
    return event_id_;
}

/*
	Mutators
*/
void Registration::setParticipantId(const std::string& participant_id)
{
    participant_id_ = std::move(participant_id);
}

void Registration::setEventId(const std::string& event_id)
{
    event_id_ = std::move(event_id);
}

/*
	operational functions
	- although some functions behave similarly with the accessors,
	 due to the fact that its a requirement by the base function because it is an
	  abstract class, functions like getKey() are used through the base class
*/

/**
 * @brief Deconstructs the line by delimiter ; and assigns the values to the registration's fields
 *
 * @param line
 */
void Registration::parseLine(const std::string& line)
{
    std::istringstream stream{line};

    if (!(std::getline(stream, participant_id_, ';') &&
          std::getline(stream, event_id_)))
        throw std::runtime_error{"Invalid registration record: " + line};

    if (participant_id_.empty() || event_id_.empty())
        throw std::runtime_error{"Registration IDs cannot be empty: " + line};
}

/**
 * @brief prints the header for registration
 *
 */
void Registration::printHeader() const
{
    std::cout << std::left
              << std::setw(8) << "Part ID" << " | "
              << std::setw(8) << "Event ID" << "\n"
              << std::string(19, '-') << "\n";
}

/**
 * @brief displays using the overloaded << operator
 *
 */
void Registration::display() const
{
    std::cout << *this << "\n";
}

/**
 * @brief provides the participant and event IDs as the registration's key
 *
 * The key contains both IDs so getIndexFromKey() can reject a repeated pair as a duplicate registration.
 *
 * @return std::string
 */
std::string Registration::getKey() const
{
    return participant_id_ + ";" + event_id_;
}

/**
 * @brief creates a unique pointer based on the object type
 *
 * @return std::unique_ptr<MainData>
 */
std::unique_ptr<MainData> Registration::makeUniquePointer() const
{
    return std::make_unique<Registration>();
}

/**
 * @brief checks whether two registrations have the same participant ID and event ID
 *
 * @param other
 * @return true if both IDs match
 * @return false if either ID does not match
 */
bool Registration::operator==(const Registration& other) const
{
    return participant_id_ == other.participant_id_ && event_id_ == other.event_id_;
}

/**
 * @brief overloads the << operator belonging to the output stream
 *
 * @param os
 * @param r
 * @return std::ostream&
 */
std::ostream& operator<<(std::ostream& os, const Registration& r)
{
	return os << std::left
			<< std::setw(8) << r.participant_id_ << " | "
			<< std::setw(8) << r.event_id_;
}