#include "header.hpp"

/**
 * @brief Regsiters participant for event for option 4
 * 
 * @param data_struct gets passed the struct
 */
void registerParticipant(Data_s& data_struct)
{
    std::string pid = readId("Participant ID: ");
    std::string eid = readId("Event ID: ");

    Participant* p = getParticipant(data_struct, pid);
    if (p == nullptr)
        throw std::runtime_error{"Unknown participant: " + pid};

    Event* e = getEvent(data_struct, eid);
    if (e == nullptr)
        throw std::runtime_error{"Unknown event: " + eid};

    // addArrEntry throws "Duplicate record" if this pair already exists
    MainData::addArrEntry(data_struct.registrations, data_struct.registrationCount, std::make_unique<Registration>(pid, eid));

    std::cout << p->getParticipantName() << " registered for " << e->getEventName() << ". Fee payable: RM" << e->getRegistrationFee() << "\n";
}

/**
 * @brief 
 * 
 * @param data_struct 
 */
void cancelRegistration(Data_s& data_struct)
{
    std::string pid = readId("Participant ID: ");
    std::string eid = readId("Event ID: ");

    int i = MainData::getIndexFromKey(data_struct.registrations, data_struct.registrationCount, pid + ";" + eid);
    if (i == -1)
        throw std::runtime_error{"No registration found for " + pid + " in " + eid};

    MainData::removeEntry(data_struct.registrations, data_struct.registrationCount, i);
    std::cout << "Registration cancelled.\n";
}

