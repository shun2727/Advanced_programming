#pragma once

#include <string>
#include <utility>

class Registration
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
		Registration& operator=(const Registration&) noexcept= default;

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
};