#include "pch.h"
#include <iostream>
#include <string>
#include <vector> 
#include "peopleDB.h"
#include "date.h"

people::people()
{
}

people::people(long iid, string i_f_n, string i_l_n, date i_d, address i_a)
{
	id = iid;
	first_name = i_f_n;
	last_name = i_l_n;
	this->date_of_birth.set_date(i_d);
	this->my_add.set_address(i_a);

}

long people::get_id(void)
{
	return id;
}

void people::set_id(long iid)
{
	id = iid;
}

string people::get_first_name(void)
{
	return first_name;
}

void people::set_first_name(string ifn)
{
	first_name = ifn;
}

string people::get_last_name(void)
{
	return last_name;
}

void people::set_last_name(string ln)
{
	last_name = ln;
}

void student::show_my_info(void)
{
	cout << this->get_first_name() << " " << this->get_last_name() << " " << this->get_id() << " " << this->date_of_birth.mmy_print() << " " << this->my_add.mmy_print() << endl;
}

student::student()
{

}


student::student(long a, string b, string c, date d, address e)
{
	id = a;
	first_name = b;
	last_name = c;
	this->date_of_birth.set_date(d);
	this->my_add.set_address(e);
}
/*
void admin::options(university u) const
{
	cout << "bla";

}






*/
/*
void admin::options(university &a) const
{

}

void admin:: add_student(university &uni)
{
	int house_num, apartment_num, year, month,day;
	long iid;
	string fname, lname, neighborhood, city;
	cout << "enter the student city:";
	cin >> city;
	cout << "enter the student neighborhood:";
	cin >> neighborhood;
	cout << "enter the student house_num:";
	cin >> house_num;
	cout << "enter the student apartment_num:";
	cin >> apartment_num;
	cout << "enter the student year:";
	cin >> year;
	cout << "enter the student month:";
	cin >> month;
	cout << "enter the student day:";
	cin >> day;
	cout << "enter the student first name:";
	cin >> city;
	cout << "enter the student first name:";
	cin >> neighborhood;
	cout << "enter the student first name:";
	cin >> fname;
	cout << "enter the student last name:";
	cin >> lname;
	cout << "enter the student id:";
	cin >> iid;
	address my_add(city, neighborhood, house_num, apartment_num);
	date d2(day, month, year);
	student x(iid, fname, lname, d2, my_add);
	uni.add_people(x);
}

void admin::edit_student(university & x)
{
	cout << "enter the id of the student you want to edit:";
	long idd;
	cin >>idd;
	people * stud = x.get_people(idd);


}*/

void admin::addstudent(vector<people>& p, student x)
{
	people t = x;
	p.push_back(t);
}
