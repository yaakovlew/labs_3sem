#pragma once
#include <iostream>
#include <exception>
#include <string>


namespace exceptions {
    class OptionExceptions : public std::exception {
    private:
        std::string error_message;
    public:
        explicit OptionExceptions(const std::string &err_message, int line, const std::string &file);

        const char *what() const noexcept override;

        ~OptionExceptions() override;
    };

    OptionExceptions::OptionExceptions(const std::string &err_message, int line, const std::string &file) {
        this->error_message = "-Error in line " + std::to_string(line) +
                              " in file" + file + "-\t-" +
                              " Message:" + err_message + "-";
    }

    const char *OptionExceptions::what() const noexcept {
        return this->error_message.c_str();
    }

    OptionExceptions::~OptionExceptions() = default;

    class ArrayExceptions : public std::exception {
    private:
        std::string error_message;
    public:
        explicit ArrayExceptions(const std::string &err_message, int line, const std::string &file);

        [[nodiscard]] const char *what() const noexcept override;

        ~ArrayExceptions() override;
    };

    ArrayExceptions::ArrayExceptions(const std::string &err_message, int line, const std::string &file) {
        this->error_message = "-Error in line " + std::to_string(line) +
                              " in file" + file + "-\t-" +
                              " Message:" + err_message + "-";
    }

    const char *ArrayExceptions::what() const noexcept {
        return this->error_message.c_str();
    }

    ArrayExceptions::~ArrayExceptions() = default;
}

