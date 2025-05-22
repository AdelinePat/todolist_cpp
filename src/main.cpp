#include "utils.hpp"
#include "csv_manager.hpp"

void redirect_choice(int user_choice, Task& task, std::vector<Task>& tasks_list) {
    int index_choice{0};
    switch (user_choice) {
        case 1:
            cout<<"Description de votre tâche : ";
            std::getline(cin>>std::ws, task.description);
            cout<<"Date butoire au format JJ/MM/AAAA : ";
            std::getline(cin>>std::ws, task.deadline);
            task.final_string = task.description + ";" + task.deadline + ";" + std::to_string(task.state);       
            cout<<"test voici la final_string : "<<task.final_string<<endl;
            add_into_todo_list(task.final_string);
            tasks_list.push_back(task);
            break;
        case 2:
            cout<<"Veuillez renseigner le numéro de la tâche qui doit changer de status : ";
            cin>>index_choice;
            change_task_state(tasks_list, index_choice-1);
            overwrite_todo_list(tasks_list);
            break;
        case 3:
            cout<<"je n'ai pas encore fait ça non plus : modifier une tâche"<<endl;
            break;
        case 4:
            cout<<"Veuillez renseigner le numéro de la tâche à supprimer : ";
            cin>>index_choice;
            delete_task(tasks_list, index_choice-1);
            overwrite_todo_list(tasks_list);
            cout<<"tu connais la chanson : suppprimer une tâche"<<endl;
            break;
        case 0:
            break;
        default:
            cout<<"Qu'est-ce à dire que ceci ?"<<endl;
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
    get_todo_list(tasks_list);
    do {
        displayTask(tasks_list);
        user_choice = displayMenu(user_choice);
        if (user_choice < 0 || user_choice > 4) {
            cout<<"Entrée invalide, veuillez recommencer..."<<endl;
        }
        redirect_choice(user_choice, task, tasks_list);

    } while (user_choice != 0);

    return 0;
}
