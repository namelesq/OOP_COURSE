#include <iostream>
#include <vector>
 
void FillArray(std::vector<int> vec)
{
	srand(time(NULL));
	for (int i = 0; i < 15; i++)
	{
		vec.push_back(1+ rand % 20);
	}
}

int main()
{
	std::vector<int> Int;
}
