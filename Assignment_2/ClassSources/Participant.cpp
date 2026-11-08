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

/*
	operational functions
*/
void Participant::parseLine(const std::string& line)
{
    std::istringstream stream{line};

    if (!(std::getline(stream, participant_id_, ';') &&
          std::getline(stream, participant_name_)))
        throw std::runtime_error{"Invalid participant record: " + line};

    if (participant_id_.empty() || participant_name_.empty())
        throw std::runtime_error{"Participant ID and name cannot be empty: " + line};
}

void Participant::display() const
{
    std::cout << *this << "\n";
}

std::string Participant::getKey() const
{
    return participant_id_;
}

std::unique_ptr<MainData> Participant::create() const
{
    return std::make_unique<Participant>();
}

std::ostream& operator<<(std::ostream& os, const Participant& p)
{
    return os << p.participant_id_ << " | " << p.participant_name_;
}