
1. A **selection statemet** structure allows a program to choose among alternative execution 
paths. (*)
2.  The statement used to execute a block of code only when a condition is true is 
**if (condition == true)**. 
3.  The Modern C++ feature introduced in C++17 that allows variable declaration inside an if 
statement is called **if initializers**. (*)
4.  The **switch**  statement is commonly used when selecting among multiple 
constant values. 
5.  A **while** loop checks its condition before executing the loop body. 
6.  A **do while** loop executes its body at least once before checking the condition. 
7.  The Modern C++ loop that directly iterates through elements of a container is called a 
**advanced for** loop. 
8.  The keyword **break** immediately terminates a loop. 
9.  The keyword **continue** skips the remainder of the current iteration. 
10. A **reference** is another name for an existing variable. (*)
11. A **pointer** stores the memory address of another variable. 
12. The Modern C++ container that has a fixed size known at compile time is **array**. 
13. The Modern C++ container that can grow and shrink dynamically is **vector**. 
14. Memory is dynamically allocated using the keyword **malloc** / **new**. 
15. Memory allocated dynamically is released using **free** / **delete**. 
16. A pointer that refers to memory that has already been released is called a **dangling pointer**
pointer. 
17. Modern C++ uses **smart** pointers to manage memory automatically. (*)

Section B: Explain the differences between 
1.  A reference and a pointer 
	Ans : a reference denoted by & contains the address of a value wheres a pointer donoted by * points to a reference. the size of a & and * are both 8 bytes. 
	Pointers can be initialized later on whreas references have to initialized upon run time.
2.  The std::array and std::vector 
	Ans : array is initialize upon compiling with a known fixed size, whereas vector is dynamically allocatted by the user during run time and requires new to be initialized and delete to free up memory to avoid memory leaks.
3.  Passing an argument by value and passing an argument by reference 
	Ans : passing an argument by value to a function passes the value from the variable , passing an argument by reference passes the variable that holds the value to the funciton. By passing by value any changes made to the value wihtin th efunciton does not change the original variable because it is modifying the local variable wheres passinf by reference modifies it because it is directly manipulating the value located in the same memory as the passed variable. 


Getting organised I – Structure within Structure, Functions  
Section B : Fill in the blanks  
1.  **RAII(Resrouce Acquisition is Initialization)**  is  a  C++  design  principle  that  acquires  resources  in  a constructor and releases them in a destructor. 
2.  A **abstact data type (ADT)** is a data type defined by its operations and behaviour rather than its implementation details. 
3.  A **abstract data type** is a data type defined by its operations and behaviour rather than its implementation details. 
4.  A **union** allows multiple members to share the same memory location. 
5.  A **enum** is a user-defined type that represents a set of named 
constants. 
6.  The Modern C++ alternative to traditional enum is **enum class**. 
7.  **typdef** creates an alias or nickname for an existing type. 
8.  The Modern C++ alternative to typedef is **using**. 
9.  **std::randome_device** generates a seed value for random number generation. 
10. **std::mt19937 (Mersenne Twister)** is a pseudo-random number generator commonly used in 
Modern C++. 
11. **ifstream** is used to read data from a file. 
12. **ofstream** is used to write data to a file. 
13. **fstream** is used for both reading and writing files. 
14. **cerr** is used to report error messages to the standard error stream. 
15. **getline** reads an entire line of text, including spaces. 
16. The Modern C++ replacement for rand() and srand() is the **random** library. 
17. The Modern C++ replacement for a traditional union is **std::varaint**. (*)
18. The Modern C++ replacement for manual memory management using new and delete is 
**smart pointers**. 
19. The destructor of an object is automatically called when the object goes out of 
**scope**. 
20. In a structure, members are **public** by default


Getting organised II: File Handling 
LAQ 1 : Write a program that creates a file named student.txt and stores the following information: 
Name: Ali 
Id: 1001 
GPA: 3.85 

```c++
#include <fstream>

int main()
{
	std::ofstream student("student.txt");
	student << "Name: Ali \n";
	student << "Id: 1001\n";
	student << "GPA: 3.85\n";

	student.close();
	return (0);
}
```
 
LAQ 2 : Write a program that reads the data from product.txt and displays in the sample output as 
shown: 
Product Id: P001 
Product Description: Cupboard 
Price RM100 
Assume there are rows of data stored in product.txt

```c++
#include <fstream>

int main()
{
	std::ifstream product("prouct.txt");
	std::string s;

	while (getline(product, s))
		cout << s;

	product.close();
	return (0);
}
```