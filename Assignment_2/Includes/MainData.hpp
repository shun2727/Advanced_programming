#pragma once

#include <fstream> //ifstream
#include <iostream>
#include <memory>

/**
 * @brief this acts as an abstract class so that the derived / child classes have a blueprint
 * 
 */
class MainData{

	private :

		
	public :
		static const int MAX_SIZE = 59;

		static void loadFile(const std::string& file_path, std::unique_ptr<MainData> arr[], int& count, const MainData& prototype);
    	static void display(const std::unique_ptr<MainData> arr[], int count);
    	static int  findIndex(const std::unique_ptr<MainData> arr[], int count, const std::string& key);

	    virtual void parseLine(const std::string& line) = 0;
    	virtual void display() const = 0;
    	virtual std::string getKey() const = 0;
    	virtual std::unique_ptr<MainData> create() const = 0;
};
