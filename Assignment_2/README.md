_This project is made by 0135347 yee shun qi for the advanced programming course within UOW_

# Event Registration and Ticket Management System
## Objective
Using oop concpets and principles develop a C++ application for an event registration and ticket management system 

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
	- Parse event information using the `;` delimiter.
	- Data_s event information using arrays or lists for event ID, event name, event type and registration fee.
	- Display available events into the terminal

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
	- Parse event information using the `;` delimiter.
    - Data_s participant records using arrays or lists for participant ID and participant name.
    - Display participant records to terminal.

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
	- Parse event information using the `;` delimiter.
    - Data_s registration records using arrays or lists.
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
## Requirements
The following lists requirements for part B as well as my reference and notes on where these concepts can be found thorught my program implementation : 

1. **Runtime Polymorphism.** Implement virtual functions and demonstrate runtime polymorphism through base class pointers or references.
	- usage of virtual

2. **Construct Overloading.** Provide overloaded constructors where appropriate.
	- default , parameterized

3. **Operator Overloading.** Implement at least one meaningful operator overloading function. Examples may include registration comparison, fee calculation, participant statistics.
	-  i u

4. **Friend Functions.** Implement at least one meaningful friend function.
	- iu

5. **Exception Handling.** Use exception handling to manage situations such as invalid event ID, invalid participant ID, duplicate registration, file processing errors.
	- written inside the setter funcitons wihtin each class
	
6. **File Processing.** The application shall:
   1. read information from the provided text files.
   2. save any modifications back to files when required.

7. **Modern C++**
	1. std::array
	

### Files - Role of each source file
--- 
#### File structure :

#### File roles : 

### Complilation guide 
---
Due to the volume of source files, a Makefile has been created to compile into a executionable file.

First ensure `Event.txt` `Participant.txt` and `Registration.txt` are located within the `/inputFiles` . Otherwise change the folder location in `Main/driver.cpp` in this seciton of the code within `main()`

```c++
MainData::loadFile("./inputFiles/Event.txt", data.events, data.eventCount, Event{});
MainData::loadFile("./inputFiles/Participant.txt", data.participants, data.participantCount, Participant{});
MainData::loadFile("./inputFiles/Registration.txt", data.registrations, data.registrationCount, Registration{});        
```

Then run : 
```bash
	make
```
You may check the `PHONY.` values for other capabilities :


These are implemented for me to use during development in the case of recompilation and object file deletion. 


## Design (Class Diagram)


## Reference list [IEEE referencing]
Some of the topics were covered in the advanced programming class, however for my own future reference some of those concepts will be refrered here.

1. Naming conventions

2. Virtual for 
	- 

3. String stream 
	- https://en.cppreference.com/cpp/io/strstream
	
4. stoi / stod
	- https://www.geeksforgeeks.org/cpp/stdstoi-function-in-cpp/

5. Makefile




## AI usage
These resources alone were not sufficient for me to fully grasp the concepts such a when it came to how the normal distribution and random number functions works beneath, how do i utilize span and the usage of stringstream. 

Therefore AI was used to give more compreensive examples, to break down concepts and to provide guidance on implementation. 

If there are doubts on the progress on the assignment, view the git logs from my github page : https://github.com/shun2727/Advanced_programming.git