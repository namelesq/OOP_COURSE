#include <iostream>
#include <vector>

template<typename T>
void PrintArray(std::vector<T> vector)
{
	std::cout << "{ ";
	for (size_t i{ 0 }; i < vector.size(); i++)
	{
		std::cout << vector[i] << " ";
	}
	std::cout << "}\n";
}

template<typename T> 
std::vector<T> SortArray(std::vector<T> vector)
{
	size_t size = vector.size();
	while (size--)
	{
		bool swapped = false;

		for (size_t i{0}; i < size; i++)
		{
			if (vector[i] > vector[i + 1])
			{
				std::swap(vector[i], vector[i + 1]);
				swapped = true;
			}
		}

		if (swapped == false)
			break;
	}
	std::cout << "Array is sorted! \n";
	PrintArray(vector);
	return vector;
}

template<typename T>
void SearchMaxInArray(std::vector<T> vector)
{
	T max = vector[0];
	for (size_t i{ 0 }; i < vector.size(); i++)
	{
		if (vector[i] > max)
		{
			max = vector[i];
		}
	}
	std::cout << "Max in array: " << max << "\n";
}

template<typename T>
void SearchMinInArray(std::vector<T> vector)
{
	T min = vector[0];
	for (size_t i{ 0 }; i < vector.size(); i++)
	{
		if (vector[i] < min)
		{
			min = vector[i];
		}
	}
	std::cout << "Min in array: " << min << "\n";
}

template<typename T>
void ChangeElement(std::vector<T> vector, T element)
{
	T elem;
	for (size_t i{ 0 }; i < vector.size(); i++)
	{
		if (vector[i] == element)
		{
			std::cout << "Enter new element: ";
			std::cin >> elem;
			vector[i] = elem ;
		}
	}
	std::cout << "Array with new element: \n";
	PrintArray(vector);
}

template<typename T>
int BinarySearch(std::vector<T> vector, T element)
{
	int left=0, rigth = vector.size();
	while (left<=rigth)
	{
		int middle = (rigth + left) / 2;
		if (vector[middle] == element) { break; std::cout << "Index of element: "; return middle; }
		if (vector[middle] < element) { left = middle + 1;}
		if (vector[middle] > element) { rigth = middle - 1; }
	}
	return -1;
}

int main()
{
	std::vector<int> Integer{ 23,2,100,765,9,6,28,10 };
	std::vector<double> Double{ 98.5, 43.5, 100.04, 8.3, 54.4, 12.3, 3.4, 4.3 };
	PrintArray(Integer);
	PrintArray(Double);
	std::vector<int> NewInt = SortArray(Integer);
	std::vector<double>NewDouble = SortArray(Double);
	SearchMaxInArray(Integer);
	SearchMinInArray(Integer);
	SearchMaxInArray(Double);
	SearchMinInArray(Double);
	int elem_i;
	double elem_d;
	std::cout << "Enter element for binary serach(int): ";
	std::cin >> elem_i;
	BinarySearch(NewInt, elem_i);
	std::cout << "Enter element for binary serach(double): ";
	std::cin >> elem_d;
	BinarySearch(NewDouble, elem_d);
	std::cout << "Enter elem for change (int): ";
	std::cin >> elem_i;
	ChangeElement(Integer, elem_i);
	std::cout << "Enter elem for change (double): ";
	std::cin >> elem_d;
	ChangeElement(Double, elem_d);
	return 0;
}