#include <iostream>

//using modern cpp programming 
/*
	notes on pointers :

	usually its :
	int a = 1; / int a{1};
	int *x = &a; / int *x{&a};
	so that *x = 4, modifies value

	but now ;
	int a{1};
	int &x{a}; 
	so when x = 5, modifies value

*/
void Task1()
{
	int arr[3]{1,2,3}; //brace initializaiton 

	// rather than using for (int i ...)
	//2. display values inside the array
	for (auto arr_value : arr)
		std::cout << " " << arr_value;

	std::cout << '\n';
	//3. use enhanced for loop to read and store values back to the array
	for (auto &arr_value : arr) //foreach value inside arr, when & is used its already call by reference
	{
		std :: cout << "input val 1: ";
		std::cin >> arr_value;
	}

	//4. display new values in the array
	for (auto arr_value : arr)
		std::cout << " " << arr_value;
	std::cout << '\n';
}
void Task2()
{
	int arr[3]{1,2,3}; //brace initializaiton 

	for (auto arr_value : arr)
		std::cout << " " << arr_value;

	std::cout << '\n';
	for (auto &arr_value : arr) //foreach value inside arr
		arr_value = 999;

	for (auto arr_value : arr)
		std::cout << " " << arr_value;
	std::cout << '\n';
}

void Task3()
{

}
struct Address{
	std::string hseNO, block, condoName;
};



void Task4(void) //includes contetn for task 4 to task 6
{
	struct Person{
		int pId, pAge;
		std::string pName;
		Address add;
	};
	Person jane; 
	jane.pId = 1;
	jane.pAge = 22;
	jane.add.hseNO = "24";
	jane.add.block = "KC206";
	jane.add.condoName = "Kanta";

}

int main(void)
{
	Task1();
	Task2();
	Task3(); //ignore for now
	Task4();

}