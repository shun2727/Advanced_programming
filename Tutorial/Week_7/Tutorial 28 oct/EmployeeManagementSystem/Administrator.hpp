#pragma once 

#include "Employee.hpp"
class Administrator : public Employee{
	public: 

		void calculateSalary(double basicSalary) override{
			double allowance = 500;
			std::cout << "Administrator Salary : RM" << basicSalary + allowance << std::endl;
		}
};