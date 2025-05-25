#include "display.hpp"

void displayTask(std::vector<Task>& tasks_list) {
    int length{0};
    for (Task task : tasks_list) {
        if (length < task.description.size()) {
            length = task.description.size();
        }        
    }

    int content_width{length+20};
    std::string bottom_border(content_width, '-');
    
    for (int index{0}; index<tasks_list.size(); index++) {
        int top_border_length = content_width - 11;
        std::string top_border((top_border_length/2), '-');
        int description_size{static_cast<int>(tasks_list[index].description.size())};
        int description_length{content_width - description_size - 4};
        int deadline_length{content_width - 10 - 4};
        int status_length{content_width - 16 - 4};

        std::string description_border(description_length, ' ');
        std::string deadline_border(deadline_length, ' ');
        std::string status_border(status_length, ' ');
    
        cout<<top_border<<" Tâche n°"<<index+1<<" "<<top_border<<endl;
        cout<<"| "<<tasks_list[index].description<<description_border<<" |"<<endl;
        cout<<"| "<<tasks_list[index].deadline<<deadline_border<<" |"<<endl;
        cout<<"| "<<"Etat : "<<(tasks_list[index].state ? "Terminée " : "En cours ")<<status_border<<" |"<<endl;
        cout<<bottom_border<<endl<<endl;
    }
}

std::string displayMenu(std::string& user_choice) {
    cout<<"####################################"<<endl;
    cout<<"0. Quitter\n"<<
    "1. Créer une nouvelle tâche\n"<<
    "2. Marquer une tâche comme terminée\n"<<
    "3. Modifier une tâche\n"<<
    "4. Supprimer une tâche\n";
    cout<<"####################################"<<endl;
    cout<<"Votre choix : ";
    cin>>user_choice;
    cout<<"\n";
    return user_choice;
}