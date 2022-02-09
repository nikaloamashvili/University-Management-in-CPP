#include "pch.h"
#include "date.h"
#include <string>
using namespace std;

Date::Date(int d, int m, int y)
{
	year = y;
	month = m;
	day = d;
}

Date & Date::operator=(const Date & other)
{
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	return *this;
}

Date::Date()
{
	year = 0;
	month = 0;
	day = 0;
}



ostream& operator<<(ostream& os, const Date& dt)
{
	if (typeid(os) == typeid(ostream)) {
		os << dt.day << '/' << dt.month << '/' << dt.year;
	}
	else {
		os << dt.day << ' ' << dt.month << ' ' << dt.year;
	}
	return os;
}

istream& operator>>(istream& is, Date& dt)
{
	if (typeid(is) == typeid(istream)) {
		cout << "day";
		is >> dt.day;
		cout << "month";
		is >> dt.month;
		cout << "year";
		is >> dt.year;
	}
	else
	{
		char delimiter;
		is >> delimiter >> dt.day >> delimiter >> dt.month >> dt.year >> delimiter;
	}
	return is;
}


