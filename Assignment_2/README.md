_This project is made by 0135347 yee shun qi for the advanced programming course within UOW_

# Event Registration and Ticket Management System
## Objective
Using oop concpets an principles develop a C++ application for an event registration and ticket management system 

The system is designed to :
- Manage events, participants and registrations through text files. 
- Allow users to view available events, manage participant information, register participants for events, cancel registrations and generate registration reports.

## System Overview
### Part A
---
This following section breaks down the requirements of the project : 
1. Event Management : 
	- Open and read Event.txt.
		- Event.txt format :
		``` text
			eventId;eventName;eventType;registrationFee
		```
		- Event.txt sample information:
		``` text
			E001;C++ Workshop;Workshop;150
			E002;AI Seminar;Seminar;100
		```
	- Parse event information using the specified delimiters.
	- Store event information using arrays or lists.
	- Display available events.
	- Store details such as event ID, event name, event type and registration fee.

2. Participant Management:
    - Open and read Participant.txt.
        - Participant.txt format:
		```text
            participantId;participantName
		```
        - Participant.txt sample information:
		```text
            P001;Ali Hassan
            P002;Siti Nurhaliza
		```
    - Parse participant information using the specified delimiters.
    - Store participant records using arrays or lists.
    - Display participant records.
    - Store details such as participant ID and participant name.

3. Registration Management:
    - Open and read Registration.txt.
        - Registration.txt format:
		```text
            participantId;eventId
		```
        - Registration.txt sample information:
		```text
            P001;E001
            P002;E002
		```
    - Parse registration information using the specified delimiters.
    - Store registration records using arrays or lists.
    - Allow participants to register for events.
    - Allow users to cancel existing registrations.
    - Prevent duplicate registrations.
    - Allow one participant to register for multiple events.

4. Reporting Functions:
    - Generate reports based on the stored registration information.
    - Display a list of participants registered for a particular event.
    - Display the registration summary for a participant.
    - Calculate the total number of registrations for each event.
    - Calculate the total registration fees collected for each event.

### Part B 
---
Following are the modifications I made to incorporate modern C++ features (c++ 11 and later):


### Files - Role of each source file
--- 
1. driver.cpp : contains the main function
2. header.cpp : contains functions of the main logic supporting the main funciton
3. header.h : (althought the converntion is to use header.hpp as per subject requirments it is stored as header.h) contains the struct, function prototypes and libraries needed for the program
4. README.md : current file with overview of the entire project

### Complilation guide 
---
Compile with the following std flags, then output to `task_assignment` as the program name
```bash
	g++ -std=c++20 driver.cpp header.cpp -o task_assignment
```
ensure `Workers.txt` and `Tasks.txt` are located in the same folder, then run with
``` bash
	./task_assignment
```
## Design designs

## Reference list


## AI usage
These resources alone were not sufficient for me to fully grasp the concepts such a when it came to how the normal distribution and random number functions works beneath, how do i utilize span and the usage of stringstream. 

Therefore AI was used to give more compreensive examples, to break down concepts and to provide guidance on implementation. 

If there are doubts on the progress on the assignment, view the git logs from my github page : https://github.com/shun2727/Advanced_programming.git