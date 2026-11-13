#include <iostream>
#include <memory>
#include "Administrator.hpp"
#include "Employee.hpp"
#include "Lecturer.hpp"

int main()
{
	//dynamically allocated lecturer (modern c++)
	std::unique_ptr<Employee> emp1 = std::make_unique<Lecturer>();
	std::unique_ptr<Employee> emp2 = std::make_unique<Administrator>();

	emp1->calculateSalary(4000);
	emp2->calculateSalary(4000);

	return (0);
}