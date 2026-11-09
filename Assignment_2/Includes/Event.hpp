#pragma once

#include "MainData.hpp"
#include <string>
#include <stdexcept>
#include <utility>
#include <sstream>

/**
 * @brief 
 * 
 */
class Event : public MainData
{
	private:
		std::string event_id_;
		std::string event_name_;
		std::string event_type_;
		double registration_fee_{}; //uniform initilization

	public:
		/*
			Orthodox Canonical Form (no special content is initilized thus default is used)
		*/
		Event() = default;//default constructor
		virtual ~Event() = default; //destructor
		Event(const Event&) = default; //copy constructor
		Event& operator=(const Event&) = default; //copy assignment
		
		/*
			Parameterized constructor that also demonstrates constructor overloading
		*/
		Event(std::string event_id, std::string event_name, std::string event_type, double registration_fee);

		/*
			move constructor and move assignment
		*/
		Event(Event&&) noexcept = default;
		Event& operator=(Event&&) noexcept = default;
		
		/*
			Accessors, nodiscard here
		*/
		[[nodiscard]] const std::string& getEventId() const;
		[[nodiscard]] const std::string& getEventName() const;
		[[nodiscard]] const std::string& getEventType() const;
		[[nodiscard]] double getRegistrationFee() const;
		
		/*
			Mutators
		*/
		void setEventId(std::string event_id);
		void setEventName(std::string event_name);
		void setEventType(std::string event_type);
		void setRegistrationFee(double registration_fee);

		/*
			operational functions
		*/
		// implied must have by MainData class
		void parseLine(const std::string& line) override;
		void display() const override;
		[[nodiscard]] std::string getKey() const override;
		[[nodiscard]] std::unique_ptr<MainData> makeUniquePointer() const override;

		// operator overloading (fee calculation)
		[[nodiscard]] double operator+(const Event& other) const; // event + event
		friend double operator+(double total, const Event& e); // running total + event

		/*
			friend operator for printing
				self note : friend declaration gives a function outside the class permission to read the class’s private members
		*/
		friend std::ostream& operator<<(std::ostream& os, const Event& e);

};