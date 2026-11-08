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