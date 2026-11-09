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
              << " 6. Report: participants for an event\n"
              << " 7. Report: registration summary for a participant\n"
              << " 8. Report: registrations & fees per event\n"
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