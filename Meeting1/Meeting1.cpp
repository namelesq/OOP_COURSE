#include <iostream>
#include <numeric> 

class Fraction {
private:
    int numerator;
    int denominator;


    void simplify() 
    {
        int gcd = std::gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;

        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:

    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) 
    {
        if (denominator == 0) 
        {
            std::cout<<"Denominator cannot be zero.";
        }
        simplify();
    }

    void input()
    {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) {
            std::cout<<"Denominator cannot be zero.";
        }
        simplify();
    }

    Fraction operator+(const Fraction& other) 
    {
        return Fraction(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) 
    {
        return Fraction(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) 
    {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other)  
    {
        if (other.numerator == 0)
        {
            std::cout<<"You can't divide by zero";
        }
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    void output() 
    {
        std::cout << numerator << "/" << denominator;
    }
};

int main() {
    Fraction fraction1, fraction2;
    std::cout << "Enter the first fraction:\n";
    fraction1.input();
    std::cout << "Enter the second fraction:\n";
    fraction2.input();

    Fraction sum = fraction1 + fraction2;
    Fraction difference = fraction1 - fraction2;
    Fraction product = fraction1 * fraction2;
    Fraction quotient = fraction1 / fraction2;

    std::cout << "Sum: ";
    sum.output();
    std::cout << "\n";
    std::cout << "Difference: ";
    difference.output();
    std::cout << "\n";
    std::cout << "Product: ";
    product.output();
    std::cout << "\n";
    std::cout << "Quotient: ";
    quotient.output();

    return 0;
}
