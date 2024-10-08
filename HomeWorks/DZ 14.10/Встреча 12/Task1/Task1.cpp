#include <iostream>
#include <ctime>

template <class T>
class Matrix
{
private:
	size_t m_size;
	T** m_matrix;

public:
	Matrix(size_t size=0, T**matrix=0):m_size{size},m_matrix{new T*[size]}{}

	~Matrix() { delete[] m_matrix; }

	void GetSize()
	{
		std::cout << "Enter size for matrix: ";
		std::cin >> m_size;
	}
	
	void ManualInputData()
	{
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				std::cout << "Enter element for matrix: ";
				std::cin >> m_matrix[i][j];
			}
		}
	}
	void AutomaticInputDataInt()
	{
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				m_matrix[i][j] = 1 + rand() % 30;
			}
		}
	}
	void AutomaticInputDataDouble()
	{
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				m_matrix[i][j] = (rand() % 30+1)/10;
			}
		}
	}

	void Display()
	{
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				std::cout << m_matrix[i][j] << " ";
			}
			std::cout << "\n";
		}
	}
	void SearchMax()
	{
		T max = m_matrix[0][0];
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				if (m_matrix[i][j] > max) { max = m_matrix[i][j]; }
			}
		}
		std::cout << "Max element of matrix: " << max << "\n";
	}
	void SearchMin()
	{
		T min = m_matrix[0][0];
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				if (m_matrix[i][j] < min) { min = m_matrix[i][j]; }
			}
		}
		std::cout << "Min element of matrix: " << min << "\n";
	}
	T CheckFirstElements(size_t in1, size_t in2)
	{
		T elem;
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				if (i == in1 && j == in2) { elem = m_matrix[i][j]; }
			}
		}
		return elem;
	}
	T CheckSecondElement(size_t in3, size_t in4)
	{
		T elem;
		for (size_t i{ 0 }; i < m_size; i++)
		{
			for (size_t j{ 0 }; j < m_size; j++)
			{
				if (i == in3 && j == in4) { elem = m_matrix[i][j]; }
			}
		}
		return elem;
	}
	void operator+()
	{;
		size_t index1, index2, index3, index4;
		std::cout << "Enter first index of element: ";
		std::cin >> index1>>index2;
		std::cout << "Enter second index of element: ";
		std::cin >> index3>>index4;
		T elem1 = CheckFirstElements(index1, index2);
		T elem2 = CheckSecondElement(index3, index4);
		std::cout << "Summ: " << elem1 << " + " << elem2 << " = " << elem1 + elem2<<"\n";
	}
	void operator-()
	{
		size_t index1, index2, index3, index4;
		std::cout << "Enter first index of element: ";
		std::cin >> index1 >> index2;
		std::cout << "Enter second index of element: ";
		std::cin >> index3 >> index4;
		T elem1 = CheckFirstElements(index1, index2);
		T elem2 = CheckSecondElement(index3, index4);
		std::cout << "Subtraction: " << elem1 << " - " << elem2 << " = " << elem1 - elem2 << "\n";
	}
	void operator*()
	{
		size_t index1, index2, index3, index4;
		std::cout << "Enter first index of element: ";
		std::cin >> index1 >> index2;
		std::cout << "Enter second index of element: ";
		std::cin >> index3 >> index4;
		T elem1 = CheckFirstElements(index1, index2);
		T elem2 = CheckSecondElement(index3, index4);
		std::cout << "Composition: " << elem1 << " * " << elem2 << " = " << elem1 * elem2 << "\n";
	}
	void operator/(Matrix& matrix)
	{
		size_t index1, index2, index3, index4;
		std::cout << "Enter first index of element: ";
		std::cin >> index1 >> index2;
		std::cout << "Enter second index of element: ";
		std::cin >> index3 >> index4;
		T elem1 = CheckFirstElements(index1, index2);
		T elem2 = CheckSecondElement(index3, index4);
		std::cout << "Division: " << elem1 << " / " << elem2 << " = " << elem1 / elem2 << "\n";
	}

};

int main()
{
	Matrix<int> matrix;
	Matrix<double> matrix_1;
	matrix.GetSize();
	matrix_1.GetSize();
	matrix.AutomaticInputDataInt();
	matrix_1.AutomaticInputDataDouble();
	matrix.operator+();
	matrix.operator-();
	matrix.operator*();
	matrix.operator/(matrix);
	matrix_1.operator+();
	matrix_1.operator-();
	matrix_1.operator*();
	matrix_1.operator/(matrix_1);
	matrix.SearchMax();
	matrix.SearchMin();
	matrix_1.SearchMax();
	matrix.SearchMin();

	return 0;
}