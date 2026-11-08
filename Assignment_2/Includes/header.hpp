#pragma once

#include "Event.hpp"
#include "Participant.hpp"
#include "Registration.hpp"
#include "MainData.hpp"

#include <array>      // std::array
#include <cstddef>    // std::size_t
#include <fstream>    // std::ifstream , atod
#include <sstream>    // std::istringstream
#include <stdexcept>  // std::runtime_error
#include <string>     // std::string, std::stod
#include <utility>    // std::move
#include <iomanip>	//setprecision()
#include <iostream>

/*
	EventUtility.cpp
*/
const std::size_t SIZE = 20;
std::size_t parseEventFile(std::array<Event, SIZE>& event_arr);
void displayEvents(const std::array<Event, SIZE>& event_arr, std::size_t event_count);

