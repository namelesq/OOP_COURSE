#include <iostream>
#include <cstring>

class String
{
private:
    char* m_data;
public:
  
    String(const char* str)
    {
        m_data = new char[strlen(str) + 1];
        strcpy_s(m_data, strlen(str) + 1, str);
    }

    ~String() { delete[] m_data; }

    String(const String& other)
    {
        if (other.m_data)
        {
            m_data = new char[strlen(other.m_data) + 1];
            strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
        }
        else { m_data = nullptr; }
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] m_data;
            if (other.m_data)
            {
                m_data = new char[strlen(other.m_data) + 1];
                strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
            }
            else { m_data = nullptr; }
        }
        return *this;
    }

    String(String& other) : m_data{ other.m_data } { other.m_data = nullptr; }

    String& operator=(String&& other)  
    {
        if (this != &other)
        {
            delete[] m_data; 
            m_data = other.m_data; 
            other.m_data = nullptr; 
        }
        return *this;
    }

    void print() const 
    {
        if (m_data) {std::cout << m_data<<"\n"; }
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

