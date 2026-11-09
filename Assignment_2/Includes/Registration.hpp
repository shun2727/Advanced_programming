#pragma once

#include "MainData.hpp"

#include <iomanip> // std::left, std::setw
#include <iostream> // std::cout, std::ostream
#include <memory> // std::make_unique, std::unique_ptr
#include <sstream> // std::istringstream
#include <stdexcept> // std::runtime_error
#include <string> // std::string
#include <utility> // std::move

class Registration : public MainData
{
	private:
		std::string participant_id_;
		std::string event_id_;

	public:
		Registration() = default;
		~Registration() = default;
		Registration(const Registration&) = default;
		Registration& operator=(const Registration&) = default;

		/*
			move constructor and move copy construtcor
			importnatn for noexcpet to be used here
		*/
		Registration(Registration&&) noexcept = default;
		Registration& operator=(Registration&&) noexcept = default;
		/* 
			Parameterised Constructor
		*/
		Registration(const std::string& participant_id, const std::string& event_id);
		
		/*
			Getter
		*/
		[[nodiscard]] const std::string& getParticipantId() const;
		[[nodiscard]] const std::string& getEventId() const;

		/*
			Setters
		*/
		void setParticipantId(const std::string& participant_id);
		void setEventId(const std::string& event_id);

		/*
			operational functions
		*/
		// implied must have by MainData class
		void printHeader() const override;
		void parseLine(const std::string& line) override;
		void display() const override;
		[[nodiscard]] std::string getKey() const override;
		[[nodiscard]] std::unique_ptr<MainData> makeUniquePointer() const override;

		// operator overloading: two registrations are equal if both IDs match
		[[nodiscard]] bool operator==(const Registration& other) const;

		friend std::ostream& operator<<(std::ostream& os, const Registration& r);
};