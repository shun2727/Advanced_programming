#include "header.hpp"

/**
 * @brief Gets the event whose key matches the passed key
 *
 * Note :
 * .get() returns the raw pointer held inside the unique_ptr, the array keeps ownership.
 * static_cast converts MainData* back to Event*. This is safe because this array only ever holds Event objects.
 *
 * @param data_struct - the struct holding the three record arrays
 * @param key - event ID to look for, e.g. "E003"
 * @return Event* - pointer to the event, or nullptr if no event has that key
 */
Event* getEvent(Data_s& data_struct, const std::string& key)
{
    int i = MainData::getIndexFromKey(data_struct.events, data_struct.eventCount, key);

    if (i == -1)
        return nullptr;

    return static_cast<Event*>(data_struct.events[i].get());
}

/**
 * @brief Gets the participant whose key matches the passed key
 *
 * @param data_struct - the struct holding the three record arrays
 * @param key - participant ID to look for, e.g. "P001"
 * @return Participant* - pointer to the participant, or nullptr if no participant has that key
 */
Participant* getParticipant(Data_s& data_struct, const std::string& key)
{
    int i = MainData::getIndexFromKey(data_struct.participants, data_struct.participantCount, key);

    if (i == -1)
        return nullptr;

    return static_cast<Participant*>(data_struct.participants[i].get());
}

/**
 * @brief Gets the registration stored at a position in the registrations array
 *
 * Note :
 * Unlike getEvent and getParticipant, this does not search by key.
 * There is also no bounds check, so the caller must make sure 0 <= i < registrationCount.
 *
 * @param data_struct - the struct holding the three record arrays
 * @param i - position (index) in the registrations array
 * @return Registration* - pointer to the registration at that position
 */
Registration* registrationAt(Data_s& data_struct, int i)
{
    return static_cast<Registration*>(data_struct.registrations[i].get());
}

/**
 * @brief Removes registrations whose participant ID or event ID does not exist
 *
 * Note :
 * Run once after all three files are loaded, because a registration can only be checked
 * once events and participants are in their arrays.
 * It loops backwards, because removing an entry shifts the later ones down,
 * and going forwards would skip the entry that slides into the removed slot.
 *
 * @param data_struct - the struct holding the three record arrays
 */
void validateRegistrations(Data_s& data_struct)
{
    for (int i = data_struct.registrationCount - 1; i >= 0; --i)      // backwards so removing doesn't skip items
    {
        Registration* reg = registrationAt(data_struct, i);

        if (getParticipant(data_struct, reg->getParticipantId()) == nullptr)
        {
            std::cerr << "Registration " << reg->getKey() << " skipped: unknown participant\n";
            MainData::removeEntry(data_struct.registrations, data_struct.registrationCount, i);
        }
        else if (getEvent(data_struct, reg->getEventId()) == nullptr)
        {
            std::cerr << "Registration " << reg->getKey() << " skipped: unknown event\n";
            MainData::removeEntry(data_struct.registrations, data_struct.registrationCount, i);
        }
    }
}