#include <iostream>
#include <numeric>

class Fraction
{
public:
	

private:
	int numerator;
	int denominator;

    void reduce()
    {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // ������������, ����� ����������� ��� �������������
            numerator = -numerator;
            denominator = -denominator;
        }
    }

};


int main()
{

}