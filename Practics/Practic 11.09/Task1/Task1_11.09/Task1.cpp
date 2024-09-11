#include <iostream>
#include<vector>

enum Actions{INPUT=1,OUTPUT=2,END=0};

class Student
{
private:
	std::string Initials;
	std::string Birthday;
	int phoneNumber;
	std::string City;
	std::string Country;
	std::string EducationsInsitutions;
	std::string CityOfEducationsInstitution;
	std::string CountryOfEducationsInstitutions;
	short int NumberOfGroupe;

public:
	 
	void InputDataInVector(Student student, std::vector<Student> students)
	{
		std::cout << "Enter initials: ";
		std::cin >> student.Initials;
		std::cout << "Enter birthday: ";
		std::cin >> student.Birthday;
		std::cout << "Enter phone number: ";
		std::cin >> student.phoneNumber;
		std::cout << "Enter city: ";
		std::cin >> student.City;
		std::cout << "Enter country: ";
		std::cin >> student.Country;
		std::cout << "Enter Education instiution: ";
		std::cin >> student.EducationsInsitutions;
		std::cout << "Enter city of education institution: ";
		std::cin >> student.CityOfEducationsInstitution;
		std::cout << "Enter country of educations institution: ";
		std::cin >> student.CountryOfEducationsInstitutions;
		std::cout << "Enter number of groupe: ";
		std::cin >> student.NumberOfGroupe;
		students.push_back(student);
	}

	void outputDataAtVector(std::vector<Student> students)
	{
		for (const Student& student : students)
		{
			std::cout << "Initials: " << student.Initials << "\n";
			std::cout<<"Birthday: "<< student.Birthday<<"\n";
			std::cout<<"Phone number: "<< student.phoneNumber<<"\n";
			std::cout<<"City: "<< student.City<<"\n";
			std::cout<<"Country: "<< student.Country<<"\n";
			std::cout<<"Education insitution: "<< student.EducationsInsitutions<<"\n";
			std::cout<<"City of education insitution: "<< student.CityOfEducationsInstitution<<"\n";
			std::cout << "Country of education insitution: " << student.CountryOfEducationsInstitutions << "\n";
			std::cout<<"Number of groupe: "<< student.NumberOfGroupe<<"\n";
		}
	}

};

int main()
{
	std::vector<Student> students;
	Student student;
	int choise;
	do
	{
		std::cout << "If you went stop operations, enter 0\n";
		std::cin >> choise;
		switch (choise)
		{
		case INPUT:
			student.InputDataInVector(student, students);
		case OUTPUT:
			student.outputDataAtVector(students);
		case END:
			break;
		}
	} while (choise != 0);

	return 0;

}