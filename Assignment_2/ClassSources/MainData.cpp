#include "MainData.hpp"

/**
 * @brief Opens file and stores into the array declared in Data_s struct
 * 
 * Note : 
 * The logic for opening and reading files are the same across all the files. 
 * However, each file have different number of fields and data types.
 * The caller passes a temporary Event{}, Participant{} or Registration{} (allowed because they publicly inherit MainData). It only decides which type is built.
 * After each line is fed from the file for every line, makeUniquePointer() returns a new blank object on the heap.
 * Then parseLine() from each object type is called to fill up the object
 * Using move, it passes the contents from filled_object into the array.
 * 
 * @param file_path 
 * @param arr 
 * @param count 
 * @param object - Event{}, Participant{} and Registration{} object. Possible due to public inheritance by these subclasses
 */
void MainData::loadFile(const std::string& file_path, std::unique_ptr<MainData> arr[], int& count, const MainData& object)
{
    int         	line_count {0};
    std::string 	line;
    std::ifstream 	file{file_path};

    if (!file)
        throw std::runtime_error{"Cannot open file: " + file_path};

    while (std::getline(file, line))
    {
        ++line_count;
		
		/*
			Creates a unique pointer of the object 
			Essentially creates a new object (allocated on the heap) everytime based on the object type passed into the parameter
			makeUniquePointer() virtual funciton will call the appropraite display based on the class object
		*/ 
        std::unique_ptr<MainData> filled_object = object.makeUniquePointer();
        try
        {
            filled_object->parseLine(line);

			// Extra error handling if the array is not big enough to accomodate the data
            if (count >= MAX_SIZE)
                throw std::runtime_error{"Exceeded size for parsing"};
			

			//if it returns -1 then theres no duplicate, if it returns and index then theres a duplicate of the key value pair
            if (getIndexFromKey(arr, count, filled_object->getKey()) != -1)
                throw std::runtime_error{"duplicate " + filled_object->getKey()};

            arr[count++] = std::move(filled_object);
        }
        catch (const std::exception& e)
        {
			// Use error output instead of the typical cout
            std::cerr << file_path << " line " << line_count << " skipped: " << e.what() << "\n";
        }
    }
}

/**
 * @brief displays the contents based on each object's own display() member functions
 * 
 * @param arr - pointing towards the data array in Data_s struct
 * @param count - rows of informaiton to be displayed
 */
void MainData::display(const std::unique_ptr<MainData> arr[], int count)
{
	// Error guard
    if (count == 0)
    {
        std::cout << "record is empty \n";
        return;
    }
	//arr[0]->display_header();
	/*
		display() virtual funciton will call the appropraite display based on the class object
	*/
    for (int i = 0; i < count; ++i)
        arr[i]->display();
}

/**
 * @brief Used for getting the array index for the corresponding key
 * 
 * @param arr 
 * @param count - size of arr / or the position the caller wants it ot stop at 
 * @param key - the code depending on the object specifically for participant and events where its E001 and P001
 * @return int 
 */
int MainData::getIndexFromKey(const std::unique_ptr<MainData> arr[], int count, const std::string& key)
{
    for (int i = 0; i < count; ++i)
	{
		if (arr[i]->getKey() == key)
			return i;
	}
    return (-1);
}

/**
 * @brief used in add a value to an array using std::move and using getIndexFromKey() to get the key value pair for dupllicate checking
 * 
 * @param arr 
 * @param count 
 * @param record 
 */
void MainData::addArrEntry(std::unique_ptr<MainData> arr[], int& count, std::unique_ptr<MainData> object)
{
	/*
		getKey() virtual funciton will call based on the class object to get the keyvalue
	*/
	//checks for duplicates
    if (getIndexFromKey(arr, count, object->getKey()) != -1)
        throw std::runtime_error{"duplicate entry"};

	//checks if the array cannot accomodate for more data
    if (count >= MAX_SIZE)
        throw std::runtime_error{"Exceeded maximum record count"};

    arr[count++] = std::move(object);
}

/**
 * @brief Removes the record at the given index and shifts later records down to close the gap. Used in validate data
 * 
 * @param arr   - Arr to remove from
 * @param count - Num of records in arr
 * @param index - Position to remove
 */
void MainData::removeEntry(std::unique_ptr<MainData> arr[], int& count, int index)
{
    if (index < 0 || index >= count)
        throw std::out_of_range{"Record index is out of range"};

    for (int i = index; i < count - 1; ++i)
        arr[i] = std::move(arr[i + 1]);

    arr[--count].reset();
}