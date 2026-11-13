
#include "Book.hpp"
#include "EBook.hpp"
#include <iostream>

int main()
{
	// Create one Book object using the default constructor
	Book book1;

	// Use write accessors (setters) to assign values 
	book1.setBookId(101);
	book1.setTitle("banana");

	// Use read accessors (getters) to retrieve and display values
	std::cout << "Book ID : " << book1.getBookId() << std::endl;
	std::cout << "Title : " << book1.getTitle() << std::endl;


	// Create two EBook objects using overloaded constructors
	EBook ebook1(67, "aaaa", 15, "PDF");
	EBook ebook2(911, "bbb", 20, "A");


	// Use displayEBook() to display details of both EBook objects
	ebook1.displayEBook();
	ebook2.displayEBook();

	return 0;
}
