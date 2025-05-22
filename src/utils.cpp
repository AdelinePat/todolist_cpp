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

void change_task_state(std::vector<Task>& tasks_list, int index) {
    tasks_list[index].state ? tasks_list[index].state = 0 : tasks_list[index].state = 1;
    // task->state ? 0 : 1;
    // if (tasks_list[index].state == 0) {
    //     tasks_list[index].state = 1;
    // } else {
    //     tasks_list[index].state = 0;
    // }
}

void delete_task(std::vector<Task>& tasks_list, int index) {
    if (index >= 0 && index < tasks_list.size()) {
        tasks_list.erase(tasks_list.begin() + index);
    } else {
        cerr<<"Problème d'index ?";
    }
}

void displayTask(std::vector<Task>& tasks_list) {
    for (int index{0}; index<tasks_list.size(); index++) {
        cout<<"# # # # "<<"Tâche n°"<<index+1<<" # # # #"<<endl;
        cout<<tasks_list[index].description<<endl;
        cout<<tasks_list[index].deadline<<endl;
        cout<<"Etat : "<<(tasks_list[index].state ? "Terminée" : "En cours")<<endl<<endl;
    }
}

int displayMenu(int user_choice) {
    cout<<"####################################"<<endl;
    cout<<"0. Quitter\n"<<
    "1. Créer une nouvelle tâche\n"<<
    "2. Marquer une tâche comme terminée\n"<<
    "3. Modifier une tâche\n"<<
    "4. Supprimer une tâche\n";
    cout<<"Votre choix : ";
    cin>>user_choice;
    cout<<"\n";
    return user_choice;
}