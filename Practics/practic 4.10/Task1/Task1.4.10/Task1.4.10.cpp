#include <iostream>

class Circle
{
private:
	int m_radius;
	int m_length;
public:
	Circle(int radius = 0, int length = 0) :m_radius{ radius }, m_length{ length } {}

	void getRadiusAndLength()
	{
		std::cout << "Enter radius: ";
		std::cin >> m_radius;
		m_length = m_radius * 2 * 3.14;
	}

	bool operator==(Circle& other)
	{
		if (m_radius == other.m_radius) { return true; }
		else { return false; }
	}

	Circle operator>(Circle& other)
	{
		if (m_length > other.m_length)
		{
			std::cout << "First circle is more than second on : ";
			return  Circle(m_length - other.m_length);
		}
		else
		{
			std::cout << "Second Circle is more than first on: ";
			return Circle(other.m_length - m_length);
		}
	}
};