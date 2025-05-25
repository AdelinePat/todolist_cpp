#include "utils.hpp"
#include "display.hpp"
#include "choice_redirection.hpp"

int main(int argc, char const *argv[])
{
    std::filesystem::current_path("C:\\Users\\Adeline\\Documents\\C++\\todolist_cpp");
     

    // std::cout << "Working directory: " << std::filesystem::current_path() << "\n\n";
    std::setlocale(LC_ALL, ".utf8");
    struct Task task;
    std::string user_choice_str{""};
    int user_choice{0};
    std::vector<Task> tasks_list;
    tasks_list.reserve(10);
    getTodoList(tasks_list);
    do {
        if (user_choice != -1) {
            displayTask(tasks_list);
        }
        try {
            user_choice_str = displayMenu(user_choice_str);
            user_choice = parseCommand(user_choice_str);
            if (user_choice < 0 || user_choice > 4) {
            cout<<"Entrée invalide, veuillez recommencer..."<<endl;
            }
            redirectChoice(user_choice, task, tasks_list);
        }
        catch (const WrongCommand& e) {
            cout<<e.what()<<endl;
            user_choice = -1;
            // continue;
        }
    } while (user_choice != 0);

    return 0;
}
