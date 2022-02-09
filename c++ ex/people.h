#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include "date.h"
#include "address.h"
#include <vector> 

using namespace std;

class University;
class Course;

struct student_cource {
	long course_id;
	double grade;
	int course_status;
	int nikud;
	int t_c;
	int semester; // 1 or 2 or (3 for sumer sem)
	string profesor_name;
	int course_deg;
    
};

struct pro_cource {
	long course_id;
	int semester; // 1 or 2 or (3 for sumer sem)
};

class People {
protected:
	long id;
	string first_name;
	string last_name;
	Date date_of_birth;
	Address my_add;
	string password;

public:
	//constructor
	People();
	People(long,string,string, string, Date, Address);

	//getrs and seters
	long get_id(void) const;
	void set_id(long);
	void set_date(Date) ;
	void set_address(Address);
	string get_first_name(void);
	void set_first_name(string);
	string get_last_name(void);
	void set_last_name(string);

	string get_password(void);
	void set_password(string);

	//more functions
	virtual string returnstring() const =0;
	virtual void login(University &x) const;
	virtual void options(University &x) const;


	//operator overloads
	friend ostream& operator<<(ostream& os, const People& dt) ;
	friend istream& operator>> (istream& is, People& dt);

};


class Student :public People {
	int degree; // student status
	int avrage=0;
	int low_points=0;
	int high_points=0;
	int master_deg_points = 0;
	vector <student_cource> pp;
	bool pass;
public:

	Student();
	Student(long, string,string, string, Date, Address, int);

	virtual  void set_student_year(int)  ;
	virtual string returnstring() const override;
	virtual void options(University &x) const override;

	int get_student_y(void);
	void edit_course( int,double);
	void add_course(long, double, int, int,int,int,string,int) ;
	void set_student_y(int) ;
	double get_course_grade(int idd);
	void show_my_info(void);
	void calculate_avg();
	bool check() ;
	void set_avr(double);
	void set_l_p(int);
	void set_h_p(int);
	double get_avr();
	int get_l_p();
	int get_h_p();
	void set_m(int);
	int get_m();

	bool get_pass();
	void set_pass(bool);

	friend istream& operator>> (istream& is, Student& dt)  ;
};

class Admin :public People {

public:

	Admin();
	Admin(long, string,string, string, Date, Address);

	virtual void options(University &x) const override;
	virtual string returnstring() const override;

	void add_a_student(University &x) const;
	void add_profesor(University &x)const;
	void add_student_to_course(University &x) const;
	void add_profesor_to_course(University &x) const;
	void add_a_course(University &x) const;
	void edit_a_student(University &x) const;
	bool check_req(Course, Student) const;
	void edit_a_student_grade(University &x) const;
	void edit_a_course(University &x)const;
	friend istream& operator>> (istream& is, People& dt);
};

class Profesor : public People {
private:
	vector <pro_cource> pp;
public:
	
	Profesor();
	Profesor(long, string , string, string, Date, Address);

	virtual void options(University &x) const override;

	friend istream& operator>> (istream& is, People& dt);

	void add_course(long,int);
	int  getcourse_semester(long);
	void show_student(University &x)const;
	void show_course(University &x) const;

	virtual string returnstring() const override;


};


