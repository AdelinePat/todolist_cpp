#ifndef __CRUD__
#define __CRUD__
#include "utils.hpp"
#include "sanitize_input.hpp"

void changeTaskState(std::vector<Task> &tasks_list, int index);

void changeTask(std::vector<Task> &tasks_list, int index, int choice);

void deleteTaskFromVector(std::vector<Task> &tasks_list, int index);

#endif
