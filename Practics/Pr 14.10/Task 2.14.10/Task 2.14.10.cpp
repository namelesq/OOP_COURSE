#include <iostream>
#include <vector>
#include <algorithm>
class Array
{
private:
	size_t m_size;
	std::vector<int> m_vector;

public:
	Array(size_t size = 0, std::vector<int> vector):m_size{size},m_vector{vector}{}

	size_t GetSize() const { return m_size; }

	void SetSize(size_t size, size_t new_size)
	{
		if (new_size > size)
		{
			for (size_t i{ size }; i < new_size; i++)
			{
				m_vector.push_back(rand() % 20);
			}
		}
		else if (new_size < size)
		{
			m_vector.erase(m_vector.begin() + new_size, m_vector.end());
			m_vector[new_size];
		}
	}
	bool IsEmpty()
	{
		short int temp = 0;
		for (size_t i{ 0 }; i < m_vector.size(); i++)
		{
			if (m_vector[i] != ' ') { temp++; }
		}
		if (temp != 0) { return false; }
		else { return true; }
	}

	
};

int main()
{

}