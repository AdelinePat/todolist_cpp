#include <exception>
#include <string>
#include <iostream>

class WrongInput : public std::exception {
    private:
        std::string message;

    public:
    WrongInput(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class WrongDate : public std::exception {
    private:
        std::string message;

    public:
    WrongDate(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

class WrongCommand : public std::exception {
    private:
        std::string message;

    public:
    WrongCommand(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};