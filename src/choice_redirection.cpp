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
            modifyTask(tasks_list);
            break;
        case 4:
            deleteTask(tasks_list);
            break;
        case 0:
            break;
        default:
            cout<<"Qu'est-ce à dire que ceci ?"<<endl;
    }

}

void createTask(Task& task, std::vector<Task>& tasks_list) {
    askForDescription(task);
    askForDate(task);    
    task.final_string = task.description + ";" + task.deadline + ";" + std::to_string(task.state);       
    cout<<"test voici la final_string : "<<task.final_string<<endl;
    addIntoTodoList(task.final_string);
    tasks_list.push_back(task);
}

void swapStatus(std::vector<Task>& tasks_list) {
    try {
        int index_choice = getStrInputReturnsInt("Veuillez renseigner le numéro de la tâche qui doit changer de status : ");
        if (index_choice < 1 || index_choice > tasks_list.size()) {
            throw WrongInput("Le numéro de la tâche demandé n'existe pas.");
        }
        changeTaskState(tasks_list, index_choice-1);
        OverwriteTodoList(tasks_list);
    } 
    catch (const WrongCommand& e) {
        cout<<e.what()<<endl;
        swapStatus(tasks_list);
    } 
    catch (const WrongInput& e) {
        cout<<e.what()<<endl;
        swapStatus(tasks_list);
    }
}

void modifyTask(std::vector<Task>& tasks_list) {
    try {
        int index_choice = getStrInputReturnsInt("Veuillez renseigner le numéro de la tâche qui doit être modifiée : ");
        if (index_choice < 1 || index_choice > tasks_list.size()) {
            throw WrongInput("Le numéro de la tâche demandé n'existe pas.");
        }
        int choice = getStrInputReturnsInt("Veuillez écrire :\n0 : pour changer la description,\n1 : pour changer la date butoir.");
        cout<<"Contenu à modifier : "<<endl;
        switch (choice) {
            case 0:  
                cout<<tasks_list[index_choice-1].description<<endl;
                changeTask(tasks_list, index_choice-1, askForDescription);
                break;
            case 1:
                cout<<tasks_list[index_choice].deadline<<endl;
                changeTask(tasks_list, index_choice, askForDate);
                break;
            default:
                cout<<"La commande n'a pas été reconnue : veuillez recommencer"<<endl;
                modifyTask(tasks_list);
        }
        OverwriteTodoList(tasks_list);
    }
    catch (const WrongCommand& e) {
        cout<<e.what()<<endl;
        modifyTask(tasks_list);
    }
    catch (const WrongInput& e) {
        cout<<e.what()<<endl;
        modifyTask(tasks_list);
    }
}

void deleteTask(std::vector<Task>& tasks_list) {
    try {
        int index_choice = getStrInputReturnsInt("Veuillez renseigner le numéro de la tâche à supprimer : ");
        if (index_choice < 1 || index_choice > tasks_list.size()) {
            throw WrongInput("Le numéro de la tâche demandé n'existe pas.");
        }
        deleteTaskFromVector(tasks_list, index_choice-1);
        OverwriteTodoList(tasks_list);
    }
    catch (const WrongInput& e) {
        cout<<e.what()<<endl;
        deleteTask(tasks_list);
    }
}

void askForDescription(Task& task) {
    try {
        cout<<"Description de votre tâche : ";
        std::getline(cin>>std::ws, task.description);
        CleanDescriptionTask(task.description);
    } catch (const WrongInput& e) {
        cout<<e.what()<<endl;
        askForDescription(task);
    }
    
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
    } catch (std::runtime_error& e) {
        cout<<e.what()<<endl;
        askForDate(task);
    }
}