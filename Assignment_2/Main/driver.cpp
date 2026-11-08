#include "header.hpp"

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
			<< "Enter choice a number corresponding to your choice\n"
			<<  "Number : ";
}
int main()
{
    std::unique_ptr<MainData> events[MainData::MAX_SIZE];
    int eventCount = 0;

    try
    {
        MainData::loadFile("./inputFiles/Event.txt", events, eventCount, Event{});
        std::cout << "Loaded " << eventCount << " events\n\n";
        MainData::display(events, eventCount);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}


