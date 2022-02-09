#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector> 

using namespace std;

class Date {
private:
	int year;
	int month;
	int day;
public:
	Date();
	friend ostream& operator<<(ostream& os, const Date& dt);
	Date(int, int, int);
	friend istream& operator>>(istream& is, Date& dt);
	Date& operator=(const Date& other);
};