#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <vector>
#include <string>

class CSVParser {
public:
    // Split a CSV line into fields and return them as a vector of strings
    static std::vector<std::string> splitCSVLine(const std::string& line, char delimiter = ',');

    // Format a vector of strings into a CSV line
    static std::string formatCSVLine(const std::vector<std::string>& fields, char delimiter = ',');
};

#endif
