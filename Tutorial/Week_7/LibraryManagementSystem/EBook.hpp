#pragma once
#include "Book.hpp"
#include <iostream>

class EBook : public Book
{
	double fileSize;
	std::string format;

public:

	EBook() //default constructor
	{

	}

	EBook(int bookId, std::string title, double fileSize, std::string format)
		: Book(bookId, title), fileSize(fileSize), format(format) //overloaded constructor
	{

	}

	//write accessors (mutators) are setters
	void setFileSize(double size)
	{
		fileSize = size;
	}

	void setFormat(std::string bookFormat)
	{
		format = bookFormat;
	}

	//read accessors (accessors) are getters
	double getFileSize() const
	{
		return fileSize;
	}

	std::string getFormat() const
	{
		return format;
	}

	//display function
	void displayEBook()
	{
		Book::displayBook();

		std::cout << "file size : " << fileSize << std::endl;
		std::cout << "format : " << format << std::endl;
	}
};
