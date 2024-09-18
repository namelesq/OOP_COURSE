#include <iostream>
#include <string>
#include <vector>

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

	int CheckVolumeOfReservoir()
	{
		return m_length * m_weight * m_maxDepth;
	}

	int CheckSquareOfReservoir()
	{
		return m_length * m_weight;
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
	}

	void DistrubitionTypes(std::vector<Reservoir>& reservoir,
		std::vector<int>&sea,
		std::vector<int>&pond)
	{
		for (Reservoir& reserv : reservoir)
		{
			if (reserv.m_type == "sea"){ sea.push_back(reserv.m_length * reserv.m_weight); }
			else if (reserv.m_type == "pond"){ pond.push_back(reserv.m_length * reserv.m_weight); }
		}
	}
};

int SearchMaxSquareBySea(std::vector<int>& sea)
{
	int max = sea[0];
	for (size_t i = 0; i < sea.size(); ++i)
	{
		if (sea[i] > max)
		{
			max = sea[i];
		}
	}
	return max;
}

int SearchMaxByPond(std::vector<int>& pond)
{
	int max = pond[0];
	for (size_t i = 0; i < pond.size(); ++i)
	{
		if (pond[i] > max)
		{
			max = pond[i];
		}
	}
	return max;
}

int main()
{
	std::vector<Reservoir> reservoir;
	std::vector<int> sea;
	std::vector<int> pond;

}



