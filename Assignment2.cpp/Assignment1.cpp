#include "header.hpp"

template <typename T>
T read_value(std::stringstream& stream, char delimiter)
{
    std::string value;
    std::getline(stream, value, delimiter);

    std::stringstream converter(value);

    T result;
    converter >> result;

    return result;
}

/**
 * @brief 
 * 
 * @param tasks_arr 
 * @return int 
 */
int parse_task(auto &tasks_arr)
{
	auto taskIndex {0};
	std::ifstream file("Tasks.txt");
	if (!file)
        return 0;
	
	std::string file_line;    
    while (taskIndex < tasks_arr.size() && std::getline(file, file_line))
    {
        std::stringstream line_stream(file_line);

        tasks_arr[taskIndex].taskId = read_value<int>(line_stream, ',');
        tasks_arr[taskIndex].description = read_value<std::string>(line_stream, ';');
        tasks_arr[taskIndex].uncertainty = read_value<int>(line_stream, '$');
        tasks_arr[taskIndex].difficulty = read_value<int>(line_stream, '%');
        tasks_arr[taskIndex].priorityLabel = read_value<int>(line_stream, '&');

		std::string temp;
        std::getline(line_stream, temp, ':');

        tasks_arr[taskIndex].workerCount = 0;
        while (std::getline (line_stream, temp, ','))
            tasks_arr[taskIndex].workerIds[tasks_arr[taskIndex].workerCount++] = std::stoi(temp);

        taskIndex++;
    }
	
    return taskIndex;
}
/**
 * @brief 
 * 
 * @param worker_arr 
 * @return int 
 */
int parse_workers(auto &worker_arr)
{
	auto worker_index{0};
	std ::ifstream file("Workers.txt");
	if (!file)
		return (0);

	std ::string file_line;
    while (worker_index < worker_arr.size() && std ::getline(file, file_line))
	{
		std::stringstream line_stream(file_line);

		worker_arr[worker_index].workerId = read_value<int>(line_stream, ',');
		worker_arr[worker_index].name = read_value<std::string>(line_stream, '%');
		worker_arr[worker_index].variability = read_value<int>(line_stream, '$');
		worker_arr[worker_index].ability = read_value<int>(line_stream, ';');
		worker_arr[worker_index].experienceLabel = read_value<int>(line_stream, ' ');

		worker_index++;
	}
	return worker_index;

}
void debug_tasks(auto& tasks, int task_size)
{
    std::cout << "\n===== TASKS =====\n";

    for (int i{0}; i < task_size; ++i)
    {
        std::cout << "Task ID: " << tasks[i].taskId
                  << " | Description: " << tasks[i].description
                  << " | Uncertainty: " << tasks[i].uncertainty
                  << " | Difficulty: " << tasks[i].difficulty
                  << " | Priority: " << tasks[i].priorityLabel
                  << " | Workers: ";

        for (int j{0}; j < tasks[i].workerCount; ++j)
        {
            std::cout << tasks[i].workerIds[j];

            if (j + 1 < tasks[i].workerCount)
                std::cout << ", ";
        }

        std::cout << '\n';
    }
}
void debug_workers(auto& workers, int worker_size)
{
    std::cout << "\n===== WORKERS =====\n";

    for (int i{0}; i < worker_size; ++i)
    {
        std::cout << "Worker ID: " << workers[i].workerId
                  << " | Name: " << workers[i].name
                  << " | Variability: " << workers[i].variability
                  << " | Ability: " << workers[i].ability
                  << " | Experience: " << workers[i].experienceLabel
                  << '\n';
    }
}


/**
 * @brief Calculates the worker's average performance
 * 
 * @param task current tasks's struct, const as no value is manipulated
 * @param normalDistribution 
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

	if (worker.experienceLabel == 1) // Senior worker +2
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

    auto task_size = parse_task(tasks);
    auto worker_size = parse_workers(workers);

    if (task_size == 0 || worker_size == 0)
        return (printf("File error\n"), 1);

	//uncomment this section to crosscheck if stored info is accurate
    	//debug_tasks(tasks, task_size);
    	//debug_workers(workers, worker_size);

	for (int i = 0; i < task_size ; ++i)
	{
        std::cout << "Details for task \"" << tasks[i].description << "\":\n";
		tasks[i].bestWorkerId = findBestWorker(tasks[i], workers);
	}

    return 0;
}
