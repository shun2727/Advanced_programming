#pragma once

#include "Event.hpp"
#include "Participant.hpp"
#include "Registration.hpp"

class MainData{

	static const int MAX_SIZE = 50;

	private :
	
		Event *event_;
		Participant *participant_;
		Registration *registration_;

		int event_count_ {};
		int participant_count_ {};
		int registration_count_ {};

		//Record* createRecord(FileType type) const;
		
	public :
		void loadAll(const std::string& event_file, const std::string& participant_file, const std::string& registration_file) 
		void displayAll(Record* const arr[], int count) const;
		void parseFile(const std::string& path, Record* arr[], int& count, FileType type);
		
};
