#include <iostream>
#include <string>
#include <vector>

class Human
{
private:
	std::string initials;
	std::string gender;
public:
	Human() {};
	
	Human(std::string init, std::string gend)
	{
		initials = init;
		gender = gend;
	}

	void InputHuman()
	{
		std::cout << "Enter initials of human: ";
		std::cin >> initials;
		std::cout << "Enter gender of human: ";
		std::cin >> gender;
	}
};

class Apartament
{
private:
	std::vector<Human> apartament;
	int NumberApartament;
	int floor;
public:

};

class House
{
private:
	std::vector<Apartament> house;
	int NumberOfHouse;

public:

};


int main()
{
	std::vector<House> house;
	return 0;
}
