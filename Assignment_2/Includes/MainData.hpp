#pragma once

#include <fstream> // std::ifstream
#include <iostream> // std::cout, std::cerr
#include <memory> // std::unique_ptr
#include <string> // std::string, std::getline
#include <stdexcept> // std::runtime_error, std::out_of_range
#include <utility> // std::move

/**
 * @brief this acts as an abstract class so that the derived / child classes have a blueprint
 * 
 */
class MainData{

	
	public :
		static const int MAX_SIZE = 50;

		static void loadFile(const std::string& file_path, std::unique_ptr<MainData> arr[], int& count, const MainData& object);
    	static void display(const std::unique_ptr<MainData> arr[], int count);
    	static int  getIndexFromKey(const std::unique_ptr<MainData> arr[], int count, const std::string& key);
		static void addArrEntry(std::unique_ptr<MainData> arr[], int& count, std::unique_ptr<MainData> record);
		static void removeEntry(std::unique_ptr<MainData> arr[], int& count, int index);

	    virtual void parseLine(const std::string& line) = 0;
    	virtual void display() const = 0;
    	virtual std::string getKey() const = 0;
    	virtual std::unique_ptr<MainData> makeUniquePointer() const = 0;
};
