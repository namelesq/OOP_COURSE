#include <iostream>
#include <string>
#include <vector>

enum Actions
{
	CHECK_VOLUME=1,
	CHECK_SQUARE=2,
	INPUT_DATA=3,
	CHECK_RESERVOIR=4,
	DISTRUB_TYPE=5,
	SQUARES_SEA=6,
	SQUARES_POND=7,
	END=0
};

class Reservoir
{
private:
	
	int m_length;
	int m_weight;
	int m_maxDepth;
	std::string m_type;

public:

	Reservoir() {};

	Reservoir(int length, int weight, int maxDepth, std::string type):
		m_length{ length }, m_weight{ weight }, m_maxDepth{ maxDepth }, m_type{type}
	{
		m_length = length;
		m_weight = weight;
		m_maxDepth = maxDepth;
		m_type = type;
	}

	void CheckVolume(std::vector<Reservoir>& reservoirs)
	{
		int length;
		std::cout << "Enter length: ";
		std::cin >> length;
		for (Reservoir& reserv : reservoirs)
		{
			if (reserv.m_length == length)
			{
				std::cout << "Volume: " << reserv.m_length * reserv.m_weight * reserv.m_maxDepth << "\n";
			}
		}
	}

	void CheckSquare(std::vector<Reservoir>& reservoirs)
	{
		int length;
		std::cout << "Enter length: ";
		std::cin >> length;
		for (Reservoir& reserv : reservoirs)
		{
			if (reserv.m_length == length)
			{
				std::cout << "Square: " << reserv.m_length * reserv.m_weight<< "\n";
			}
		}
	}

	void InputDataInvect(std::vector<Reservoir>& reservoir)
	{
		Reservoir object;
		std::cout << "Enter lehgth: ";
		std::cin >> object.m_length;
		std::cout << "Enter weigth: ";
		std::cin >> object.m_weight;
		std::cout << "Enter max depth: ";
		std::cin >> object.m_maxDepth;
		std::cout << "Enter type (sea or pond): ";
		std::cin >> object.m_type;
		reservoir.push_back(object);
	}

	void CheckReservoirType(std::vector<Reservoir>& reservoir)
	{
		size_t size_vec{ reservoir.size() };
		size_t count_sea{ 0 };
		size_t count_pond{ 0 };
		for (const Reservoir& reserv : reservoir)
		{
			if (reserv.m_type == "sea") { count_sea++; }
			else if (reserv.m_type == "pond"){ count_pond++; }
			else {continue;}
		}
		if (count_sea == size_vec) { std::cout << "Quantity type of sea: " << count_sea; }
		else if (count_pond == size_vec) { std::cout << "Quantity type of pond: " << count_pond; }
		else
		{
			std::cout << "Sea: " << count_sea << "\n";
			std::cout << "Pond: " << count_pond << "\n";
		}
	}

	void DistrubitionTypes(std::vector<Reservoir>& reservoir,
		std::vector<int>&sea,
		std::vector<int>&pond)
	{
		for (const Reservoir& reserv : reservoir)
		{
			if (reserv.m_type == "sea")
			{ 
				int result = reserv.m_length * reserv.m_weight;
				sea.push_back(result); 
			}
			else if (reserv.m_type == "pond")
			{ 
				int result = reserv.m_length * reserv.m_weight;
				pond.push_back(result);
			}
		}
		std::cout << "Distrubition is completed!\n";
	}
};

void OutputAllSquaresTheSea(std::vector<int>& sea)
{
	std::cout << "{ ";
	for (int i = 0; i < sea.size(); ++i)
	{
		std::cout << sea[i];
	}
	std::cout << " }";
}

void OutputAllSquaresThePond(std::vector<int>& pond)
{
	std::cout << "{ ";
	for (int i = 0; i < pond.size(); ++i)
	{
		std::cout << pond[i];
	}
	std::cout << " }";
}

int main()
{
	std::vector<Reservoir> reservoir;
	std::vector<int> sea;
	std::vector<int> pond;
	Reservoir reserv;
	int choise;
	std::cout << "If you wanted check volume, enter 1\nIf you wanted check square, enter 2\nIf you wanted input data in vector, enter 3\nIf you wanted check reservoir, enter 4\nIf you wanted distrubition type, enter 5\nIf you wanted output all sqaures sea, enter 6\nIf you wanted output all sqaures pond,enter 7\nEND = 0\n\n";
	do
	{
		std::cout << "Enter action: ";
		std::cin >> choise;
		switch (choise)
		{
		case CHECK_VOLUME:
			reserv.CheckVolume(reservoir);
			break;
		case CHECK_SQUARE:
			reserv.CheckSquare(reservoir);
			break;
		case INPUT_DATA:
			reserv.InputDataInvect(reservoir);
			break;
		case CHECK_RESERVOIR:
			reserv.CheckReservoirType(reservoir);
			break;
		case DISTRUB_TYPE:
			reserv.DistrubitionTypes(reservoir, sea, pond);
			break;
		case SQUARES_SEA:
			OutputAllSquaresTheSea(sea);
			break;
		case SQUARES_POND:
			OutputAllSquaresThePond(pond);
			break;
		default:
			std::cerr << "Uncorrect action\n";
		}
	} while (choise != 0);
	return 0;
}



