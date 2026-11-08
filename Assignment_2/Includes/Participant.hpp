#pragma once

#include "MainData.hpp"
#include <string>
#include <utility> // std::move

class Participant : public MainData
{
	private:
		std::string participant_id_;
		std::string participant_name_;

	public:
		/*
			Orthodox Canonical Form (no special content is initilized thus default is used)
		*/
		Participant() = default; // default constructor
		virtual ~Participant() = default; // destructor
		Participant(const Participant&) = default; // copy constructor
		Participant& operator=(const Participant&) = default; // copy assignment
		
		/*
			Parameterized constructor that also demonstrates constructor overloading
		*/
		Participant(std::string participant_id, std::string participant_name);

		/*
			move constructor and move assignment, noexcept here
		*/
		Participant(Participant&&) noexcept = default;
		Participant& operator=(Participant&&) noexcept = default;

		/*
			Accessors, nodiscard here
		*/
		[[nodiscard]] const std::string& getParticipantId() const;
		[[nodiscard]] const std::string& getParticipantName() const;

		/*
			Mutators
		*/
		void setParticipantId(std::string participant_id);
		void setParticipantName(std::string participant_name);

		/*
			
		*/
};