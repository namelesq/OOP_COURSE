#include<iostream>
#include <string>
#include <vector>

class Student
{
public:
	void InputData(std::vector<Student> student)
	{
		for (Student& studenT : student)
		{
			std::cout << "Enter initials of student: ";
			std::cin >> studenT.SN;
			std::cout << "Enter Birthday of student: ";
			std::cin >> studenT.Birthday;
			std::cout << "Enter Phone number of student: ";
			std::cin >> studenT.PhoneNumber;
			std::cout << "Enter city: ";
			std::cin >> studenT.City;
			std::cout << "Enter country: ";
			std::cin >> studenT.Country;
			std::cout << "Enter learning town: ";
			std::cin >> studenT.LearningTown;
			std::cout << "Enter number groupe: ";
			std::cin >> studenT.NumberGroupe;
		}
	}
	void OutputData(std::vector<Student> student)
	{
		for (Student& studenT : student)
		{
			std::cout << "Enter initials of student: "<< studenT.SN<<"\n";
			std::cout << "Enter Birthday of student: "<< studenT.Birthday<<"\n";
			std::cout << "Enter Phone number of student: "<< studenT.PhoneNumber<<"\n";
			std::cout << "Enter city: "<< studenT.City<<"\n";
			std::cout << "Enter country: "<< studenT.Country<<"\n";
			std::cout << "Enter learning town: "<< studenT.LearningTown<<"\n";
			std::cout << "Enter number groupe: "<< studenT.NumberGroupe;
		}
	}

private:
	std::string SN;
	std::string Birthday;
	std::string PhoneNumber;
	std::string City;
	std::string Country;
	std::string LearningTown;
	std::string NumberGroupe;

};

int main()
{
	std::vector<Student> student;
	return 0;
}