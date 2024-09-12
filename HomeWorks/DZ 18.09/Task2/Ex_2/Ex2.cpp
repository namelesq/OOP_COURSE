#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class Contact {
private:
    char* fullName;                // Динамическое выделение памяти для ФИО
    std::string homePhone;
    std::string workPhone;
    std::string mobilePhone;
    std::string additionalInfo;

public:
    // Конструктор с инициализацией
    Contact(const char* name, const std::string& hPhone, const std::string& wPhone,
        const std::string& mPhone, const std::string& info) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
        homePhone = hPhone;
        workPhone = wPhone;
        mobilePhone = mPhone;
        additionalInfo = info;
    }

    // Деструктор
    ~Contact() {
        delete[] fullName;         // Освобождение памяти
    }

    // Ввод информации о контакте
    void display() const {
        std::cout << "ФИО: " << fullName << "\\n"
            << "Домашний телефон: " << homePhone << "\\n"
            << "Рабочий телефон: " << workPhone << "\\n"
            << "Мобильный телефон: " << mobilePhone << "\\n"
            << "Дополнительная информация: " << additionalInfo << "\\n"
            << "-----------------------------\\n";
    }

    // Получение имени для поиска
    const char* getFullName() const {
        return fullName;
    }
};

class PhoneBook {
private:
    std::vector<Contact> contacts;  // Вектор для хранения списка контактов

public:
    // Добавление нового контакта
    void addContact() {
        char name[100], hPhone[15], wPhone[15], mPhone[15], info[100];
        std::cout << "Введите ФИО: ";
        std::cin.ignore();
        std::cin.getline(name, 100);
        std::cout << "Введите домашний телефон: ";
        std::cin >> hPhone;
        std::cout << "Введите рабочий телефон: ";
        std::cin >> wPhone;
        std::cout << "Введите мобильный телефон: ";
        std::cin >> mPhone;
        std::cout << "Введите дополнительную информацию: ";
        std::cin.ignore();
        std::cin.getline(info, 100);

        contacts.emplace_back(name, hPhone, wPhone, mPhone, info); // emplace для добавления нового контакта
    }

    // Удаление контакта по ФИО
    void deleteContact(const char* name) {
        auto it = std::remove_if(contacts.begin(), contacts.end(),
            [&name](Contact& c) { return strcmp(c.getFullName(), name) == 0; });
        if (it != contacts.end()) {
            contacts.erase(it, contacts.end());
            std::cout << "Контакт удален.\\n";
        }
        else {
            std::cout << "Контакт не найден.\\n";
        }
    }

    // Поиск контакта по ФИО
    void searchContact(const char* name) {
        for (const auto& contact : contacts) {
            if (strcmp(contact.getFullName(), name) == 0) {
                contact.display();
                return;
            }
        }
        std::cout << "Контакт не найден.\\n";
    }

    // Отображение всех контактов
    void showAllContacts() {
        if (contacts.empty()) {
            std::cout << "Телефонная книга пуста.\\n";
            return;
        }
        for (const auto& contact : contacts) {
            contact.display();
        }
    }

    // Сохранение данных в файл
    void saveToFile(const std::string& filename) {
        std::ofstream outFile(filename);
        for (const auto& contact : contacts) {
            outFile << contact.getFullName() << "\\n"; // Сохранение ФИО
            // Далее добавить сохранение остальных данных
        }
        outFile.close();
    }

    // Загрузка данных из файла
    void loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        // Имплементация загрузки данных о контактах
        inFile.close();
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;

    do {
        std::cout << "1. Добавить контакт\\n"
            << "2. Удалить контакт\\n"
            << "3. Найти контакт\\n"
            << "4. Показать все контакты\\n"
            << "5. Сохранить в файл\\n"
            << "6. Загрузить из файла\\n"
            << "0. Выход\\n"
            << "Выбор: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            phoneBook.addContact();
            break;
        case 2: {
            char name[100];
            std::cout << "Введите ФИО для удаления: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            phoneBook.deleteContact(name);
            break;
        }
        case 3: {
            char name[100];
            std::cout << "Введите ФИО для поиска: ";
            std::cin.ignore();
            std::cin.getline(name, 100);
            phoneBook.searchContact(name);
            break;
        }
        case 4:
            phoneBook.showAllContacts();
            break;
        case 5: {
            std::string filename;
            std::cout << "Введите имя файла для сохранения: ";
            std::cin >> filename;
            phoneBook.saveToFile(filename);
            break;
        }
        case 6: {
            std::string filename;
            std::cout << "Введите имя файла для загрузки: ";
            std::cin >> filename;
            phoneBook.loadFromFile(filename);
            break;
        }
        case 0:
            std::cout << "Выход из программы.\\n";
            break;
        default:
            std::cout << "Неверный выбор. Попробуйте снова.\\n";
            break;
        }
    } while (choice != 0);

    return 0;
}


/*#include <iostream>
#include <vector>
#include <fstream>

enum Actions
{
	ADDABONENT = 1,
	DELETEABONENT = 2,
	SEARCHABONENTBYSURN = 3,
	PRINTABONENTS = 4,
	SAVEFILE = 5,
	UPLOADFILE = 6,
	END = 0
};

class PhoneBook
{
private:
	
	std::string initials;
	int homeNumber;
	int workNumber;
	int mobileNumber;
	std::string addInfo;

public:
	
	/*PhoneBook();
	
	PhoneBook(std::string initial, int home, int work, int mobile, std::string addInfo) :
		initials(initial), homeNumber(home), workNumber(work), mobileNumber(mobile), addInfo(addInfo)
	{ }

	void AddAbonent(std::vector<PhoneBook> abonents)
	{
		PhoneBook abonent;
		std::cout << "Enter initials: ";
		std::cin >> abonent.initials;
		std::cout << "Enter home number: ";
		std::cin >> abonent.homeNumber;
		std::cout << "Enter work number: ";
		std::cin >> abonent.workNumber;
		std::cout << "Enter mobile number: ";
		std::cin >> abonent.mobileNumber;
		std::cout << " add info abonent: ";
		std::cin >> abonent.addInfo;
		abonents.push_back(abonent);
	}

	void PrintAbonents(std::vector<PhoneBook> abonents)
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
			{return abonent.initials == abonent.initials; }), abonents.end());
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


};


int main()
{
	std::vector<PhoneBook> abonents;
	PhoneBook abonent;
	abonent.AddAbonent(abonents);
	abonent.PrintAbonents(abonents);
	return 0;
}*/