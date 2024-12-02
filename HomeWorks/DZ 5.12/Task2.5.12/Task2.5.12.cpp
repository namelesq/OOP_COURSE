#include <iostream>
#include <string>

class BaseException {
protected:
    std::string message; 
public:
    explicit BaseException(const std::string& msg) : message(msg) {}
    virtual const char* what() const {
        return message.c_str();
    }
};

class MathException : public BaseException {
public:
    explicit MathException(const std::string& msg)
        : BaseException("MathException: " + msg) {}
};

class MemoryException : public BaseException {
public:
    explicit MemoryException(const std::string& msg)
        : BaseException("MemoryException: " + msg) {}
};

class FileException : public BaseException {
public:
    explicit FileException(const std::string& msg)
        : BaseException("FileException: " + msg) {}
};

class HomeworkException : public BaseException {
public:
    explicit HomeworkException(const std::string& msg)
        : BaseException("HomeworkException: " + msg) {}
};

int main() {
    try {
        
        throw MathException("Division by zero is not allowed!");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        
        throw MemoryException("Not enough memory to allocate the array.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        
        throw FileException("Unable to open the file: 'data.txt'.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        
        throw HomeworkException("Invalid solution for task 2.");
    }
    catch (const BaseException& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}