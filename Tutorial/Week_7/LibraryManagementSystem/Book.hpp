#pragma once
#include <iostream>

class Book{

	int bookId;
	std::string title;

	Book() //default constructor
	{

	}

	Book (int bookId, std::string title) : bookId(bookId), title(title)//overloaded constructor
	{

	}

	//write accessors (mutators) are setters
	void setBookId(int id)
    {
        bookId = id;
    }

    void setTitle(std::string bookTitle)
    {
        title = bookTitle;
    }
	
	//read accessors (mutators) are getters
	int getBookId() const
    {
        return bookId;
    }

    std::string getTitle() const
    {
        return title;
    }
	

	void diplayBook()
	{
		std::cout<< "title : " << title <<std::endl;
		std::cout<< "boo id : " << bookId <<std::endl;

	}
};