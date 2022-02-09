#pragma once
#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct Table_profesor {
	int semester; //1,2,3=summer
	long id;
};

struct Table_student {
public:
	int status; //1=course in proces ,2=pass,3= file
	long id;
	double grade;
};

class Course
{
public:
	Course();
	~Course();
	Course(long, string, int, int, int,int);

	friend ostream& operator<<(ostream& os, const Course& dt);
	friend istream& operator>> (istream& is, Course& dt);
	Course& operator=(const Course& other);

	long get_id();
	void set_id(long);

	string get_first_name();
	void set_first_name(string);

	int get_points();
	void set_points(int);

	int get_semester();
	void set_semester(int);

	vector < Table_profesor> get_profesortable();
	void add_profesor(long,int);

	Table_student get_student_info(long );
	long add_student(long);
	void change_student_grade(double x, long);
	bool bget_student_info(long);
	void set_student_info(Table_student);
	void set_type(int);
	int get_type(void);
	long get_pro_id(int);
	void add_kedem(long);
	vector < long> get_kedem();
	int get_num_of_students();
	long return_grade_of(long);
	int return_id_of(long);
	int return_status_of(long);
	bool check_stud_prop(long pid);
	bool check_stud_prop_con(long sid, long pid);

	int get_degree();
	void set_degree(int dd);

private:
	int num_of_students = 0;
	long id;
	string first_name;
	int points;
	int semester; //1,2,3=summer
	vector <Table_profesor> prop;
	vector <long> kedem;
	vector <Table_student> stud;
	int type_of_course; //1,2,3
	int degree;
};

inline Course::Course()
{
}

inline Course::Course(long iid, string iname, int ipoints, int isem, int itype_of_course,int idegree)
{
	id = iid;
	first_name = iname;
	points = ipoints;
	semester = isem;
	type_of_course = itype_of_course;
	degree = idegree;
}

inline Course::~Course()
{
	prop.clear();
	stud.clear();

}

inline  void Course::add_kedem(long x)
{
	kedem.push_back(x);
}



inline vector<long> Course::get_kedem()
{
	return kedem;
}

inline int Course::get_num_of_students()
{
	return this->num_of_students;
}

inline long Course::return_grade_of(long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			return element.grade;
		}
	}
	return 0;
}

inline int Course::return_id_of(long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			return element.id;
		}
	}
	return 0;
	
}

inline int Course::return_status_of(long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			return element.status;
		}
	}
	return 0;
}

inline bool Course::check_stud_prop(long pid)
{
	for (auto& element : prop) {
		if (element.id == pid) {
			return true;
		}
	}
	return false;
}

inline bool Course::check_stud_prop_con(long sid, long pid)
{
	bool a = false;
	bool b = false;
	for (auto& element : stud) {
		if (element.id == sid) {
			a = true;
		}
	}
	for (auto& element : prop) {
		if (element.id == pid) {
			b = true;
		}
	}
	return (a&&b);
}

inline int Course::get_degree()
{
	return degree;
}

inline void Course::set_degree(int dd)
{
	degree = dd;
}

inline long Course::get_id() {
	return id;
}

inline void Course::set_id(long iid)
{
	id = iid;
}

inline string Course::get_first_name()
{
	return first_name;
}

inline ostream& operator<<(ostream& os, const Course& dt) {

	os<< "course id " << dt.id << " corse name is " << dt.first_name << "course points is " << dt.points << "the course is in semester " << dt.semester << "type of the points is " << dt.type_of_course << endl;
	os<< "table of the propesors:" << endl;
	for (auto& element : dt.prop) {
		os << "prop id is " << element.id << "in semester " << element.semester << endl;
	}
	cout << "table of the students:" << endl;
	for (auto& element : dt.stud) {
		os << "student id is " << element.id << "in grade of " << element.grade << "status of " << element.status << endl;
	}
	return os;
}

inline istream& operator>> (istream& is, Course& dt) {
	cout << "id:";
	is >> dt.id;
	cout << "course name:";
	is >> dt.first_name;
	cout << "points:";
	is >> dt.points;
	cout << "in what semester:";
	is >> dt.semester;
	cout << "type of the course"<<endl;
	cout << "1 for basic course" << endl;
	cout << "2 for advance course" << endl;
	cout << "enter:";
	is >> dt.type_of_course;
	cout << "enter course of degree " << endl;
	cout << "1 for Bachelor's degree" << endl;
	cout << "2 for Master's degree" << endl;
	cout << "enter:";
	is >> dt.degree;
	return is;
}

inline Course & Course::operator=(const Course & other)
{
	this->first_name = other.first_name;
	this->id = other.id;
	this->kedem = other.kedem;
	this->points = other.points;
	this->prop = other.prop;
	this->semester = other.semester;
	this->stud = other.stud;
	this->type_of_course = other.type_of_course;
	return *this;
}

inline void Course::set_first_name(string if_n)
{
	first_name = if_n;
}

inline int Course::get_points()
{
	return points;
}

inline  void Course::set_points(int in)
{
	points = in;
}

inline int Course::get_semester()
{
	return semester;
}

inline void Course::set_semester(int is)
{
	semester = is;
}

inline  vector<Table_profesor> Course::get_profesortable()
{
	return prop;
}

inline  void Course::add_profesor(long iid,int isem)
{
	Table_profesor p;
	p.id = iid;
	p.semester = isem;
	prop.push_back(p);
}

inline  Table_student  Course::get_student_info(long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			return element;
		}
	}
}

inline long Course::add_student(long sid)
{
	num_of_students++;
	Table_student t;
	t.id = sid;
	t.grade =0;
	t.status=1;
	stud.push_back(t);
	return t.id;

}

inline  void Course::change_student_grade(double x, long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			element.grade = x;
		}
	}
}

inline bool Course::bget_student_info(long iid)
{
	for (auto& element : stud) {
		if (element.id == iid) {
			return true;
		}
	}
	return false;
}

inline  void Course::set_student_info(Table_student s)
{
	stud.push_back(s);
}

inline void Course::set_type(int x)
{
	type_of_course = x;
}

inline int Course::get_type(void)
{
	return type_of_course;
}

inline long Course::get_pro_id(int isem)
{
	for (auto& element : prop) {
		if (element.semester == isem) {
			return element.id;
		}
	}
}
