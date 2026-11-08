#pragma once
#include <string>

class Event
{
private:
    std::string event_id_;
    std::string event_name_;
    std::string event_type_;
    double registration_fee_{}; //uniform initilization

public:
    Event() = default;//default constructor
    virtual ~Event() = default; //destructor
    Event(const Event&) = default; //copy constructor
    Event& operator=(const Event&) = default; //copy assignment
    Event(std::string event_id, std::string event_name, std::string event_type, double registration_fee);

	//eh ?
    Event(Event&&) noexcept = default;
    Event& operator=(Event&&) noexcept = default;

    // accessors
    [[nodiscard]] const std::string& getEventId() const;
    [[nodiscard]] const std::string& getEventName() const;
    [[nodiscard]] const std::string& getEventType() const;
    [[nodiscard]] double getRegistrationFee() const;

    // mutators
    void setEventId(std::string event_id);
    void setEventName(std::string event_name);
    void setEventType(std::string event_type);
    void setRegistrationFee(double registration_fee);
};