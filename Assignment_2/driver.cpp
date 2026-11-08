#include "header.hpp"
#include <fstream> // ifstream , stoi
#include <sstream> //stringstream

int main()
{
    constexpr std::size_t SIZE = 20;
    std::array<Event, SIZE> event_arr;
    std::size_t event_count = parseEventFile(event_arr);   // N deduced as 20

    displayEvents(event_arr, event_count);
}


