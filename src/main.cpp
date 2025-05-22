#include "utils.hpp"
#include "csv_manager.hpp"



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

void redirect_choice(int user_choice, Task& task) {
    switch (user_choice) {
        case 1:
            cout<<"Description de votre tâche : ";
            std::getline(cin>>std::ws, task.description);
            cout<<"Date butoire au format JJ/MM/AAAA : ";
            std::getline(cin>>std::ws, task.deadline);
            // task.final_string = "\"" + task.description + "\";\"" + task.deadline + "\";\"0\"";
            task.final_string = task.description + ";" + task.deadline + ";" + std::to_string(task.state);
                                
            cout<<"test voici la final_string : "<<task.final_string<<endl;
            write_in_todo_list(task.final_string);
            break;
        case 2:
            cout<<"j'ai pas encore fait ça non plus : marquer une tâche comme terminée"<<endl;
            break;
        case 3:
            cout<<"je n'ai pas encore fait ça non plus : modifier une tâche"<<endl;
            break;
        case 4:
            cout<<"tu connais la chanson : suppprimer une tâche"<<endl;
            break;
        case 0:
            return;
        default:
            cout<<"Qu'est-ce à dire que ceci ?"<<endl;
    }
}
void displayTask(std::vector<Task>& tasks_list) {
    get_todo_list(tasks_list);
    // for (Task a_task : tasks_list) {
    //     cout<<""
    // }
    for (int index{0}; index<tasks_list.size(); index++) {
        cout<<"# # # # "<<"Tâche n°"<<index<<" # # # #"<<endl;
        cout<<tasks_list[index].description<<endl;
        cout<<tasks_list[index].deadline<<endl;
        cout<<"Etat : "<<(tasks_list[index].state ? "Terminée" : "En cours")<<endl<<endl;
    }
}

int main(int argc, char const *argv[])
{
    std::filesystem::current_path("C:\\Users\\Adeline\\Documents\\C++\\todolist_cpp");

    std::cout << "Working directory: " << std::filesystem::current_path() << "\n\n";
    std::setlocale(LC_ALL, ".utf8");
    struct Task task;
    int user_choice{0};
    std::vector<Task> tasks_list;
    tasks_list.reserve(10);
    do {
        displayTask(tasks_list);
        user_choice = displayMenu(user_choice);
        if (user_choice < 0 || user_choice > 4) {
            cout<<"Entrée invalide, veuillez recommencer..."<<endl;
        }
        redirect_choice(user_choice, task);

    } while (user_choice != 0);

    return 0;
}
