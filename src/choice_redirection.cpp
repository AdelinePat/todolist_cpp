#include "choice_redirection.hpp"
#include "wrong_input.hpp"

void redirectChoice(int user_choice, Task& task, std::vector<Task>& tasks_list) {
    int choice{0};
    switch (user_choice) {
        case 1:
            createTask(task, tasks_list);
            break;
        case 2:
            swapStatus(tasks_list);
            break;
        case 3:
            modifyTask(user_choice, tasks_list);
            break;
        case 4:
            deleteTask(user_choice, tasks_list);
            break;
        case 0:
            break;
        default:
            cout<<"Qu'est-ce à dire que ceci ?"<<endl;
    }
}


void createTask(Task& task, std::vector<Task>& tasks_list) {
    cout<<"Description de votre tâche : ";
    std::getline(cin>>std::ws, task.description);
    CleanDescriptionTask(task.description);
    askForDate(task);    
    task.final_string = task.description + ";" + task.deadline + ";" + std::to_string(task.state);       
    cout<<"test voici la final_string : "<<task.final_string<<endl;
    addIntoTodoList(task.final_string);
    tasks_list.push_back(task);
}

void swapStatus(std::vector<Task>& tasks_list) {
    cout<<"Veuillez renseigner le numéro de la tâche qui doit changer de status : ";
    int index_choice{0};
    cin>>index_choice;
    changeTaskState(tasks_list, index_choice-1);
    OverwriteTodoList(tasks_list);
}

void modifyTask(int choice, std::vector<Task>& tasks_list) {
    cout<<"Veuillez renseigner le numéro de la tâche qui doit être modifiée : ";
    int index_choice{0};
    cin>>index_choice;
    cout<<"Veuillez écrire :\n0 : pour changer la description,\n1 : pour changer la date butoir."<<endl;
    cin>>choice;
    changeTask(tasks_list, index_choice-1, choice);
    OverwriteTodoList(tasks_list);
}

void deleteTask(int choice, std::vector<Task>& tasks_list) {
    int index_choice{0};
    cout<<"Veuillez renseigner le numéro de la tâche à supprimer : ";
    cin>>index_choice;
    deleteTaskFromVector(tasks_list, index_choice-1);
    OverwriteTodoList(tasks_list);
}


void askForDate(Task& task) {
    try {
        cout<<"Date butoire au format JJ/MM/AAAA : ";
        std::getline(cin>>std::ws, task.deadline);
        checkDateInput(task.deadline);
    }
    catch (const WrongDate& e) {
        cout<<e.what()<<endl;
        askForDate(task);
    }
    catch (const WrongInput& e) {
        cout<<e.what()<<endl;
        askForDate(task);
    }
}