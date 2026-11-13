Foundations III: Exceptions and Namespaces (Page 1)
Part A: Short Answer Questions
1. Explain the differences between syntax, runtime, and logic errors.
	- syntax error is when the grammer of the programm is wrong , for example it misses a semicolo
	- runtime errors happen when theprogram can be compiled free of syntax errors but theres an unexpected or abnormal termination of the program due to probelms like opening a file that doesnt exist or dereferencing a null pointer
	- logic errors i when it can compile and run BUT it doesnt run the way the programmer coded it to be due to the errors that they themselves made in terms of logic such as using the wrong symbols for comparison or in arthimethic equaitons
2. State four limitations of traditional error handling techniques.
	- so for traditional error handling its done by returning error codes or using if statements to check the error by printing out the wrong values, has to be determined manually by the programmer.
	- if its returning error codes the programmer can ignore them
	- there is limited informaiton about what the error stands for if the codes returns on exit are similar
3. Describe the purpose of try, throw, catch, and handle.
	- try encloses code that my cause en error and within that code block the program will check for any possile errors
	- throw will signal that an error has happenned
	- catch block is a block placed after try so that it matches the exceoption and will run the code (handle) corresponding to it
	```
	try {
		if (b == 0) throw std::runtime_error("Division by zero");
			result = a / b;
		}
		catch (const std::runtime_error& e) 
		{
			std::cout << e.what();   // handling
		}
	```
4. Differentiate between std::exception, std::logic_error, std::invalid_argument, std::out_of_range, and std::runtime_error.
- exception is the base type of exception or error
- logic error is derived from exception that catches logics that could be an issues
- invalid argument is when an invalid vlaue i placed inn a perameter such that itoa("abc"), where it expects an integer but receives an ascii
- out of range is when the value beig accesssed is not within the range of the cntianer such as accessing index 9 at an aray with 7 elements
- runtime error is Errors that can only be detected at runtime and are outside the program’s control (e.g., file or network failure).
5. What is stack unwinding?
- when fucntion a calls funciton b and funciton b calls function c but c runs into an issue which is an exception, but funciton c doesn tknow how to handle the exception and it stops to look at funciton b and and so on to funciton a , as the program steps out of funciton c then b it destroyes local variables and runs the clean up code the order they were created if it reaches a funciton with a matching block th eunwinding stops and the code resumes from there
6. Define scope and list four variable scopes discussed in the slides.
- local : within its own block {}
- funciton : within the funciton
- global :in the file itself
- namespace : declared in a namespace and accessed via namespase using
7. How do namespaces solve naming conflicts?
- A namespace groups identifiers under a unique name, so the same identifier can exist in different namespaces without clashing. The full name is qualified with the scope resolution operator.
```
namespace A { void print() { } }
namespace B { void print() { } }

A::print();   // calls A's version
B::print();   // calls B's versio
```

8. Differentiate between named and unnamed namespaces.
- named like namespace Math {}, has a name so it ccan be accessed form other files via math::var, it can be used to organize code and share this across different files
- unnamed namespaces us when there is just namespace{}, so it's mambers cannot be reffered to from other files

9. What is the purpose of a namespace alias?
- to create a shorter or ore convineinet name for a longer namespace which imrpoves readability . for example
```
namespace fs = std :: filesystem 
```
10. Explain the use of constexpr in namespaces.
constexpr declares variables or functions whose values are evaluated at compile time. Placing them inside a namespace groups compile-time constants and utilities under a clear name, avoiding global name clashes while giving zero runtime cost, type safety, and usability in contexts that need constant expressions (array sizes, template arguments).

Part B: Long Answer Questions
1. Discuss traditional error handling methods and explain why exceptions are preferred in Modern C++.
2. Using suitable examples, explain the C++ exception hierarchy and when each exception type should be used.
3. Describe the process of stack unwinding and explain its relationship with RAII.
4. Explain how namespaces support large-scale software development and library organization.
5. Compare named namespaces, unnamed namespaces, nested namespaces, and namespace aliases with examples.


Foundations IV and V: Defensive Programming and Time (Page 2)
Part A: Short Answer Questions
1. Define defensive programming.
2. List four differences between older C-style and Modern C++ defensive programming.
3. When should assert() be used?
4. When should assert() NOT be used?
5. What is a function precondition?
6. Compare std::time and std::clock.
7. Why is std::chrono preferred in Modern C++?
8. Differentiate between wall-clock time and CPU time.
9. State the purpose of std::this_thread::sleep_for().
10. Give two real-world uses of sleep_for().


Part B: Long Answer Questions
1. Compare older C-style defensive programming with Modern C++ defensive programming.
2. Explain the role of assertions in defensive programming and provide examples of appropriate and inappropriate use cases.
3. Compare std::time, std::clock, and std::chrono in terms of precision, purpose, and modern relevance.
4. Describe how  and  work together in Modern C++ applications.
5. Develop a discussion on how defensive programming techniques improve software reliability and maintainability.
Foundations IV and V: Pre-processing, Macros, Makefiles, Debuggers and Profilers (Page 3)

Part A: Short Answer Questions
1. What is a preprocessor directive?
2. State the purpose of #include.
3. What is conditional compilation?
4. What are header guards used for?
5. Compare #pragma once and traditional header guards.
6. Define an object-like macro and a function-like macro.
7. Why should macros be used sparingly in Modern C++?
8. State four purposes of a Makefile.
9. Differentiate between .cpp, .o, and executable files.
10. What is the role of a debugger and a profiler in software development?

Part B: Long Answer Questions
1. Explain the role of preprocessing in C++ and discuss the importance of conditional compilation.
2. Discuss the advantages and disadvantages of macros. Include Modern C++ alternatives.
3. Explain the complete compilation and build process from source files to executable program.
4. Using a suitable example, explain the structure and components of a Makefile.
5. Compare the roles of debuggers and profilers in improving software quality and performance.