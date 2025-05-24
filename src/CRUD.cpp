#include "CRUD.hpp"

void changeTaskState(std::vector<Task>& tasks_list, int index) {
    tasks_list[index].state ? tasks_list[index].state = 0 : tasks_list[index].state = 1;
}

// Use a function pointer for this ?? Could be a good exercise
void changeTask(std::vector<Task>& tasks_list, int index, int choice) {
    switch (choice) {
        case 0:
            cout<<"Contenu à modifier : "<<endl;
            cout<<tasks_list[index].description<<endl;
            std::getline(cin>>std::ws, tasks_list[index].description);
            CleanDescriptionTask(tasks_list[index].description);
            cout<<"Nouvelle description est bien prise en compte"<<endl;
            break;
        case 1:
            cout<<"Contenu à modifier (date à mettre au format JJ/MM/AAAA) : "<<endl;
            cout<<tasks_list[index].deadline<<endl;
            std::getline(cin>>std::ws, tasks_list[index].deadline);
            checkDateInput(tasks_list[index].deadline);
            cout<<"Nouvelle date butoir est bien prise en compte"<<endl;
            break;
        default:
            cout<<"cette commande n'est pas reconnue"<<endl;
    }            
}

void deleteTaskFromVector(std::vector<Task>& tasks_list, int index) {
    if (index >= 0 && index < tasks_list.size()) {
        tasks_list.erase(tasks_list.begin() + index);
    } else {
        cerr<<"Problème d'index ?";
    }
}