#include <iostream>
#include <cstring>

class Person
{
private:
    char* name;
public:
    Person(const char* name) 
    {
        this->name = new char[strlen(name) + 1];
        strcpy_s(this->name,strlen(name)+1, name);
    }

    Person(const Person& other) 
    {
        name = new char[strlen(other.name) + 1];
        strcpy_s(name, strlen(other.name)+1, other.name);
    }

    ~Person() 
    {
        delete[] name;
    }

    void display()
    {
        std::cout << name<<"\n";
    }
};

class Apartment
{
private:
    Person** residents;
    int residentCount;
public:
    Apartment() : residentCount(0), residents(nullptr) {}

    void addResident(const char* name)
    {
        Person** temp = new Person * [residentCount + 1];
        for (int i = 0; i < residentCount; i++)
        {
            temp[i] = residents[i];
        }
        temp[residentCount] = new Person(name);
        delete[] residents;
        residents = temp;
        residentCount++;
    }

    ~Apartment() 
    {
        for (int i = 0; i < residentCount; i++) 
        {
            delete residents[i];
        }
        delete[] residents;
    }

    void displayResidents() {
        for (int i = 0; i < residentCount; i++) 
        {
            residents[i]->display();
        }
    }
};

class House
{
private:
    Apartment* apartments;
    int apartmentCount;
public:
    House(int count) : apartmentCount(count)
    {
        apartments = new Apartment[count];
    }

    void addResidentToApartment(int apartmentIndex, const char* name)
    {
        if (apartmentIndex >= 0 && apartmentIndex < apartmentCount) 
        {
            apartments[apartmentIndex].addResident(name);
        }
    }

    ~House() {
        delete[] apartments;
    }

    void displayAllResidents()
    {
        for (int i = 0; i < apartmentCount; i++) 
        {
            std::cout << "Apartment " << i + 1 << " \nresidents:";
            apartments[i].displayResidents();
        }
    }
};

int main() 
{
    House house(2);
    house.addResidentToApartment(0, "Person 1");
    house.addResidentToApartment(0, "Person 2");
    house.addResidentToApartment(1, "Person 3");

    house.displayAllResidents();

    return 0;
}
