#ifndef __REDIRECTION_CHOICE__
#define __REDIRECTION_CHOICE__
#include "utils.hpp"
#include "sanitize_input.hpp"
#include "csv_manager.hpp"
#include "CRUD.hpp"

void redirectChoice(int user_choice, Task &task, std::vector<Task> &tasks_list);

void createTask(Task &task, std::vector<Task> &tasks_list);

void swapStatus(std::vector<Task> &tasks_list);

void modifyTask(int choice, std::vector<Task> &tasks_list);

void deleteTask(int choice, std::vector<Task> &tasks_list);

void askForDescription(Task &task);

void askForDate(Task &task);

#endif


