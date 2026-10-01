/*
1. Diff between 
	a. procedural language
	Ans :
	- Procedural language is code written with focus on steps and instructions
	- The main building block are funcitons.
	- In terms of reusability, function are often reused.
	
	b. oop language
	Ans : 
	- oop language is the focus on the entity and the procedures tied to the entity. 
	- The main building blocks are classes and objects. 
	- Typically used for Medium and large systems. 

2. Diff between 
	a. procedural language
	Ans : 
	- Procedural language is code written with focus on steps and instructions
	- The main building block are funcitons.
	- In terms of reusability, function are often reused.


	b. generic language
	Ans :
	- Typically used in libraries and frameworks. 
	- In terms of reusability , type safe codes are reused. (type safe is
	 code of different datatypes can be used onto the same funciton/block of code
	 which prevents conflicitng data types)


	Code example:
	a. procedural language
		double calculateArea(double radius)
		{
			return (3.142 * radius * radius)
		}
	b. generic language
		template <template T>
		T template(T a, T b)
		{
			return (a > b ? a: b)
		}
	c. oop language 
		class Circle
		{
			public :
				double area() const;
		}

	The codes below are in procedural C++.  
	a.  Modify it to reflect procedural C. 
	b.  Modify the original codes in other versions of C++. Suggest and use other methods of 
	passing an array to the function. 
	c.  Modify the original codes to reflect generic programming. 


	#include <iostream>
	using namespace std;

	const int SIZE = 5;

	void display (int arr[])
	{
		cout << "Vlalues in the array" << endl;
		for (int i = 0; i  < SIZE ; i)
			cout << arr[i] << "\t";
	}
	void readInput(int a[])
	{
		for(int i = 0; i < SIZE; i++)
		{
			cout<< "Enter value for element" << i i + 1 << ";"
			cin >> a[i];
		}
	}

	int main()
	{
		int arr[SIZE] = {0};
		readinput(arr);
		display(arr);

	}
*/

/*
	a. modify to reflect procedural C
	#include <stdio.h>

	const int SIZE = 5;

	void display (int arr[])
	{
		printf("Valies in the array \n");
		for (int i = 0; i  < SIZE ; i)
			printf("%d \t", i);
	}

	void readInput(int a[])
	{
		for(int i = 0; i < SIZE; i++)
		{
			printf("Enter value for element %d ;", i + 1 );
			scanf(%d, a[i]);
		}
	}

	int main()
	{
		int arr[SIZE] = {0};
		readinput(arr);
		display(arr);
	}

*/

/*
	b.  Modify the original codes in other versions of C++. Suggest and use other methods of 
	passing an array to the function. (using modern c++)

	#include <iostream>
	#include <array>

	const int SIZE = 5;
	//dont want to modify the array therefore use const
	void display (const std::arr<int, SIZE> &arr) //&arr cus its a reference to the array passed in (rather than doing *arr and dereferencing it)
	{
		cout << "Vlalues in the array" << endl;
		for (auto &arr_val : arr)
			cout << arr_val << "\t";
	}
	void readInput(std::arr<int, SIZE> &arr)
	{
		for(auto &arr_item : a)
		{
			cout<< "Enter value for element" << i i + 1 << ";"
			cin >> arr_item;
		}
	}

	int main()
	{
		//replaced array with std::arr
		std::array<int,SIZE> arr{};
		readinput(arr);
		display(arr);

	}

*/

/*
	c.  Modify the original codes to reflect generic programming. 
	#include <iostream>
	#include <array>

	template <typename T, std::size_t N>
	void display(const std::array<T, N>& arr)
	{
		std::cout << "Values in the array:\n";

		for (const auto& value : arr)
		{
			std::cout << value << '\t';
		}

		std::cout << '\n';
	}

	template <typename T, std::size_t N>
	void readInput(std::array<T, N>& arr)
	{
		for (auto& value : arr)
		{
			std::cout << "Enter value: ";
			std::cin >> value;
		}
	}

	int main()
	{
		std::array<int, 5> arr{};

		readInput(arr);
		display(arr);

		return 0;
	}
*/