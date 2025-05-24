#ifndef __SANITIZE_INPUT__
#define __SANITIZE_INPUT__
#include <chrono> // need of get_time()
#include <ctime> // manipulate time_tm and tm type to compare user date string and now time
#include <regex> //need to replace things inside user string I guess
#include "utils.hpp"

std::time_t getTodayDate();

std::tm parseDateToTm(const std::string &date_string);

void compareDate(std::time_t &now_time, std::time_t &task_deadline);

void checkDateInt(std::__cxx11::smatch &regex_result);

void checkDateInput(std::string &date_input);

void isDateCoherent(std::string &date_input);

void CleanDescriptionTask(std::string &description_task);

bool isOnlyWhitespace(std::string &description_task);

#endif


