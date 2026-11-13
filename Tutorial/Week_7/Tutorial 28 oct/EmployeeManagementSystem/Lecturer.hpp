#pragma once
#include "Employee.hpp"

//defined as public here so that
class Lecturer : public Employee{
	public : 
	//override is written here so that 
	//void calculateSalary(const double& basicSalary) const override; //comst after () promises the funciton wont change the object memebr data 
		void calculateSalary (double basicSalary) override {
			double allowance = 1000;
			std::cout << "Lecturer Salary : RM " << basicSalary + allowance << std::endl;
		}
};

