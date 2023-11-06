#include "CSVParser.h"
#include <sstream>

// Split a CSV line into fields and return them as a vector of strings
std::vector<std::string> CSVParser::splitCSVLine(const std::string& line, char delimiter) {
    std::vector<std::string> fields;
    std::istringstream ss(line);
    std::string field;

    while (std::getline(ss, field, delimiter)) {
        fields.push_back(field);
    }

    return fields;
}

// Format a vector of strings into a CSV line
std::string CSVParser::formatCSVLine(const std::vector<std::string>& fields, char delimiter) {
    std::string csvLine;

    for (size_t i = 0; i < fields.size(); ++i) {
        csvLine += fields[i];
        if (i < fields.size() - 1) {
            csvLine += delimiter;
        }
    }

    return csvLine;
}
