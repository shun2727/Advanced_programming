//1. getter funciton
void getStudent()
{
	return(studentID_);
};

//2. initilizer list
Product(int id) : productid_(id)
{

}

//3. arameterized constructor for a class named Product that uses a constructor initializer list to initialize the following private data members: 
Product(int id, const std::string& name): productid_(id), name_(name)
{

}