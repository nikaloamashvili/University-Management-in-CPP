#include "pch.h"
#include "address.h"

Address::Address()
{

}

Address::~Address()
{
}



Address::Address(string c, string n, int h, int a)
{
	city = c;
	neighborhood = n;
	house_num = h;
	apartment_num = a;
}

Address & Address::operator=(const Address & other)
{
	this->city = other.city;
	this->apartment_num = other.apartment_num;
	this->neighborhood = other.neighborhood;
	this->house_num = other.house_num;
	return *this;
}

ostream & operator<<(ostream & os, const Address & dt)
{
	os << dt.city <<" "<< dt.neighborhood << " " << dt.house_num << " " << dt.apartment_num << endl;
	return os;
	// TODO: insert return statement here
}

istream & operator>>(istream & is, Address & dt)
{
	cout << "city:";
	is >> dt.city;
	cout << "neighborhood:";
	is >> dt.neighborhood;
	cout << "house_num:";
	is >> dt.house_num;
	cout << "apartment_num:";
	is>> dt.apartment_num;
	return is;
	// TODO: insert return statement here
}
