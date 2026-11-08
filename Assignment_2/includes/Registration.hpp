#pragma once
#include <string>

class Registration
{
	private:
		std::string participantId_;
		std::string eventId_;

	public:
		Registration();
		Registration(const std::string& participantId, const std::string& eventId);

		std::string getParticipantId() const;
		std::string getEventId() const;

		void setParticipantId(const std::string& participantId);
		void setEventId(const std::string& eventId);
};
