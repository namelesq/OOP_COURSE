#include <iostream>

class Flat
{
private:
	double m_square;
	double m_cost;
public:
	Flat(double square = 0, double cost = 0) :m_square{ square }, m_cost{ cost }
	{
		m_square = square;
		m_cost = cost;
	}
	void Input()
	{
		std::cout << "Enter square of flat: ";
		std::cin >> m_square;
		std::cout << "Enter cost of the flat: ";	  
		std::cin >> m_cost;
	}
	friend bool operator==(const Flat& flat1, const Flat& flat2)
	{
		std::cout << "equality completed\n";
		return flat1.m_square == flat2.m_square;
	}
	Flat operator=(const Flat& flat)
	{
		if (&flat != this) { m_square = flat.m_square, m_cost = flat.m_cost; }
		std::cout << "Assignment completed\n";
		return *this;
	}
	bool operator>(const Flat& flat)
	{
		return m_cost > flat.m_cost;
	}
	void Display()
	{
		std::cout << "Square: " << m_square << " Cost: " << m_cost << "\n";
	}
};

int main()
{
	Flat flat1, flat2;
	flat1.Input();
	flat2.Input();

	std::cout << "Flats: ";
	flat1.Display();
	flat2.Display();

	if (flat1 == flat2){std::cout << "Squares of the flats are equal\n";}

	Flat flat3;
	flat3.Input();
	flat3 = flat2;
	flat3.Display();

	if (flat1 > flat2)
	{
		std::cout << "Cost of the first flat is more expensive than second flat\n";
	}
	else
	{
		std::cout << "Cost of the second flat is more expensive than first flat\n";
	}
	return 0;
}