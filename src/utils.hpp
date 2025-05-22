
#ifndef __UTILS__
#define __UTILS__
#include <iostream>
#include <string>
#include <string_view>
#include <regex> //need to replace things inside user string I guess
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

std::vector<std::string> split_string(std::string & current_string);
void change_task_state(std::vector<Task>& tasks_list, int index);
void delete_task(std::vector<Task> &tasks_list, int index);
void displayTask(std::vector<Task> &tasks_list);
int displayMenu(int user_choice);

#endif
