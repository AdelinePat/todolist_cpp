#include "utils.hpp"
std::vector<std::string> split_string(std::string& current_string) {
        std::vector<std::string> all_strings;
        size_t start = 0;
        size_t end = current_string.find(";");

        while (end != std::string::npos) {
            all_strings.push_back(current_string.substr(start, end-start));
            start = end+1;
            end = current_string.find(";", start);
        }
        all_strings.push_back(current_string.substr(start));
        return all_strings;
}