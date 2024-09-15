
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

enum Actions
{
	ADDABONENT = 1,
	DELETEABONENT = 2,
	SEARCHABONENTBYINITIALS = 3,
	PRINTABONENTS = 4,
	SAVEFILE = 5,
	UPLOADFILE = 6,
	END = 0
};

class PhoneBook
{
private:
	
	std::string initials;
	std::string homeNumber;
	std::string workNumber;
	std::string mobileNumber;
	std::string addInfo;

public:
	
	PhoneBook(){}
	
	PhoneBook(std::string initial, std::string home, std::string work,
		std::string mobile, std::string addInf) :
		initials(initial), homeNumber(home), workNumber(work), mobileNumber(mobile), addInfo(addInf)
	{
		initials = initial;
		homeNumber = home;
		workNumber = work;
		mobileNumber = mobile;
		addInfo = addInf;
	}

	void AddAbonent(std::vector<PhoneBook>&abonents, PhoneBook abonent)
	{
		std::cout << "Enter initials: ";
		std::cin >> abonent.initials;
		std::cout << "Enter home number: ";
		std::cin >> abonent.homeNumber;
		std::cout << "Enter work number: ";
		std::cin >> abonent.workNumber;
		std::cout << "Enter mobile number: ";
		std::cin >> abonent.mobileNumber;
		std::cout << "Add info abonent: ";
		std::cin >> abonent.addInfo;
		abonents.push_back(abonent);
	}

	void PrintAbonents(std::vector<PhoneBook>&abonents)
	{
		for (PhoneBook& abonent : abonents)
		{
			std::cout << "Initials: " << abonent.initials << "\n";
			std::cout << "Work number: " << abonent.workNumber << "\n";
			std::cout << "Mobile number: " << abonent.mobileNumber << "\n";
			std::cout << "Home number: " << abonent.homeNumber << "\n";
			std::cout << "Add info of abonent: " << abonent.addInfo << "\n\n";
		}
	}

	void DeleteAbonent(std::vector<PhoneBook> abonents)
	{
		std::string initials;
		std::cout << "Enter initials of abonent for delete him: ";
		std::cin >> initials;
		abonents.erase(std::remove_if(abonents.begin(), abonents.end(), [&](PhoneBook const& abonent)
			{return abonent.initials == initials; }), abonents.end());
		std::cout << "New phone number: \n";
		PrintAbonents(abonents);
	}

	void SearchAbonentByInitials(std::vector<PhoneBook> abonents)
	{
		std::string initials;
		std::cout << "Enter initials for search abonent: ";
		std::cin >> initials;
		for (const PhoneBook& abonent : abonents)
		{
			if (abonent.initials == initials)
			{
				std::cout << "Initials: " << abonent.initials << "\n";
				std::cout << "Work number: " << abonent.workNumber << "\n";
				std::cout << "Mobile number: " << abonent.mobileNumber << "\n";
				std::cout << "Home number: " << abonent.homeNumber << "\n";
				std::cout << "Add info of abonent: " << abonent.addInfo << "\n\n";
			}
		}
	}

	void Serialize(std::ofstream&ofs)
	{
		ofs << initials << " " << workNumber << " " << mobileNumber 
			<< " " << homeNumber << " " << addInfo<<"\n";
	}
		
	void Deserialize(std::ifstream& ifs)
	{
		ifs >> initials >> workNumber >> mobileNumber >> homeNumber >> addInfo;
	}

	void SaveAbonentsInFile(const std::vector<PhoneBook>& abonents, const std::string& FileName)
	{
		std::ofstream ofs(FileName, std::ios::binary);
		for (const auto& abonent : abonents) 
		{
			abonent.Serialize(ofs);
		}
	}
	
	void UploadAbonentsFromFile(std::vector<PhoneBook> abonents, const std::string& FileName)
	{
		std::ifstream ifs(FileName, std::ios::binary);
		PhoneBook abonent;
		while (ifs.peek() != EOF) 
		{
			abonent.Deserialize(ifs);
			abonents.push_back(abonent);
		}
	}

};

int main()
{
	std::vector<PhoneBook> abonents;
	std::vector<PhoneBook> SecondaryAbonents;
	PhoneBook abonent;
	int action;
	std::cout << "If you enter 1-add abonent\nIf you enter 2-delete abonent\nif you enter 3-search by initials\nIf you enter 4-print abonents\nif you enter 5-save info to file\nif you enter 6-upload info from file";
	std::cout << "\nAs soon as you want to finish, press 0 \n";
	do
	{
		std::cout << "Enter action: ";
		std::cin >> action;
		switch (action)
		{
		case ADDABONENT:
			abonent.AddAbonent(abonents, abonent);
			break;
		case DELETEABONENT:
			abonent.DeleteAbonent(abonents);
			break;
		case SEARCHABONENTBYINITIALS:
			abonent.SearchAbonentByInitials(abonents);
			break;
		case PRINTABONENTS:
			abonent.PrintAbonents(abonents);
			break;
		case SAVEFILE:
			abonent.SaveAbonentsInFile(abonents, "Information");
			break;
		case UPLOADFILE:
			abonent.UploadAbonentsFromFile(SecondaryAbonents, "Information");
			break;
		default:
			std::cerr << "Uncorrect action!\n";
		}
	} while (action != 0);
	return 0;
}