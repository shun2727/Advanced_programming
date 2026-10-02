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
		//looks convoluted but its 
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