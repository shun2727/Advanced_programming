#pragma once

#include <string>
#include <stdexcept>
#include <utility>

class Event
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
};