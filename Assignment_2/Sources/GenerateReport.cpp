#include "header.hpp"

/**
 * @brief returns the total amount of participants in an event
 * 
 * @param data_struct 
 */
void rptTotalEventParticipant(Data_s& data_struct)
{
    int found{0};
	std::string eid = readId("Event ID: ");

    Event* e = getEvent(data_struct, eid);

    if (e == nullptr)
        throw std::runtime_error{"Unknown event: " + eid};

    std::cout << "\nParticipants registered for " << e->getEventName() << "\n"
              << std::left << std::setw(8) << "ID" << "Name\n"
              << std::string(40, '-') << "\n";

    for (int i = 0; i < data_struct.registrationCount; ++i)
    {
        Registration* r = registrationAt(data_struct, i);

        if (r->getEventId() == eid)
        {
            Participant* p = getParticipant(data_struct, r->getParticipantId());
            std::cout << std::setw(8) << p->getParticipantId() << p->getParticipantName() << "\n";
            ++found;
        }
    }

    std::cout << "Total: " << found << "\n";
}

/**
 * @brief 
 * 
 * @param data_struct 
 */
void rptParticipantSummary(Data_s& data_struct)
{
    std::string pid = readId("Participant ID: ");

    Participant* p = getParticipant(data_struct, pid);
    if (p == nullptr)
        throw std::runtime_error{"Unknown participant: " + pid};

    std::cout << "\nRegistration summary for " << p->getParticipantName() << "\n"
              << std::left << std::setw(8) << "ID" << std::setw(30) << "Event"
              << std::setw(14) << "Type" << "Fee (RM)\n"
              << std::string(62, '-') << "\n";

    int found = 0;
    double total = 0;

    for (int i = 0; i < data_struct.registrationCount; ++i)
    {
        Registration* r = registrationAt(data_struct, i);

        if (r->getParticipantId() == pid)
        {
            Event* e = getEvent(data_struct, r->getEventId());
            std::cout << std::setw(8) << e->getEventId()
                      << std::setw(30) << e->getEventName()
                      << std::setw(14) << e->getEventType()
                      << e->getRegistrationFee() << "\n";

            total = total + *e;                 // your overloaded operator+ (double + Event)
            ++found;
        }
    }

    std::cout << "Events: " << found << "   Total fees: RM" << total << "\n";
}

/**
 * @brief 
 * 
 * @param data_struct 
 */
void rptEventAmtSum(Data_s& data_struct)
{
    std::cout << "\n" << std::left << std::setw(8) << "ID" << std::setw(30) << "Event"
              << std::setw(15) << "Registrations" << "Fees (RM)\n"
              << std::string(62, '-') << "\n";

    for (int i = 0; i < data_struct.eventCount; ++i)          // loop events so events with 0 registrations still show
    {
        Event* e = static_cast<Event*>(data_struct.events[i].get());
        int count = 0;
        double fees = 0;

        for (int j = 0; j < data_struct.registrationCount; ++j)
        {
            if (registrationAt(data_struct, j)->getEventId() == e->getEventId())
            {
                ++count;
                fees = fees + *e;               // overloaded operator+ again
            }
        }

        std::cout << std::setw(8) << e->getEventId()
                  << std::setw(30) << e->getEventName()
                  << std::setw(15) << count
                  << fees << "\n";
    }
}
