
#include <iostream>
#include <numeric>  

class Fraction 
{
private:
    int numerator;
    int denominator;

    int simplify(int num, int denom)
    {
        int gcd = std::gcd(numerator, denominator);
        num /= gcd;
        denom /= gcd;

        if (denominator < 0) 
        {
            num = -num;
            denom = -denom;
        }
        return num,denom;
    }

public:
    
    void input() 
    {
        std::cout << "Enter numerator: ";
        std::cin >> numerator;
        std::cout << "Enter denominator: ";
        std::cin >> denominator;
        if (denominator == 0) 
        {
            std::cerr << "Denominator cannot be zero. Setting to 1." << std::endl;
            denominator = 1;
        }
        simplify(numerator, denominator);
    }

    Fraction addition(Fraction fract1, Fraction fract2)
    {
        int newNum, newDenom;
        newNum = fract1.numerator * fract2.denominator + fract2.numerator * fract1.denominator;
        newDenom = fract1.denominator * fract2.denominator;
        simplify(newNum,newDenom);
        return Fraction(newNum, newDenom);
    }

    Fraction subtraction(Fraction fract1, Fraction fract2)
    {
        int newNum, newDenom;
        newNum = fract1.numerator * fract2.denominator - fract2.numerator * fract1.denominator;
        newDenom = fract1.denominator * fract2.denominator;
        return Fraction(newNum, newDenom);
    }

    void display() const 
    {
        std::cout << numerator << "/" << denominator << std::endl;
    }
};

int main() {
    Fraction frac1, frac2, result;

    std::cout << "Enter first fraction:\\n";
    frac1.input();

    std::cout << "Enter second fraction:\\n";
    frac2.input();

    std::cout << "First Fraction: ";
    frac1.display();

    std::cout << "Second Fraction: ";
    frac2.display();

    result = frac1 + frac2;
    std::cout << "Addition: ";
    result.display();

    result = frac1 - frac2;
    std::cout << "Subtraction: ";
    result.display();

    result = frac1 * frac2;
    std::cout << "Multiplication: ";
    result.display();

    result = frac1 / frac2;
    std::cout << "Division: ";
    result.display();

    return 0;
}