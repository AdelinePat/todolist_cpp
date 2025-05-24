#include "utils.hpp"
#include "display.hpp"
#include "choice_redirection.hpp"

int main(int argc, char const *argv[])
{
    std::filesystem::current_path("C:\\Users\\Adeline\\Documents\\C++\\todolist_cpp");
     

    // std::cout << "Working directory: " << std::filesystem::current_path() << "\n\n";
    std::setlocale(LC_ALL, ".utf8");
    struct Task task;
    int user_choice{0};
    std::vector<Task> tasks_list;
    tasks_list.reserve(10);
    getTodoList(tasks_list);
    do {
        displayTask(tasks_list);
        user_choice = displayMenu(user_choice);
        if (user_choice < 0 || user_choice > 4) {
            cout<<"Entrée invalide, veuillez recommencer..."<<endl;
        }
        redirectChoice(user_choice, task, tasks_list);

    } while (user_choice != 0);

    return 0;
}
