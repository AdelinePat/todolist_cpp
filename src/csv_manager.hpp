#ifndef __CSV_MANAGER__
#define __CSV_MANAGER__
#include "utils.hpp"
#include <fstream> //library for reading inside a file
#define FILE_PATH "./src/todo.csv"
#include <filesystem>

void create_file();
void add_into_todo_list(std::string_view user_entry);
void overwrite_todo_list(std::vector<Task> &tasks_list);
void get_todo_list(std::vector<Task> &tasks_list);

#endif