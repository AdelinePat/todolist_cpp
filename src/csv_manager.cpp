#include "csv_manager.hpp"

void create_file() {
    bool file_exists = std::filesystem::exists(FILE_PATH);
    if (!file_exists) {
        cout<<"FILE_PATH = "<<FILE_PATH<<endl;
        cout<<"csv n'existe pas encore..."<<endl;
        std::ofstream new_file(FILE_PATH, std::ios::out | std::ios::trunc);
        if (!new_file) {
            cerr<<"La création du nouveau fichier a échoué"<<endl;
            return;
        }
        new_file << "Tâche;Date;Etat\n";
        new_file.close();
    }
}

void write_in_todo_list(std::string_view user_entry) {
    create_file();
    std::ofstream todo_file{FILE_PATH, std::ofstream::app};
    if (!todo_file) {
        cerr<<"Le fichier n'a pas pu s'ouvrir en mode ajout"<<endl;
        return;
    }
    todo_file << user_entry << endl;
    cout<<"Votre tâche a bien été ajouté !"<<endl;
}

void get_todo_list(std::vector<Task>& tasks_list) {
    std::ifstream todo_file{FILE_PATH, std::ios::in};
    if (!todo_file) {
        cerr<<"Le fichier n'a pas pu s'ouvrir en mode lecture";
        return;
    }
    std::string row;
    while (std::getline(todo_file, row)) {
        std::vector<std::string> my_current_string = split_string(row);
        Task a_task;
        if (my_current_string.at(2) != "Etat") {
            a_task.description = my_current_string.at(0);
            a_task.deadline = my_current_string.at(1);
            a_task.state = std::stoi(my_current_string.at(2));
            tasks_list.emplace_back(a_task);
        } 
    }
}


// void change_task_status() {

// }