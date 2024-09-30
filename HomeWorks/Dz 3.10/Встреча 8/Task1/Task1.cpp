#include <iostream>
#include <cstring>

class String
{
private:
    char* data;
public:
    String() : data(nullptr) {}

    String(const char* str)
    {
        if (str)
        {
            data = new char[strlen(str) + 1];
            strcpy_s(data, strlen(str) + 1, str);
        }
        else { data = nullptr; }
    }

    ~String() { delete[] data; }

    String(const String& other)
    {
        if (other.data)
        {
            data = new char[strlen(other.data) + 1];
            strcpy_s(data, strlen(other.data) + 1, other.data);
        }
        else { data = nullptr; }
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            if (other.data)
            {
                data = new char[strlen(other.data) + 1];
                strcpy_s(data, strlen(other.data) + 1, other.data);
            }
            else { data = nullptr; }
        }
        return *this;
    }

    String(String& other) : data{ other.data } { other.data = nullptr; }

    String& operator=(String&& other)  
    {
        if (this != &other)
        {
            delete[] data; 
            data = other.data; 
            other.data = nullptr; 
        }
        return *this;
    }

    void print() const 
    {
        if (data) {std::cout << data<<"\n"; }
        else { std::cout << "Empty string."; }
    }
};

int main() {
    
    String s1{ "My string" };
    std::cout << "First string: ";
    s1.print();

    String s2 { std::move(s1) };
    std::cout << "Second string: ";
    s2.print();

    return 0;
}

