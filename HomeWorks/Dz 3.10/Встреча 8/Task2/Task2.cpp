#include <iostream>

class Array
{
private:
	size_t m_size;
	int* m_data;
public:
	
	Array(size_t size) :m_size{ size }, m_data{ new int[size] }
	{
		std::cout << "Constructor called for size: " << size<<"\n";
	}
	Array(const Array& other) : m_size{ other.m_size }, m_data{ new int[other.m_size] }
	{
		for (size_t i{ 0 }; i < other.m_size; i++)
		{
			m_data[i] = other.m_data[i];
		}
		std::cout << "\nCopy constructor called\n";
	}
	Array(Array& other) :m_size{ other.m_size }, m_data{ other.m_data }
	{
		other.m_size = 0;
		other.m_data = nullptr;
	}
	Array& operator=(Array& other)
	{
		if (this != &other)
		{
			delete[] m_data;
			m_data = other.m_data;
			other.m_data = nullptr;
		}
	}
	~Array() { delete[] m_data; }
	
	void print() const
	{
		std::cout << "{ ";
		for (size_t i{ 0 }; i < m_size; i++)
		{
			std::cout << m_data[i] << " ";
		}
		std::cout << " }";
	}
};


int main()
{
	size_t size;
	std::cout << "Input size of  array: ";
	std::cin >> size;
	Array arr1(size);;
	std::cout << "First array: \n";
	arr1.print();

	Array arr2{ std::move(arr1) };
	std::cout << "Second Array: \n";
	arr2.print();

	return 0;
}