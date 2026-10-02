#include "header.hpp"

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

/**
 * @brief Opens the file and parses it into the task_arr argument
 * 
 * @param tasksArr 
 * @return int 
 */
int parseTask(auto& tasksArr)
{
	auto taskIndex {0};
	std::ifstream file("Tasks.txt");
	if (!file)
        return 0;
	
	std::string fileLine;    
	while (taskIndex < tasksArr.size() && std::getline(file, fileLine))
    {
        std::stringstream lineStream(fileLine);

        tasksArr[taskIndex].taskId = readValue<int>(lineStream, ',');
        tasksArr[taskIndex].description = readValue<std::string>(lineStream, ';');
        tasksArr[taskIndex].uncertainty = readValue<int>(lineStream, '$');
        tasksArr[taskIndex].difficulty = readValue<int>(lineStream, '%');
        tasksArr[taskIndex].priorityLabel = readValue<int>(lineStream, '&');

		std::string temp;
        std::getline(lineStream, temp, ':');

        tasksArr[taskIndex].workerCount = 0;
        while (std::getline (lineStream, temp, ','))
            tasksArr[taskIndex].workerIds[tasksArr[taskIndex].workerCount++] = std::stoi(temp);

        taskIndex++;
    }
	
    return taskIndex;
}

/**
 * @brief Opens the worker file and parses to to the worker_arr argument
 * 
 * @param workerArr 
 * @return int 
 */
int parseWorkers(auto& workerArr)
{
    auto workerIndex{0};
	std ::ifstream file("Workers.txt");
	if (!file)
		return (0);

    std ::string fileLine;
    while (workerIndex < workerArr.size() && std ::getline(file, fileLine))
	{
        std::stringstream lineStream(fileLine);

        workerArr[workerIndex].workerId = readValue<int>(lineStream, ',');
        workerArr[workerIndex].name = readValue<std::string>(lineStream, '%');
        workerArr[workerIndex].variability = readValue<int>(lineStream, '$');
        workerArr[workerIndex].ability = readValue<int>(lineStream, ';');
        workerArr[workerIndex].experienceLabel = readValue<int>(lineStream, ' ');

        workerIndex++;
	}
    return workerIndex;

}
/**
 * @brief iterates the entire task span, and displays the values
 * 
 * @param tasks 
 */
void debugTasks(auto& tasks)
{
    std::cout << "\n===== TASKS =====\n";

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
    std::cout << "\n===== WORKERS =====\n";

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

/**
 * @brief Calculates the worker's average performance, rd from random_device gets an entrophic value from the sytem and passess it to normalDistribution 
 * 
 * @param task current tasks's struct, const as no value is manipulated
 * @param normalDistribution normal distribution object initilized in findBestWorker
 * @param worker worker's struct according to it's id, const as no value is manipulated
 * @return Worker's average performance 
 */
auto calculateAvg(const auto task, auto normalDistribution, const auto worker)
{
	std::random_device rd;
	int sampleAmt;
	double total = 0;

	if (task.priorityLabel == 0)
		sampleAmt = 10; // Low priority loop 10 
	else
		sampleAmt = 15; // High priority loop 15 

	for (int j{0}; j < sampleAmt; ++j)
		total += normalDistribution(rd);

	double average = total / sampleAmt;

	if (worker.experienceLabel == 1) // Senior worker +2 by the end of the result
		average += 2;

	return (average);
}

/**
 * @brief find workerId of worker with best average performance, will print score of each worker for comparison purposes
 * 
 * @param task current task being processed
 * @param workers accepts worker array, const because no data is manipulated
 * @return int workerId of worker with best average performance
 */
int findBestWorker(auto& task, const auto& workers)
{
    double bestScore = 0; //assuming all the best scores are impossible to be negative values
    int bestWorkerId = -1; //-1 is placed because no worker is id -1

    for (int i{0}; i < task.workerCount; ++i)
    {
        int workerId = task.workerIds[i];
        auto& worker = workers[workerId];

        double mean = worker.ability - task.difficulty;
        double sd = std::abs(task.uncertainty + worker.variability);
        if (sd == 0)
            sd = 1;

		//create nd centred around mean and sd of 5
		//initialize the normal distribution
        std::normal_distribution<double> normalDistribution(mean, sd);

        double average = calculateAvg(task, normalDistribution, worker);
        std::cout << "Worker ID: " << worker.workerId << ", Name: " << worker.name << ", Average performance score: " << average << '\n';

        if (average > bestScore)
        {
            bestScore = average;
            bestWorkerId = worker.workerId;
        }
    }

    std::cout << "Best worker for task \"" << task.description << "\" is Worker ID: " << bestWorkerId << ", Name: " << workers[bestWorkerId].name << ", Score: " << bestScore << "\n\n";
    return (bestWorkerId);
}

int main()
{
    std::array<t_tasks, SIZE> tasks{};
    std::array<t_worker, SIZE> workers{};

	//althought not repeatedly used, parsing the files are seperated into their respective functions to not overload the main	
    auto taskSize = parseTask(tasks);
    auto workerSize = parseWorkers(workers);

    if (taskSize == 0 || workerSize == 0)
        return (printf("File error\n"), 1);

	//const for worker as 
	std::span<const t_worker> loadedWorker (workers.data(), workerSize);
    std::span<t_tasks> loadedTasks (tasks.data(), taskSize);

	//uncomment this section to crosscheck if stored info is accurate
        //debugTasks(loadedTasks);
        //debugWorkers(loadedWorker);
		//std::cout << "\n";

    for (auto& task : loadedTasks)
	{
        std::cout << "Details for task \"" << task.description << "\":\n";
        task.bestWorkerId = findBestWorker(task, workers);
	}

    return 0;
}
