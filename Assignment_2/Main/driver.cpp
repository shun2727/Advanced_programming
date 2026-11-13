#include "header.hpp"

int main()
{
    Data_s	data;
	int		userInput;

	/*
		First loads and parses the data and validate the contents in the registration file.
		Upon failure will throw an exception
	*/
    try
    {
        MainData::loadFile("./Event.txt", data.events, data.eventCount, Event{});
        MainData::loadFile("./Participant.txt", data.participants, data.participantCount, Participant{});
        MainData::loadFile("./Registration.txt", data.registrations, data.registrationCount, Registration{});        
        validateRegistrations(data);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << "\n";
        return (1);
    }

	/*
		Self note:
			- usually i'd do while (num != x) then loop
			- but by implementing do while , the int can be initilized within the
			 loop wihout it's condition being checked before entreing the loop
	*/
    do
    {
		/*
			Displays the menu and registers user input
		*/
        displayMenu();
        userInput = parseUserInput();

        try
        {
            switch (userInput)
            {
                case 1:
					MainData::display(data.events, data.eventCount);
					break;
                case 2: 
					MainData::display(data.participants, data.participantCount);
					break;
                case 3:
					MainData::display(data.registrations, data.registrationCount);
					break;
                case 4:
					registerParticipant(data); 
					break;
                case 5: 
					cancelRegistration(data); 
					break;
                case 6: 
					rptTotalEventParticipant(data); 
					break;
                case 7: 
					rptParticipantSummary(data); 
					break;
                case 8: 
					rptEventAmtSum(data); 
					break;
                case 0:
					std::cout << "Exiting menu....\n"; 
					break;
                default: 
					std::cout << "Invalid userInput, enter a number from 0 to 8.\n";
            }
        }
        catch (const std::exception& e)
        {
            std::cout << "Error: " << e.what() << "\n";
        }

    } while (userInput != 0);

    return (0);
}