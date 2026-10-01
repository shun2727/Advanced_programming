#include <iostream>
//only works for c++ 17 and above 

int main()
{
	// if (int val{}; val > 5)
	// {
	// 	std:: cout << "Greater than";
	// }
	// else
	// 	std:: cout << "Not greater than";

	// int value{100};
	// int *vPtr{&value};

	// std::cout<<value<<"\n";
	// std::cout<<*vPtr<<"\n";
	// std::cout<<&value<<"\n";
	// std::cout<<vPtr<<"\n";

	/*
	In languages like C and C++, the compiler actually does not care where you put the asterisk. Whitespace is ignored.
	 All three of these lines mean the exact same thing to the computer:
	 double* ptr; (Preferred in C++ — emphasizes that the type is "pointer to double")
	 double *ptr; (Preferred in C — emphasizes that dereferencing *ptr gives you a double)
	 double * ptr; (Less common, but perfectly valid)
	*/
	double value;
	int a;
	char w = 'a';
	std ::cout << sizeof(value) << sizeof(double) << sizeof(double*);
	std ::cout << sizeof(a) << sizeof(int) << sizeof(int*);
	std ::cout << sizeof(w) << sizeof(char) << sizeof(char*);
}