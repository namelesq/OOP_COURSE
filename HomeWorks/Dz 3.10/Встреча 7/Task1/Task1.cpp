#include <iostream>

class Overcoat
{
private:
	std::string m_type;
	int m_cost;
public:
	Overcoat(std::string type = "", int cost = 0) :m_type{ type }, m_cost{ cost }
	{
		m_type = type;
		m_cost = cost;
	}
	void Input()
	{
		std::cout << "Enter type of overcoat: ";
		std::cin >> m_type;
		std::cout << "Enter cost of overcoat: ";
		std::cin >> m_cost;
	}
	friend bool operator==(const Overcoat& over1, const Overcoat& over2)
	{
		std::cout << "equality completed\n";
		return over1.m_type == over2.m_type;
	}
	Overcoat operator=(const Overcoat& over)
	{
		if (&over != this)
		{
			m_type = over.m_type;
			m_cost = over.m_cost;
		}
		std::cout << "Assignment completed\n";
		return *this;
	}

	bool operator>(const Overcoat& over)
	{
		if (m_type == over.m_type)
		{
			std::cout << "Comparison is complete\n";
			return m_cost > over.m_cost;
		}
		else
		{
			std::cout << "Comparison is complete\n";
			return over.m_cost > m_cost;
		}
	}
	void Display()
	{
		std::cout << "\nType: " << m_type << " Cost: " << m_cost<<"\n";
	}

};

int main()
{
	Overcoat overcoat1;
	Overcoat overcoat2;
	overcoat1.Input();
	overcoat2.Input();
	overcoat1.Display();
	overcoat2.Display();
	if (overcoat1 == overcoat2)
	{
		std::cout << "Overcoat 1 and overcoat 2 are equal";
	}
	Overcoat overcoat3;
	overcoat3.Input();
	overcoat3.Display();
	overcoat3 = overcoat2;

	if (overcoat1 > overcoat2)
	{
		std::cout << "Overcoat 1 more expensive than overcoat 2\n";
	}
	else if (overcoat2 > overcoat1)
	{
		std::cout << "Overcoat 2 more expensive than overcoat 1\n";
	}
	else
	{
		std::cout << "They are equal";
	}

	return 0;
}