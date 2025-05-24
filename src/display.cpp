#include "display.hpp"


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