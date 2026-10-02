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
- Calculate mean of **worker performance** for each task (there are multiple workers per task, therefore calculated for each) (the mean value within the normal distribution)
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
Following are the modifications I made to incorporate modern C++ features (c++ 11 and later):

1. Brace initialization:
	- `tasks{}` and `workers{}` initialize the arrays to default values (numbers start at 0 and strings start empty).
	- This feature was introduced in C++11.

2. Usage of `auto` and reference calls in function parameters:
	- Functions such as `parseTask(auto& tasksArr)` use abbreviated function templates. The compiler deduces the array type, so I do not need to write the full template declaration for each function.
	- Passing arrays by reference avoids copying the whole array when calling these functions.
	- Using `auto` in function parameters was introduced in C++20.

3. Usage of `std::array`:
	- The tasks and workers are stored in `std::array` instead of C-style arrays.
	- `std::array` was introduced in C++11.

4. Usage of `template <typename T>` for extracting delimited text:
	- Rather than writing a separate function for each data type after parsing (especially for integers), I created the function `readValue()`.
	- The function accepts a delimited value from the file, converts it to the type requested at the call site (string, char or int), and returns it.
	- Function templates have been part of C++ since C++98 , not exactly modern c++ but its generic programing and worth mentioning

5. Inclusion of `std::span`:
	- Most of the code can be run using a for loop, but for the sake of tidiness and interest in learning a new type of container, span is included.
	- Based on research, it only stores a pointer to the original container and a length, and does not require its own separate memory, so no additional overhead is added to the program.
	- It replaced several for loops, including the ones in `main` and in the debug functions. In doing so I am able to demonstrate modern C++ capabilities by introducing the range-based for loop.
	- This feature was introduced in C++20.

6. Range-based `for` loops, using reference `&` when modification of the value is needed:
	- The main loop iterates over `loadedTasks`, and the debug functions use range-based loops to process the tasks and workers they receive.
	- In `debugTasks`, a span limits the range of candidate worker IDs to each task's `workerCount`.
	- Range-based for loops were introduced in C++11.

### Files
--- 
1. driver.cpp : contains the main functions and the ovarall logic for the program
2. debugger.cpp : showing the values after parsing was not specified by the assignment requirements, therefore i seperated it into another file
3. header.hpp : contains the struct and libraries needed for the program
4. README.md : current file with overview of the entire project

### Complilation guide 
---
To avoid warning compile with the following std flags, then output to `task_assignment` as the program name
```bash
	g++ -std=c++20 driver.cpp -o task_assignment
```
ensure `Workers.txt` and `Tasks.txt` are located in the same folder, then run with
``` bash
	./task_assignment
```

## Resources
1. Read file :
	- https://www.geeksforgeeks.org/cpp/file-handling-c-classes/
	- https://en.cppreference.com/cpp/io/basic_ifstream

2. Getline :
	- getline (file / stdin for the funciton, buffer, delimiter);
	- https://www.geeksforgeeks.org/cpp/getline-string-c/
	- https://en.cppreference.com/cpp/string/basic_string/getline

3. Stringstream :
	- https://www.geeksforgeeks.org/cpp/stringstream-c-applications/

4. stoi :
	- https://www.geeksforgeeks.org/cpp/convert-string-to-int-in-cpp/

Math funcitons within findBestWorker :
1. normal distribution :
	- https://en.cppreference.com/cpp/numeric/random/normal_distribution
	
2. random number generator : 
	- essentially asks the system for randome numbers every time 
	- https://en.cppreference.com/cpp/numeric/random/random_device

3. General lookup on how to solve getting random values form the normal distribution:
	- https://stackoverflow.com/questions/60721093/random-number-from-normal-distribution-in-c

4. span : 
	- https://en.cppreference.com/cpp/container/span
	- https://stackoverflow.com/questions/45723819/what-is-a-span-and-when-should-i-use-one

## AI usage
These resources alone were not sufficient for me to fully grasp the concepts such a when it came to how the normal distribution and random number functions works beneath, how do i utilize span and the usage of stringstream. 

Therefore AI was used to give more compreensive examples, to break down concepts and to provide guidance on implementation. All code was written myself, with exceptions that some were references from forums and learning websites. 