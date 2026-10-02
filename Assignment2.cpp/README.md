_This project is made by 0135347 yee shun qi for the advanced programming course within UOW_

# Task Assignment System
## Objective

Files Tasks.txt and Workers.txt are provided with a specific format delmited by different symbols. 

**Format for Tasks.txt :**
```text
TaskId,description;uncertainty$difficulty%priorityLabel&workers:list of worker IDs 

1,image processing;6$10%1&workers:7,0,8
```

**Format for Workers.txt :**
```text
workerId,name%variability$ability;experienceLabel

0,Michael%-2$50;1
```
Calculate the average performance of each worker, and the output of the program will be the worker with the highest performance.

## Structure
### Part A
---
This following section breaks down the requirements of the project : 

- Open file
	- Read file (Workers.txt, Tasks.txt)
	- Parse input (check by delimiters)
	- Store infromation (array / list)

Within a loop : 
- Calculate mean of **worker performance** for each worker (the mean value within the normal distribution)
	-  Calculate perfromance score = worker ability - task difficuly (perfromance score logic : the greater the ability of the worker, the less the task diffuculty affects them, which gives them a better performance score)
	- Calculate standard deviation = | task uncertainty + worker variability (worker variability : what is the performance of the worker from time to time) |

- Calculate **average performance** for each worker :
		- Use 10 random draws for low-priority tasks and 15 for high-priority tasks.
		- Add 2 points to the average for senior workers and 0 for ordinary workers.
	- Store the output for each workers

- Find the worker with the best performance
	- print the output with the performance value of all workers 

### Part B 
---
Incoperating modern C++ features :
- inline declaration (but not necessary applicable)
- special pointers
- auto
- library funcitons for arrays / containers (no vectors allowed)
- (do extra for modern c++)

### Files
--- 

### Complilation guide 
---
To avaoid warning compile with the following std flags
```bash
	g++ -std=c++20 Assignment1.cpp
```


## Resources
---
Read file :
	- https://www.geeksforgeeks.org/cpp/file-handling-c-classes/
	- https://en.cppreference.com/cpp/io/basic_ifstream
Getline :
	- getline (file / stdin for the funciton, buffer, delimiter);
	- https://www.geeksforgeeks.org/cpp/getline-string-c/
	- https://en.cppreference.com/cpp/string/basic_string/getline
Stringstream :
	- https://www.geeksforgeeks.org/cpp/stringstream-c-applications/
stoi :
	- https://www.geeksforgeeks.org/cpp/convert-string-to-int-in-cpp/

Math funcitons within findBestWorker :
normal distribution :
	- https://en.cppreference.com/cpp/numeric/random/normal_distribution
random number generator : 
	- essentially asks the system for randome numbers every time 
	- https://en.cppreference.com/cpp/numeric/random/random_device

General lookup on how to solve:
	- https://stackoverflow.com/questions/60721093/random-number-from-normal-distribution-in-c


span : 
	- https://en.cppreference.com/cpp/container/span
	