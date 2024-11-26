#include <iostream>
#include <vector>
#include <algorithm>
class SasNum
{
public:
	int value;
	SasNum(int value_in) { value = value_in; }
};

int main()
{
	std::vector<SasNum> SasNums = { 8,4,3,3,5,3,4,2,89,12 };
	std::sort(SasNums.begin(), SasNums.end(), [](const SasNum& L_val, const SasNum& R_val)
		{return L_val.value < R_val.value; });
	for (int i = 0; i < SasNums.size(); i++)
	{
		std::cout << SasNums[i].value<<" ";
	}
	return 0;
}