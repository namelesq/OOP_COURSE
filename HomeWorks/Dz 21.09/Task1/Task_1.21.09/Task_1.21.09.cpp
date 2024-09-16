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
	
	Human(std::string init, std::string gend):
		initials{init},gender{gend}
	{
		initials = init;
		gender = gend;
	}

	void Display() {std::cout << "Initials: " << initials << " Gender: " << gender;}
};

class Apartament
{
private:
	std::vector<Human> human;
	int NumberApartament;
	int floor;

public:
	Apartament(){}
	
	Apartament(std::vector<Human> Human, int Num, int floo) :
		human{ Human }, NumberApartament{ Num }, floor{ floo }
	{
		human = Human;
		NumberApartament = Num;
		floor = floo;
	}

	void AddApartaments()
};

class House
{
private:
	std::vector<Apartament> house;
	int NumberOfHouse;

public:
	House(){}

	House(std::vector<Apartament> aparts, int NumberHouse) :
		house{ aparts },NumberOfHouse(NumberHouse)
	{
		house = aparts;
		NumberOfHouse = NumberHouse;
	}

	void InputHouse(std::vector<House>&house)
	{
		House houseK;
		std::cout << "Enter number of house: ";
		std::cin >> houseK.NumberOfHouse;
		house.push_back(houseK);
	}

	void PrintVectorOfHouse(std::vector<House>& house)
	{
		
	}
};


int main()
{
	std::vector<Human> human;
	std::vector<Apartament> aprt_s;
	std::vector<House> house;
	Human human_s;
	human_s.InputHuman(human);
	Apartament apartament;
	apartament.InputApartament(aprt_s);
	House house_s;
	house_s.InputHouse(house);
	
	return 0;
}
