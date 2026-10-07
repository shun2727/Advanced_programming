#include "header.h"

int main()
{
    std::array<sTasks, SIZE> tasks{};
    std::array<sWorker, SIZE> workers{};

	//althought not repeatedly used, parsing the files are seperated into their respective functions to not overload the main	
    auto taskSize = parseTask(tasks);
    auto workerSize = parseWorkers(workers);

    if (taskSize == 0 || workerSize == 0)
        return (printf("File error\n"), 1);

	//const for worker as 
	std::span<const sWorker> loadedWorker (workers.data(), workerSize);
    std::span<sTasks> loadedTasks (tasks.data(), taskSize);

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
