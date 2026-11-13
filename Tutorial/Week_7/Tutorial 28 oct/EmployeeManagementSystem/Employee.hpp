#pragma once
#include <iostream>

class Employee{
	public : 
		Employee() = default;
		~Employee() = default;

		//virtual keyword in C++ is to enable runtime polymorphism through late binding (dynamic linkage).
		virtual void calculateSalary(double basicSalary) //default constructor 
		{
			std::cout<< "Employee Salary : RM" << basicSalary << ::std::endl;
		}	
};