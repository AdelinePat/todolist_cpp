#ifndef __CSV_MANAGER__
#define __CSV_MANAGER__
#include "utils.hpp"
#include <fstream> //library for reading inside a file
#define FILE_PATH "./src/todo.csv"
#include <filesystem>

void createFile();
void addIntoTodoList(std::string_view user_entry);
void OverwriteTodoList(std::vector<Task> &tasks_list);
void getTodoList(std::vector<Task> &tasks_list);

#endif