#include <iostream>
#include <numeric>

class Complex
{
private:
	int m_a;
	int m_b;
public:
	Complex(){}
	
	Complex(int a, int b) :m_a{ a }, m_b{ b }
	{
		m_a = a;
		m_b = b;
	}

	void Input()
	{
		std::cout << "Enter a: ";
		std::cin >> m_a;
		std::cout << "Enter b: ";
		std::cin >> m_b;
	}

	Complex operator+(const Complex&num) const
	{
		return Complex(m_a + num.m_a, m_b + num.m_b);
	}

	Complex operator-(const Complex& num) const
	{
		return Complex(m_a - num.m_a, m_b - num.m_b);
	}

	Complex operator*(const Complex& num)
	{
		return Complex(m_a * num.m_a - m_b * num.m_b, m_a * num.m_b + m_b * num.m_a);
	}

	Complex operator/(const Complex& num)
	{
		int denominator = num.m_a * num.m_a + num.m_b * num.m_b;
		if (denominator == 0)
		{
			std::cerr << "You cannot divide by zero\n";
		}
		return Complex((m_a * num.m_a + m_b * num.m_b) / denominator, 
			(m_b * num.m_a - m_a * num.m_b) / denominator);
	}

	friend std::ostream& operator<<(std::ostream& os, const Complex& num)
	{
		os << num.m_a;
		if (num.m_a >= 0) { os << "+"; }
		os << num.m_b << "*i";
		return os;
	}

};

int main()
{
	Complex number1, number2;
	number1.Input();
	number2.Input();

	Complex Summ = number1 + number2;
	Complex Subtraction = number1 - number2;
	Complex Composition = number1 * number2;
	Complex Division = number1 / number2;
	
	std::cout << "Summ: " << Summ<<"\n";
	std::cout << "Subtraction: " << Subtraction << "\n";
	std::cout << "Composition: " << Composition << "\n";
	std::cout << "Division: " << Division;

	return 0;
}