#include "header.h"

/**
 * @brief Opens the file and parses it into the task_arr argument
 * 
 * @param tasksArr 
 * @return int 
 */
int parseTask(std::array<sTasks, SIZE>& tasksArr)
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
        while (std::getline(lineStream, temp, ','))
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
int parseWorkers(std::array<sWorker, SIZE>& workerArr)
{
    auto workerIndex{0};
    std::ifstream file("Workers.txt");
    if (!file)
        return 0;

    std::string fileLine;
    while (workerIndex < workerArr.size() && std::getline(file, fileLine))
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
 * @brief Calculates the worker's average performance, rd from random_device gets an entrophic value from the sytem and passess it to normalDistribution 
 * 
 * @param task current tasks's struct, const as no value is manipulated
 * @param normalDistribution normal distribution object initilized in findBestWorker
 * @param worker worker's struct according to it's id, const as no value is manipulated
 * @return Worker's average performance 
 */
double calculateAvg( const sTasks& task, std::normal_distribution<double>& normalDistribution, const sWorker& worker)
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

    return average;
}

/**
 * @brief find workerId of worker with best average performance, will print score of each worker for comparison purposes
 * 
 * @param task current task being processed
 * @param workers accepts worker array, const because no data is manipulated
 * @return int workerId of worker with best average performance
 */
int findBestWorker( sTasks& task, const std::array<sWorker, SIZE>& workers)
{
    double bestScore = 0; // assuming all the best scores are impossible to be negative values
    int bestWorkerId = -1; // -1 is placed because no worker is id -1

    for (int i{0}; i < task.workerCount; ++i)
    {
        int workerId = task.workerIds[i];
        const auto& worker = workers[workerId];

        double mean = worker.ability - task.difficulty;
        double sd = std::abs(task.uncertainty + worker.variability);

        if (sd == 0)
            sd = 1;

        // create nd centred around mean and sd of 5
        // initialize the normal distribution
        std::normal_distribution<double> normalDistribution(mean, sd);

        double average = calculateAvg(task, normalDistribution, worker);

        std::cout << "Worker ID: " << worker.workerId
                  << ", Name: " << worker.name
                  << ", Average performance score: " << average << '\n';

        if (average > bestScore)
        {
            bestScore = average;
            bestWorkerId = worker.workerId;
        }
    }

    std::cout << "Best worker for task \"" << task.description
              << "\" is Worker ID: " << bestWorkerId
              << ", Name: " << workers[bestWorkerId].name
              << ", Score: " << bestScore << "\n\n";

    return bestWorkerId;
}