/*
	instead of #ifndef #define
	#pragma once prevents this header file
    from being included more than once
    in the same compilation.
*/

#pragma once 

#include <iostream>
#include <random> 
#include <sstream> //for stringstream
#include <string> //for std::string
#include <fstream> //for files
#include <array> //for array

#ifndef SIZE
#define SIZE 20 //consistent sizing across workers and tasks to the limit of 20
#endif

typedef struct s_worker
{
	int workerId;
	std::string name;
	int variability;
	int ability;
	int experienceLabel;
	
} t_worker;

typedef struct s_tasks
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