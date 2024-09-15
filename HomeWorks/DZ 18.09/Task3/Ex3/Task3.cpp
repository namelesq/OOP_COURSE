#include <iostream>
#include <cstring>

class String 
{
private:
    char* data;            
    size_t length;         
    static size_t count;   

public:
    
    String() : length(80)
    {
        data = new char[length];
        data[0] = '\\0'; 
        count++;
    }

    explicit String(size_t size) : length(size)
    {
        data = new char[length];
        data[0] = '\\0';
        count++;
    }

    String(const char* str)
    {
        length = strlen(str) + 1; 
        data = new char[length];
        strcpy(data, str);
        count++;
    }

    ~String() 
    {
        delete[] data;
        count--;
    }

    void input() const
    {
        std::cout << "Enter string: ";
        std::cin.getline(data, length);
    }


    void output() 
    {
        std::cout << data << std::endl;
    }

    static size_t getCount()
    {
        return count;
    }
};


size_t String::count = 0;

int main() {
    String str1;          
    str1.input();        
    str1.output();       

    String str2(100);    
    str2.input();        
    str2.output();       

    String str3("Hello, world");  
    str3.output();       

    std::cout << "Количество созданных объектов String: " << String::getCount();

    return 0;
}