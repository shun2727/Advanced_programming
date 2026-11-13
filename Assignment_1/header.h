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

#define SIZE 20 //consistent sizing across workers and tasks to the limit of 20 as per assignment stated

// structs are deliberatly written as such for tidiness 
struct sWorker
{
	int workerId;
	std::string name;
	int variability;
	int ability;
	int experienceLabel;
	
};

struct sTasks
{
	int taskId;
	std::string description;
	int uncertainty;
	int difficulty;
	int priorityLabel;

	int workerCount;
	std::array<int, SIZE> workerIds;
	int bestWorkerId;

};

//main functions 
//templates must be defied in the header file
/**
 * @brief Template is used here for the different data types like string and int that can be extracted from the stream
 * 
 * @tparam T 
 * @param stream 
 * @param delimiter 
 * @return T 
 */
template <typename T>
T readValue(std::stringstream& stream, char delimiter)
{
    std::string value;
    std::getline(stream, value, delimiter);

    std::stringstream converter(value);

    T result;
    converter >> result;

    return result;
}

/*
	Functions that use auto are required to be placed in the header due to their 
		use of abbreviated function templates, which require their definitions to be 
		visible at the point of instantiation.

	Althought these seem weird to put in here,
		to demonstrate generic programming 
		both debugger functions can work with different compatible containers, 
		such as std::array and std::span, without requiring separate functions 
		for each container type. (It is not demonstrated in the program but the justificaiton to
		put it in extends on what was done currently in the program)
*/

/**
 * @brief iterates the entire task span, and displays the values
 * 
 * @param tasks 
 */
void debugTasks(auto& tasks)
{
    std::cout << "\n TASKS \n";

    for (const auto& task : tasks)
    {
        std::cout << "Task ID: " << task.taskId
                  << " | Description: " << task.description
                  << " | Uncertainty: " << task.uncertainty
                  << " | Difficulty: " << task.difficulty
                  << " | Priority: " << task.priorityLabel
                  << " | Workers: ";

        bool firstWorker = true;
        for (int workerId : std::span<const int>{task.workerIds}.first(static_cast<std::size_t>(task.workerCount)))
        {
            if (!firstWorker)
                std::cout << ", ";
            std::cout << workerId;
            firstWorker = false;
        }

        std::cout << '\n';
    }
}
/**
 * @brief iterates the entire worker span, and displays the values
 * 
 * @param workers 
 */
void debugWorkers(auto& workers)
{
    std::cout << "\n WORKERS \n";

    for (const auto& worker : workers)
    {
        std::cout << "Worker ID: " << worker.workerId
                  << " | Name: " << worker.name
                  << " | Variability: " << worker.variability
                  << " | Ability: " << worker.ability
                  << " | Experience: " << worker.experienceLabel
                  << '\n';
    }
}

int parseTask(std::array<sTasks, SIZE>& tasksArr);
int parseWorkers(std::array<sWorker, SIZE>& workerArr);
double calculateAvg(const sTasks& task,std::normal_distribution<double>& normalDistribution,const sWorker& worker);
int findBestWorker(sTasks& task, const std::array<sWorker, SIZE>& workers);