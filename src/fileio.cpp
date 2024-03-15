#include "fileio.h"

#include <fstream>

// Read in a file and return a vector of strings
// inputLocation refers to the path to the file that will be read
// data refers to the vector that will store the lines

bool getData(const std::string& inputLocation, std::vector<std::string>& data)
{
    std::ifstream fileInput(inputLocation); // Opens the file for reading
    // Condition to check if the file was opened
    if (!fileInput.is_open()) {
        return false;
    }

    std::string line;
    while (fileInput.eof() != true) {  // It will read each line until end of file
        std::getline(fileInput, line);
        data.push_back(line);         // Store the lines read in the vector 'data'
    }
    fileInput.close();                // Close the file after reading the lines
    return true;
}

// Output the vector of strings to the file
// outputLocation refers to the path where the data will be written
// data refers to the vector that stores the lines

bool putData(const std::string& outputLocation, const std::vector<std::string>& data)
{
    std::ofstream fileOutput(outputLocation); // Opens the file for writing
    // Condition to check if the file was opened
    if (!fileOutput.is_open()) {
        return false;
    }

    for (int i = 0; i < data.size(); i++) {  // Writes each line from vector 'data' to the file
        fileOutput << data[i] << std::endl;
    }
    fileOutput.close();                     // Close the file after reading the lines
    return true;
}