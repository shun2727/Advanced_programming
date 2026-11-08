#include "header.hpp"

std::size_t parseEventFile(std::array<Event, SIZE>& event_arr)
{
    std::size_t event_count{};
    std::ifstream event_file{"./inputFiles/Event.txt"};
    std::string event_buffer;

    if (!event_file)
        throw std::runtime_error{"Unable to open ./inputFiles/Event.txt"};

    while (event_count < event_arr.size() && std::getline(event_file, event_buffer))
    {
        if (event_buffer.empty())
            continue;

        std::istringstream event_stream{event_buffer};
        std::string event_id;
        std::string event_name;
        std::string event_type;
        std::string fee_text;
        double registration_fee{};

        if (!(std::getline(event_stream, event_id, ';') &&
              std::getline(event_stream, event_name, ';') &&
              std::getline(event_stream, event_type, ';') &&
              std::getline(event_stream, fee_text)))
            throw std::runtime_error{"Invalid event record: " + event_buffer};

        try
        {
            registration_fee = std::stod(fee_text);
        }
        catch (const std::exception&)
        {
            throw std::runtime_error{"Invalid registration fee: " + fee_text};
        }

        event_arr[event_count++] = Event{std::move(event_id), std::move(event_name),
                                         std::move(event_type), registration_fee};
    }

    return event_count;
}

void displayEvents(const std::array<Event, SIZE>& event_arr, std::size_t event_count)
{
    std::cout << std::left
              << std::setw(8)  << "ID"           << "| "
              << std::setw(25) << "Name"         << "| "
              << std::setw(15) << "Type"         << "| "
              << "Fee (RM)\n";

    for (std::size_t i{}; i < event_count; i++)
        std::cout << std::left
                  << std::setw(8)  << event_arr[i].getEventId()   << "| "
                  << std::setw(25) << event_arr[i].getEventName() << "| "
                  << std::setw(15) << event_arr[i].getEventType() << "| "
                  << std::fixed << std::setprecision(2)
                  << event_arr[i].getRegistrationFee() << '\n';
}