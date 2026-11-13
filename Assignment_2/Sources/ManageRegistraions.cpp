#include "header.hpp"

/**
 * @brief Regsiters participant for event for option , saves and removes from file according to teh actions
 * 
 * @param data_struct gets passed the struct
 */
void registerParticipant(Data_s& data_struct)
{
	showParticipants(data_struct);
    std::cout << "\n";
    std::string pid = readId("Participant ID: ");

	showEvents(data_struct);
    std::cout << "\n";
    std::string eid = readId("Event ID: ");

    Participant* p = getParticipant(data_struct, pid);
    if (p == nullptr)
        throw std::runtime_error{"Invalid participant: " + pid};

    Event* e = getEvent(data_struct, eid);
    if (e == nullptr)
        throw std::runtime_error{"Invalid event: " + eid};

    // addRegistraionEntry throws "Duplicate record" if this pair already exists
    MainData::addRegistraionEntry(data_struct.registrations, data_struct.registrationCount, std::make_unique<Registration>(pid, eid));

    std::ofstream registration_file{"./inputFiles/Registration.txt", std::ios::trunc};
    if (!registration_file)
        throw std::runtime_error{"Cannot open file: ./inputFiles/Registration.txt"};

    for (int i = 0; i < data_struct.registrationCount; ++i)
    {
        Registration* reg = static_cast<Registration*>(data_struct.registrations[i].get());
        registration_file << reg->getParticipantId() << ';' << reg->getEventId() << '\n';
    }

    registration_file.flush();

    std::cout << p->getParticipantName() << " registered for " << e->getEventName() << ". Fee payable: RM" << e->getRegistrationFee() << "\n";
}

/**
 * @brief 
 * 
 * @param data_struct 
 */
void cancelRegistration(Data_s& data_struct)
{
	if (data_struct.registrationCount == 0)
    	throw std::runtime_error{"There are no registrations to cancel"};

    showRegistrations(data_struct);
    std::cout << "\n";

    std::string pid = readId("Participant ID: ");
    std::string eid = readId("Event ID: ");

    int i = MainData::getIndexFromKey(data_struct.registrations, data_struct.registrationCount, pid + ";" + eid);
    if (i == -1)
        throw std::runtime_error{"No registration found for " + pid + " in " + eid};

    MainData::removeEntry(data_struct.registrations, data_struct.registrationCount, i);

    std::ofstream registration_file{"./inputFiles/Registration.txt", std::ios::trunc};
    if (!registration_file)
        throw std::runtime_error{"Cannot open file: ./inputFiles/Registration.txt"};

    for (int i = 0; i < data_struct.registrationCount; ++i)
    {
        Registration* reg = static_cast<Registration*>(data_struct.registrations[i].get());
        registration_file << reg->getParticipantId() << ';' << reg->getEventId() << '\n';
    }

    registration_file.flush();

    std::cout << "Registration cancelled.\n";
}

