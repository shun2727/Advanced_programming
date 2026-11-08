#include "Participant.hpp"

/*
	Constructor Initializer List
	Self note:
		- intial lernings suggested to use var_(var)
		- However that only makes a copy of the value
		- var{std::move(var)} , moves the actual resrouces
*/
Participant::Participant(std::string participant_id, std::string participant_name)
    : participant_id_(std::move(participant_id)), 
      participant_name_(std::move(participant_name))
{

}

/*
	Accessors, dont need to repeat [[nodiscard]] here
*/
const std::string& Participant::getParticipantId() const 
{
    return participant_id_;
}

const std::string& Participant::getParticipantName() const 
{
    return participant_name_;
}

/*
	Mutators
*/
void Participant::setParticipantId(std::string participant_id) 
{
    participant_id_ = std::move(participant_id); 
}

void Participant::setParticipantName(std::string participant_name) 
{
    participant_name_ = std::move(participant_name); 
}