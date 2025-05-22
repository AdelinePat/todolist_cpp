
#ifndef __UTILS__
#define __UTILS__
#include <iostream>
#include <string>
#include <string_view>
#include <regex> //need to replace things inside user string I guess
#include <vector>
struct Task {
    std::string description{""};
    std::string deadline{""};
    std::string final_string{""};
    int state{0};
};

std::vector<std::string> split_string(std::string & current_string);

#endif
