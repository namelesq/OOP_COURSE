#include <iostream>
#include <vector>

void Swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
} 

int particionHoare(std::vector<int>& array, int left, int right);
int particion_omuto(std::vector<int>& array, int left, int right);

void QuickSort(std::vector<int>& array, int left, int right)
{
	if (left >= right) { return; }
	int pivot = particion_omuto(array, left, right);
	QuickSort(array, left, pivot);
	QuickSort(array, pivot + 1, right);
}


int particion_omuto(std::vector<int>& array, int left, int right)
{
	int p_v = array[left];
	int p_p = left;
	for (size_t i = left + 1; i <= right; ++i)
	{
		if (array[i] < p_v)
		{
			p_p++;
			Swap(array[i], array[p_p]);
		}
	}
	Swap(array[p_p], array[left]);
	return p_p;
}

int particionHoare(std::vector<int>& array, int left, int right) 
{ 
	int p_v = array[(left + right) / 2];
	int i = left;
	int j = right;
	while (i <= j)
	{
		while (array[i] < p_v)
		{
			i++;
		}
		while (array[j] > p_v)
		{
			j--;
		}
		if (i >= j) { break; }
		Swap(array[i], array[j]);
		i++;
		j--;
	}
	return j;
}

int main()
{
	std::vector<int> array{ 9,3,2,5,1,4,7,8,7 };
	QuickSort(array, 0, array.size() - 1);
	for (size_t i = 0; i < array.size(); i++)
	{
		std::cout << array[i] << " ";
	}
	return 0;
}