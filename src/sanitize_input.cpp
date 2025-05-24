#include "sanitize_input.hpp"
#include "wrong_input.hpp"

std::time_t getTodayDate() {
    std::time_t now = std::time(nullptr);
    std::tm local_tm = *std::localtime(&now);
    std::time_t now_time = std::mktime(&local_tm);
    return now_time;
}

std::tm parseDateToTm(const std::string& date_string) {
    std::tm time{};
    std::istringstream string_stream(date_string);
    string_stream >> std::get_time(&time, "%d/%m/%Y");
    if (string_stream.fail()) {
        throw std::runtime_error("Failed to parse date string into std::tm");
    }
    return time;
}

void compareDate(std::time_t& now_time, std::time_t& task_deadline) {
    std::tm now_tm = *std::localtime(&now_time);
    std::tm task_tm = *std::localtime(&task_deadline);

    int now_year = now_tm.tm_year + 1900;
    int task_year = task_tm.tm_year + 1900;

    int now_month = now_tm.tm_mon;
    int task_month = task_tm.tm_mon;

    if (task_deadline < now_time) {
        throw WrongDate("Date entrée invalide : date dans le passé\n");
    }
    else if (task_year >= now_year +2 && task_month > now_month) {
        throw WrongDate("Date entrée invalide : date trop loin dans le futur (jusqu'à 2 ans dans le futur accepté)\n");
    }    
}

void checkDateInt(std::__cxx11::smatch& regex_result) {
    int year = std::stoi(regex_result[3]);
    int month = std::stoi(regex_result[2]);
    int day = std::stoi(regex_result[1]);

    if (month <= 0 || month > 12 ) {
        throw WrongDate("Date invalide : le mois doit être compris entre 1 et 12.\n");
    }
    else if (month >= 8 && month%2 != 0 && day > 30) {
        throw WrongDate("Date invalide : le jour du mois indiqué doit être compris entre 1 et 30.\n");
    }
    else if (month <= 7 && month% 2 == 0) {
        if(day > 30) {
            throw WrongDate("Date invalide : le jour du mois indiqué doit être compris entre 1 et 30.\n");
        }
        if (month == 2 && day > 29) {
            throw WrongDate("Date invalide : le mois de février n'a que 29 jours.\n");
        } 
    }
    if (day <= 0) {
        throw WrongDate("Date invalide : le jour du mois doit être supérieur à 0.\n");
    }
    if (year < 1900 || year > 2099) {
        throw WrongDate("Date invalide : les années acceptées vont de 1900 à 2099.\n");
    }
}

void checkDateInput(std::string& date_input) {
    try {
        std::regex pattern(R"(^([0-9]{2})/([0-9]{2})/([0-9]{4})$)");
        if (std::regex_match(date_input, pattern)) {
            std::smatch result;
            regex_search(date_input, result, pattern);
            checkDateInt(result);
            isDateCoherent(date_input);  
        }
        else {
            throw WrongInput("La date n'est pas écrite au bon format");
        }
    }
    catch (const WrongDate& e) {
        throw;
    } catch (const std::exception& e) {
        throw;
    } catch (...) {
        throw;
    }
}

void isDateCoherent(std::string& date_input) {
    try {
        std::tm time{parseDateToTm(date_input)};
        std::time_t parsed_time = std::mktime(&time);
        if (parsed_time == -1) {
            throw std::runtime_error("Invalid or out-of-range date (e.g., year must be reasonable)");
        }
        std::time_t today{getTodayDate()};
        compareDate(today, parsed_time);
    } catch (const WrongDate& e) {
        throw;
    } catch (const std::exception& e) {
        throw;
    } catch (...) {
        throw;
    }
}

void CleanDescriptionTask(std::string& description_task) {
    if (description_task.empty() || isOnlyWhitespace(description_task)) {
        throw WrongInput("La description ne peut pas être vide");
    }   
    std::regex semicolon_pattern(R"((;)+)");
    description_task = std::regex_replace(description_task, semicolon_pattern, "");
    std::regex white_space_pattern(R"(\s{2,})");
    description_task = std::regex_replace(description_task, white_space_pattern, " ");
}

bool isOnlyWhitespace(std::string& description_task) {
    return std::all_of(description_task.begin(), description_task.end(), [](unsigned char c) {
        return std::isspace(c);
    });
}