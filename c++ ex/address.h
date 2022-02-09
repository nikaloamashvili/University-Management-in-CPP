#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Address {
private:
	string city;
	string neighborhood;
	int house_num;
	int apartment_num;

public:

	Address();
	~Address();
	Address(string, string, int, int);

	friend ostream& operator<<(ostream& os, const Address& dt);
	friend istream& operator>> (istream& is, Address& dt);
	Address& operator=(const Address& other);
};