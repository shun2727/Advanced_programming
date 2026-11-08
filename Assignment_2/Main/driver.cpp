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
    // constexpr std::size_t SIZE = 20;
    // std::array<Event, SIZE> event_arr;
    // std::size_t event_count = parseEventFile(event_arr);   // N deduced as 20
    // displayEvents(event_arr, event_count);

	/*
		Shown 
	*/
	Event			event;
	Registration 	registration;
	Participant 	participant;

	bool flag = true;
	int	user_input {-1};
	
	//load file
	while (flag)
	{
		displayMenu();

	}
	
}


