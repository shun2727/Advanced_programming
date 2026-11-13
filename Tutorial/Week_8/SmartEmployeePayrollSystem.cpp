#include <iostream>

class Employee
{
	int id;
	std::string name;
	int hourlyRate_;

	//try catch throw exception 
	public :
		Employee();

		//i dont think initilzer list is a good fit here considering it wants to detect errors
		Employee(int id, std::string name, int hourlyRate) :id(id), name(name)
		{
			try 
			{
				hourlyRate_ = hourlyRate;
				if (hourlyRate_ < 0)
					throw (hourlyRate_);
			}
			catch (int hourlyRate)
			{
				std::cout << "invalid hourly rate \n";
			}
		}

		void displayInformation()
		{
			std::cout << "Employee ID : " << id << std::endl;
			std::cout << "Employee Name: " << name << std::endl;
			std::cout << "Employee Hourly Rate : " << hourlyRate_ << std::endl;
		}


};

