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
 * return amount of tasks
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

int parse_workers(auto &worker_arr)
{
	auto worker_index{0};
	std ::ifstream file("Workers.txt");
	if (!file)
		return (0);

	std ::string file_line;
	while (worker_index < SIZE && std ::getline(file, file_line))
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
        std::cout << "Task ID: " << tasks[i].taskId << '\n';
        std::cout << "Description: " << tasks[i].description << '\n';
        std::cout << "Uncertainty: " << tasks[i].uncertainty << '\n';
        std::cout << "Difficulty: " << tasks[i].difficulty << '\n';
        std::cout << "Priority: " << tasks[i].priorityLabel << '\n';

        std::cout << "Workers: ";

        for (int j{0}; j < tasks[i].workerCount; ++j)
        {
            std::cout << tasks[i].workerIds[j];

            if (j + 1 < tasks[i].workerCount)
                std::cout << ", ";
        }

        std::cout << "\n\n";
    }
}
void debug_workers(auto& workers, int worker_size)
{
    std::cout << "\n===== WORKERS =====\n";

    for (int i{0}; i < worker_size; ++i)
    {
        std::cout << "Worker ID: "
                  << workers[i].workerId << '\n';

        std::cout << "Name: "
                  << workers[i].name << '\n';

        std::cout << "Variability: "
                  << workers[i].variability << '\n';

        std::cout << "Ability: "
                  << workers[i].ability << '\n';

        std::cout << "Experience: "
                  << workers[i].experienceLabel << '\n';

        std::cout << '\n';
    }
}
void print_results(const auto tasks, auto task_size)
{
	std::cout << "\n===== RESULTS =====\n";

    for (int i{0}; i < task_size; ++i)
    {
        std::cout << "Task "
                  << tasks[i].taskId
                  << " -> Worker "
                  << tasks[i].bestWorkerId
                  << '\n';
    }
}

int calculateAvg(const auto task, auto normalDistriution)
{
	std::random_device rd;
	std::default_random_engine engine(rd());
	// Low priority = 10 samples
	// High priority = 15 samples
	int sampleCount;
	if (task.priorityLabel == 0)
		sampleCount = 10;
	else
		sampleCount = 15;

	// Generate samples
	double total = 0;

	for (int j{0}; j < sampleCount; ++j)
	{
		total += normalDistribution(engine);
	}

	// Calculate average
	double average = total / sampleCount;

	// Senior worker gets +2
	if (worker.experienceLabel == 1)
		average += 2;
}

int findBestWorker(auto& task, auto& workers)
{

    double bestScore = -std::numeric_limits<double>::infinity();
    int bestWorkerId = -1;

    for (int i{0}; i < task.workerCount; ++i)
    {
        int workerId = task.workerIds[i];
        auto& worker = workers[workerId];

        double mean = worker.ability - task.difficulty;
        double sd = std::abs(task.uncertainty + worker.variability);
        if (sd == 0)
            sd = 1;

        std::normal_distribution<double> normalDistribution(mean, sd);

		calculateAvg

        // Check if this is the best worker so far
        if (average > bestScore)
        {
            bestScore = average;
            bestWorkerId = worker.workerId;
        }
    }

    return bestWorkerId;
}

void print_result()
{

}


int main()
{
    std::array<t_tasks, SIZE> tasks{};
    std::array<t_worker, SIZE> workers{};

    auto task_size = parse_task(tasks);
    auto worker_size = parse_workers(workers);

    if (task_size == 0 || worker_size == 0)
        return (printf("File error\n"), 1);

    //debug_tasks(tasks, task_size);
    //debug_workers(workers, worker_size);
	/*
		for each task
			task.bestwrokerId = calculatebest worker
	*/
	for (auto &task_items :tasks)
		task_items.bestWorkerId = findBestWorker(task_items, workers, task_size);

	//print task & worker ();

    return 0;
}
