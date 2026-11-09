#include "Participant.hpp"

/*
	Constructor Initializer List
	Self note:
		- intial lernings suggested to use var_(var)
		- However that only makes a copy of the value
		- var{std::move(var)} , moves the actual resrouces
*/
Participant::Participant(std::string participant_id, std::string participant_name) 
	: participant_id_(std::move(participant_id)), participant_name_(std::move(participant_name))
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
	- alhtough some functions behave similarly with the accessors,
	 due to the fact that its a rewquirement by the base funciton due to it being an
	  abstract class and participant is a virtual class, funciton like getKey() is
	    used based on the base class
*/

/**
 * @brief Deconstructs the line by delimeter ; and assign the values to the participant's field
 * 
 * @param line 
 */
void Participant::parseLine(const std::string& line)
{
    std::istringstream stream{line};

    if (!(std::getline(stream, participant_id_, ';') && std::getline(stream, participant_name_)))
        throw std::runtime_error{"Invalid participant record: " + line};

    if (participant_id_.empty() || participant_name_.empty())
        throw std::runtime_error{"Participant ID and name cannot be empty: " + line};
}


/**
 * @brief provdes the participant_id_
 * 
 * @return std::string 
 */
std::string Participant::getKey() const
{
    return participant_id_;
}

/**
 * @brief creates a unqiue pointer based on the object type
 * 
 * @return std::unique_ptr<MainData> 
 */
std::unique_ptr<MainData> Participant::makeUniquePointer() const
{
    return std::make_unique<Participant>();
}

/**
 * @brief displayes using the overloaded << operator
 * 
 */
void Participant::display() const
{
    std::cout << *this << "\n";
}

/**
 * @brief overload the << operator belonging to the output stream
 * 
 * @param os 
 * @param e 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, const Participant& p)
{
	return os << std::left
			<< std::setw(8)  << p.participant_id_ << " | "
			<< std::setw(30) << p.participant_name_;
}

/**
 * @brief prints the header for participant
 * 
 */
void Participant::printHeader() const
{
    std::cout << std::left
              << std::setw(8)  << "ID" << " | "
              << std::setw(30) << "Name" << "\n"
              << std::string(41, '-') << "\n";
}