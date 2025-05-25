#include "utils.hpp"

std::vector<std::string> splitString(std::string& current_string) {
        std::vector<std::string> all_strings;
        size_t start = 0;
        size_t end = current_string.find(";");

        while (end != std::string::npos) {
            all_strings.push_back(current_string.substr(start, end-start));
            start = end+1;
            end = current_string.find(";", start);
        }
        all_strings.push_back(current_string.substr(start));
        return all_strings;
}

int parseCommand(const std::string& input) {
    std::stringstream string_stream(input);
    int choice;
    if (string_stream >> choice && string_stream.eof()) {
        return choice;
    } else {
        throw WrongCommand("Commande invalide : entrée non numérique.");
    }
}

int getStrInputReturnsInt(std::string_view prompt_string) {
    try {
        cout<<prompt_string<<endl;
        std::string choice_str{""};
        int choice{0};
        cin>>choice_str;
        choice = parseCommand(choice_str);
        return choice;
    }
    catch (const WrongCommand& e) {
        cout<<e.what()<<endl;
        return getStrInputReturnsInt(prompt_string);       
    }
}