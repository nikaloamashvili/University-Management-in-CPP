#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector> 
#include "people.h"
#include "date.h"
#include "course.h"

using namespace std;

class University {
private:

	vector <Course> course;
	string name;
	Address address;
	vector <People *> people;

public:
	University();
	University(string, Address);

	bool bget_course(long iid); //Checks if course in the data base
	bool  bget_people(long iid);//Checks if people in the data base
	People &  get_people(long iid);
	Course & get_course(long iid);
	void add_people(People *ipeople); //add people to data base
	void add_course(Course kcourse); //add Course to data base
	bool check_s_p_con(long sid, long pid); // Checks if the student x was the student of profesor y
};