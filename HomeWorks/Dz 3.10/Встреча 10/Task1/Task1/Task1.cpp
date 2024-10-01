#include <iostream>

class Date
{
private:
	int m_day;
	int m_month;
	int m_year;

	
	void Validate()
	{
		if (m_month < 1 || m_month>12) { std::cout << "\nThere is no such month\n"; }
		if (m_day < 1 || m_day > DaysInMonth()) { std::cout << "\nThere is no such day\n"; }
	}
	bool IsLeapYear()
	{
		return(m_year % 4 == 0 || m_year % 100 != 0) || (m_year % 400 == 0);
	}
	int DaysInMonth()
	{
		if (m_month == 2)
		{
			return(IsLeapYear()) ? 29 : 28;
		}
		return (m_month == 4 || m_month == 6 || m_month == 9 || m_month == 1) ? 30 : 31;
	}

public:

	Date(int day = 1, int month = 1, int year = 1) :m_day{ day }, m_month{ month }, m_year{ year }
	{
		Validate();
	}

	Date operator++()
	{
		m_day++;
		if (m_day > DaysInMonth())
		{
			m_day = 1;
			m_month++;
			if (m_month > 12)
			{
				m_month = 1;
				m_year++;
			}
		}
		Validate();
		return *this;
	}
	Date operator--(int days)
	{
		Date temp = *this;
		for (int i{ 0 }; i < days; i++) { temp.operator++(); }
		return temp;
	}

	bool operator!=(const Date& other)
	{
		return m_day != other.m_day && m_month != other.m_month && m_year != other.m_year;
	}

	bool operator==(const Date& other)
	{
		return m_day == other.m_day && m_month == other.m_month && m_year == other.m_year;
	}

	bool operator>(const Date& other)
	{
		if (m_month != other.m_month) { return m_month > other.m_month; }
		if (m_year != other.m_year) { return m_year > other.m_year; }
		return m_day > other.m_day;
	}
	bool operator<(const Date& other)
	{
		if (m_month != other.m_month) { return m_month < other.m_month; }
		if (m_year != other.m_year) { return m_year < other.m_year; }
		return m_day < other.m_day;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.m_day << "/" << date.m_month << "/" << date.m_year;
		return os;
	}
	friend std::istream& operator>>(std::istream& is, Date& date)
	{
		is >> date.m_day >> date.m_month >> date.m_year;
		date.Validate();
		return is;
	}

	Date& operator=(const Date& other)
	{
		if (this != &other)
		{
			m_day = other.m_day;
			m_month = other.m_month;
			m_year = other.m_year;
			Validate();
		}
		return *this;
	}

	Date operator+=(int days)
	{
		for (int i{ 0 }; i < days; i++) { operator++(); }
		return *this;
	}
	Date operator-=(int days)
	{
		for (int i{ 0 }; i < days; i++) { operator++(); }
		return *this;
	}
	void operator()() { std::cout << "Date: " << *this << "\n"; }
	};


int main()
{
	Date date_1;
	std::cout << "Enter date (day/month/year): ";
	std::cin >> date_1;
	std::cout << "Your date: " << date_1;
	date_1.operator++();
	std::cout << "\nDate after ++: " << date_1 << "\n";
	Date date_2{ 19,3,2008 };
	std::cout << "Comparing dates: " << date_1.operator==(date_2) << "\n";
	date_1.operator=(date_2);
	std::cout << "The second date is copied to the first date\n";
	std::cout << "Date 1: " << date_1 << "\n";
	Date date_3{ 28,1,2008 };
	if (date_1 > date_3) { std::cout << "First date is more than third date\n"; }
	else { std::cout << "First date is less than third date\n"; }
	if (date_1 != date_3) { std::cout << "Dates is not equal\n"; }
	return 0;

}