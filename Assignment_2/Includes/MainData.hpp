#pragma once

#include <fstream> // std::ifstream, std::getline
#include <iostream> // std::cout, std::cerr
#include <memory> // std::unique_ptr
#include <stdexcept> // std::runtime_error, std::out_of_range
#include <string> // std::string
#include <utility> // std::move

/**
 * @brief this acts as an abstract class so that the derived / child classes have a blueprint
 * 
 */
class MainData{

	
	public :
		static const int MAX_SIZE = 50;	

		virtual ~MainData() = default; 

		static void loadFile(const std::string& file_path, std::unique_ptr<MainData> arr[], int& count, const MainData& object);
    	static void display(const std::unique_ptr<MainData> arr[], int count);
    	static int  getIndexFromKey(const std::unique_ptr<MainData> arr[], int count, const std::string& key);
		static void addRegistraionEntry(std::unique_ptr<MainData> arr[], int& count, std::unique_ptr<MainData> record);
		static void removeEntry(std::unique_ptr<MainData> arr[], int& count, int index);

		/*
			inherited classes need to have these functions
		*/
		virtual void printHeader() const = 0;
	    virtual void parseLine(const std::string& line) = 0;
    	virtual void display() const = 0;
    	virtual std::string getKey() const = 0;
    	virtual std::unique_ptr<MainData> makeUniquePointer() const = 0;
};
