#pragma once

#include "Event.hpp"
#include "Participant.hpp"
#include "Registration.hpp"
#include "MainData.hpp"

#include <cctype> // std::toupper
#include <fstream> // std::ofstream, std::ios::trunc
#include <iomanip> // std::left, std::setw
#include <iostream> // std::cin, std::cout, std::cerr
#include <memory> // std::unique_ptr
#include <stdexcept> // std::runtime_error
#include <string> // std::string, std::getline, std::stoi


struct Data_s
{
	/*
		- initializes an array of pointer objects
		- initilized from stack with a fixed size defined in MainData struct
		- the assumption is that data size will not exceed 50 inputs
	*/
    std::unique_ptr<MainData> events[MainData::MAX_SIZE];
    std::unique_ptr<MainData> participants[MainData::MAX_SIZE];
    std::unique_ptr<MainData> registrations[MainData::MAX_SIZE];
    int eventCount{};
	int participantCount {};
	int registrationCount {};
};

// MenuFeatures.cpp
int         parseUserInput();
std::string readId(const std::string& prompt);
void        displayMenu();
void		showEvents(Data_s& data_struct);
void		showParticipants(Data_s& data_struct);
void		showRegistrations(Data_s& data_struct);

// HelperFunctions.cpp
Event*        getEvent(Data_s& data_struct, const std::string& id);
Participant*  getParticipant(Data_s& data_struct, const std::string& id);
Registration* registrationAt(Data_s& data_struct, int i);
void          validateRegistrations(Data_s& data_struct);

// ManageRegistraions.cpp
void registerParticipant(Data_s& data_struct);
void cancelRegistration(Data_s& data_struct);

// GenerateReport.cpp
void rptTotalEventParticipant(Data_s& data_struct);
void rptParticipantSummary(Data_s& data_struct);
void rptEventAmtSum(Data_s& data_struct);
