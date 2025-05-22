#ifndef __CSV_MANAGER__
#define __CSV_MANAGER__
#include "utils.hpp"
#include <fstream> //library for reading inside a file
#define FILE_PATH "./src/todo.csv"
#include <filesystem>



using std::cout;
using std::cin;
using std::endl;
using std::cerr;

void create_file();
void write_in_todo_list(std::string_view user_entry);
void get_todo_list(std::vector<Task> &tasks_list);

#endif