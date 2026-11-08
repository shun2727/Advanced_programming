#include "MainData.hpp"

/**
 * @brief 
 * 
 * @param file_path 
 * @param arr 
 * @param count 
 * @param prototype 
 */
void MainData::loadFile(const std::string& file_path, std::unique_ptr<MainData> arr[], int& count, const MainData& prototype)
{
    int         	line_count {0};
    std::string 	line;
    std::ifstream 	file{file_path};

    if (!file)
        throw std::runtime_error{"Cannot open file: " + file_path};

    while (std::getline(file, line))
    {
        ++line_count;

        std::unique_ptr<MainData> r = prototype.create();
        try
        {
            r->parseLine(line);
            if (count >= MAX_SIZE)
                throw std::runtime_error{"Exceeded size for parsing"};

            if (findIndex(arr, count, r->getKey()) != -1)
                throw std::runtime_error{"duplicate " + r->getKey()};

            arr[count++] = std::move(r);
        }
        catch (const std::exception& e)
        {
            std::cerr << file_path << " line " << line_count << " skipped: " << e.what() << "\n";
        }
    }
}

/**
 * @brief 
 * 
 * @param arr 
 * @param count 
 */
void MainData::display(const std::unique_ptr<MainData> arr[], int count)
{
    if (count == 0)
    {
        std::cout << "record is empty \n";
        return;
    }

    for (int i = 0; i < count; ++i)
        arr[i]->display();              // virtual: runs Event / Participant / Registration version
}

/**
 * @brief 
 * 
 * @param arr 
 * @param count 
 * @param key 
 * @return int 
 */
int MainData::findIndex(const std::unique_ptr<MainData> arr[], int count, const std::string& key)
{
    for (int i = 0; i < count; ++i)
        if (arr[i]->getKey() == key)    // virtual: the ID for each type
            return i;

    return -1;
}