/*
Self note :
	instead of #ifndef #define
	#pragma once prevents this header file
    from being included more than once
    in the same compilation.
*/

#pragma once 

#include <iostream> //cout
#include <random> // for randomdevice (used to get an enthropic value from the system)
#include <sstream> //for stringstream
#include <string> //for std::string
#include <fstream> //for files
#include <array> //for array
#include <span> //for span contianer
#include <cstddef> //for size_t

#ifndef SIZE
#define SIZE 20 //consistent sizing across workers and tasks to the limit of 20 as per assignment stated
#endif

// structs are deliberatly written as such for tidiness 
typedef struct sWorker
{
	int workerId;
	std::string name;
	int variability;
	int ability;
	int experienceLabel;
	
} t_worker;

typedef struct sTasks
{
	int taskId;
	std::string description;
	int uncertainty;
	int difficulty;
	int priorityLabel;

	int workerCount;
	std::array<int, SIZE> workerIds;
	int bestWorkerId;

} t_tasks;