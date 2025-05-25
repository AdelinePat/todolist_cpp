#include "CRUD.hpp"

void changeTaskState(std::vector<Task>& tasks_list, int index) {
    tasks_list[index].state ? tasks_list[index].state = 0 : tasks_list[index].state = 1;
}

void changeTask(std::vector<Task>& tasks_list, int index, void (*choice)(Task& task)) {
    choice(tasks_list[index]);
}

void deleteTaskFromVector(std::vector<Task>& tasks_list, int index) {
    if (index >= 0 && index < tasks_list.size()) {
        tasks_list.erase(tasks_list.begin() + index);
    } else {
        cerr<<"Problème d'index ?";
    }
}