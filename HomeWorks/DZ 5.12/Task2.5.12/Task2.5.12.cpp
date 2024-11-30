#include <iostream>
#include <string>

// Базовый класс пользовательских исключений
class BaseException {
protected:
    std::string message; // Сообщение об ошибке
public:
    explicit BaseException(const std::string& msg) : message(msg) {}
    virtual const char* what() const {
        return message.c_str();
    }
};

// Класс для математических ошибок
class MathException : public BaseException {
public:
    explicit MathException(const std::string& msg)
        : BaseException("MathException: " + msg) {}
};

// Класс для ошибок нехватки памяти
class MemoryException : public BaseException {
public:
    explicit MemoryException(const std::string& msg)
        : BaseException("MemoryException: " + msg) {}
};

// Класс для ошибок работы с файлами
class FileException : public BaseException {
public:
    explicit FileException(const std::string& msg)
        : BaseException("FileException: " + msg) {}
};

// Класс для обработки домашнего задания
class HomeworkException : public BaseException {
public:
    explicit HomeworkException(const std::string& msg)
        : BaseException("HomeworkException: " + msg) {}
};

// Пример работы программы
int main() {
    try {
        // Пример: математическая ошибка
        throw MathException("Division by zero is not allowed!");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // Пример: нехватка памяти
        throw MemoryException("Not enough memory to allocate the array.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // Пример: ошибка работы с файлами
        throw FileException("Unable to open the file: 'data.txt'.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        // Пример: ошибка в домашнем задании
        throw HomeworkException("Invalid solution for task 2.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}