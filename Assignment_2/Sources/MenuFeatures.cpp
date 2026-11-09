#include "header.hpp"

/**
 * @brief Displays menu
 * 
 */
void displayMenu()
{
    std::cout << "\n---------------- MAIN MENU ----------------\n"
              << " 1. Display all events\n"
              << " 2. Display all participants\n"
              << " 3. Display all registrations\n"
              << " 4. Register participant for an event\n"
              << " 5. Cancel registration\n"
              << " 6. Generate report: participants for an event\n"
              << " 7. Generate report: registration summary for a participant\n"
              << " 8. Generate report: registrations & fees per event\n"
              << " 0. Exit\n"
              << "-------------------------------------------\n"
              << "Enter a number corresponding to the menu options \n"
              << "Number : ";
}

/**
 * @brief Calls gets line and reads and evaluate the user's input
 * 
 * @return int 
 */
int parseUserInput()
{
    std::string line;

	// if cin is used, it will only read until the space
    if (!std::getline(std::cin, line))     
        return 0;

    try
    {
        return std::stoi(line);
    }
    catch (const std::exception&)
    {
        return -1;
    }
}

/**
 * @brief returns the user's input , mostly used for report generation
 * 
 * @param prompt 
 * @return std::string 
 */
std::string readId(const std::string& prompt)
{
    std::string id;

    std::cout << prompt;
    std::getline(std::cin, id);

    for (char& c : id)
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));

    return (id);
}


void showEvents(Data_s& data_struct)
{
    std::cout << "--- Events ---\n";
    MainData::display(data_struct.events, data_struct.eventCount);
}

void showParticipants(Data_s& data_struct)
{
    std::cout << "--- Participants ---\n";
    MainData::display(data_struct.participants, data_struct.participantCount);
}

/**
 * @brief Displays registrations with the participant and event names beside their IDs
 *
 * Note :
 * Registration only stores the two IDs, so the names are looked up from the other two arrays.
 */
void showRegistrations(Data_s& data_struct)
{
    std::cout << "--- Registrations ---\n";

    if (data_struct.registrationCount == 0)
    {
        std::cout << "record is empty \n";
        return;
    }

    std::cout << std::left
              << std::setw(8)  << "Part ID"          << " | "
              << std::setw(30) << "Participant Name" << " | "
              << std::setw(8)  << "Event ID"         << " | "
              << std::setw(30) << "Event Name"       << "\n"
              << std::string(85, '-') << "\n";

    for (int i = 0; i < data_struct.registrationCount; ++i)
    {
        Registration* r = registrationAt(data_struct, i);
        Participant*  p = getParticipant(data_struct, r->getParticipantId());
        Event*        e = getEvent(data_struct, r->getEventId());

        std::cout << std::setw(8)  << p->getParticipantId()   << " | "
                  << std::setw(30) << p->getParticipantName() << " | "
                  << std::setw(8)  << e->getEventId()         << " | "
                  << std::setw(30) << e->getEventName()       << "\n";
    }
}