#include <iostream>

class String
{
private:
	char* m_data;
	size_t m_size;
public:
	String(const char* string)
	{
		m_data = new char[strlen(string) + 1];
		strcpy_s(m_data, strlen(string) + 1, string);
	}
	
	~String() { delete[] m_data;}

	char& operator[](size_t index)
	{
		if (index < 0 && index >= strlen(m_data))
		{
			std::cerr << "Index out of range\n";
		}
		return m_data[index];
	}
	size_t operator()(char symbol)
	{
		for (size_t i{ 0 }; i < strlen(m_data); i++)
		{
			if (symbol == m_data[i]) { return i; }

		}
		return -1;
	}
	operator int()const { return strlen(m_data); }
	void Display()const
	{
		std::cout << "String: " << m_data << "\n";
	}

};

int main()
{
	String str_1{ "My string" };
	str_1.Display();
	char symbol;
	std::cout << "Enter the symbol to search in the string: ";
	std::cin >> symbol;
	
	size_t index = str_1(symbol);
	if (index != -1)
	{
		std::cout << "Index of " << symbol << ": " << index << "\n";
	}
	else {std::cout<<"Index is not found\n"; }

	int length = str_1;
	std::cout << "Length of string: " << length;
	
	return 0;
}