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

void Registration::display() const
{
    std::cout << *this << "\n";
}

// the key is BOTH IDs, so findIndex rejects a repeated pair = duplicate registration
std::string Registration::getKey() const
{
    return participant_id_ + ";" + event_id_;
}

std::unique_ptr<MainData> Registration::create() const
{
    return std::make_unique<Registration>();
}

bool Registration::operator==(const Registration& other) const
{
    return participant_id_ == other.participant_id_ && event_id_ == other.event_id_;
}

std::ostream& operator<<(std::ostream& os, const Registration& r)
{
    return os << r.participant_id_ << " | " << r.event_id_;
}