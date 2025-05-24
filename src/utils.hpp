
#ifndef __UTILS__
#define __UTILS__
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::cerr;
struct Task {
    std::string description{""};
    std::string deadline{""};
    std::string final_string{""};
    int state{0};
};

std::vector<std::string> splitString(std::string &current_string);


#endif
