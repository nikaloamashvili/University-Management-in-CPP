#include "pch.h"
#include <string>
#include <vector> 
#include "people.h"
#include "date.h"
#include "university.h"
#include "course.h" 
#include <iostream>

using namespace std;


People::People()
{
}

People::People(long iid,string ipassword, string i_f_n, string i_l_n, Date di, Address ad)
{
	id = iid;
	password = ipassword;
	first_name = i_f_n;
	last_name = i_l_n;
	date_of_birth = di;
	my_add = ad;
}

long People::get_id(void) const
{
	return id;
}

void People::set_id(long iid)
{
	id = iid;
}

void People::set_date(Date d)
{
	date_of_birth = d;
}

void People::set_address(Address adddd)
{
	my_add = adddd;
}


string People::get_first_name(void)
{
	return first_name;
}

void People::options(University &x) const
{
	std::cout << "i am people";
}

void People::login(University & x) const
{
	int userchoise;
	long iid;
	int flag = 1;
	string ipassword;
	while (flag) {
		std::cout << "1.login" << endl;
		std::cout << "2.exit"<<endl;
		std::cout << "chose 1 or 2:" << endl;
		std::cin >> userchoise;

		switch (userchoise)
		{
		case(1): {
			std::cout << "enter your id:";
			std::cin >> iid;
			std::cout << "enter password:";
			std::cin >> ipassword;
			if (x.bget_people(iid)) {
				People *p = &(x.get_people(iid));
				if (ipassword == p->get_password()) {
					p->options(x);
					std::cout << endl;
				}
				else {
					std::cout << "wrong password";
					std::cout << endl;
				}
				
			}
			break;
		}
		case(2): {
			flag = 0;
			break;
		}
		default:
			cout << "wrong input" << endl;
			break;
		}
	}

}

void People::set_first_name(string ifn)
{
	first_name = ifn;
}

string People::get_last_name(void)
{
	return last_name;
}





void People::set_last_name(string ln)
{
	last_name = ln;
}

string People::get_password(void)
{
	return password;
}

void People::set_password(string ipassword)
{
	password = ipassword;
}

void Student::show_my_info(void)
{
	std::cout << this->get_first_name() << " " << this->get_last_name() << " " << this->get_id() << " " << this->date_of_birth << " " << this->my_add << endl;
}

void Student::calculate_avg()
{
	double sum=0;
	int s_lp=0;
	int h_lp = 0;
	int m_p = 0;
	int counter = 0;
	for (auto& element : this->pp) {
		if (element.course_status != 1) {
			sum = sum + element.grade;
			if (element.course_deg = 2) {
				m_p = m_p + element.nikud;
			}
			else {
				if (element.t_c == 1) {
					s_lp = s_lp + element.nikud;

				}
				else if (element.t_c == 2) {
					h_lp = h_lp + element.nikud;
				}
			}
			counter = counter + 1;
		}
	}
	if (counter != 0) {
		this->set_avr((sum / (this->pp.size())));
		this->set_l_p(s_lp);
		this->set_h_p(h_lp);
		this->set_m(m_p);

	}
}

bool Student::check()
{
	if (this->get_student_y()==1) {
		if ((this->get_l_p() + this->get_h_p() >= 20)&& this->get_h_p() >=5) {
			return true;
		}
	}
	else if (this->get_student_y() == 2) {
		if ((  this->get_h_p() +this->get_m() >= 20) && this->get_h_p() <= 4) {////////////////////////////
			return true;
		}
	}
	return false;
}

void Student::set_avr(double a)
{
	avrage = a;
}

void Student::set_l_p(int lp)
{
	low_points = lp;
}

void Student::set_h_p(int hp)
{
	high_points = hp;
}

double Student::get_avr()
{
	return avrage;
}

int Student::get_l_p()
{
	return low_points;
}

int Student::get_h_p()
{
	return high_points;
}

void Student::set_m(int xm)
{
	master_deg_points = xm;
}

int Student::get_m()
{
	return master_deg_points;
}

bool Student::get_pass()
{
	return pass;
}

void Student::set_pass(bool boo)
{
	pass = boo;
}

void Student::set_student_year(int y)
{
	degree = y;
}



Student::Student()
{

}

void Student::set_student_y(int y)
{
	degree = y;
}

double Student::get_course_grade(int idd)
{
	for (auto& element : pp) {
		if (element.course_id == idd) {
			return element.grade;
		}
	}
	return 0.0;
}



string Student::returnstring() const
{
	string output ;
	if (pass == true) {
		output.append("you can get yor " + to_string(degree) + " from the college now!!!!! we happy for you!! \n");
	}
	output.append("student of "+ to_string(degree) + '\n');
	output.append("avrage of " + to_string(avrage) + '\n');
	output.append("basic courses points " + to_string(low_points) + '\n');
	output.append("advance courses points " + to_string(high_points) + '\n');
	output.append("student grades:" + '\n');
	output.append("course id: course status: grade: nikud:" +'\n');
	for (auto& element : this->pp) {
		output.append(to_string(element.course_id) + "  " + to_string(element.course_status) + "  " + to_string(element.grade) +"  "+ to_string(element.nikud)+ element.profesor_name + "  "  +'\n' ) ;
	}
	return output;
}



void Student::options(University & x) const
{
	std::cout<<(x.get_people(this->get_id()));
}

int Student::get_student_y(void)
{
	return this->degree;
}

void Student::edit_course(int idd,double j){
	for (auto& element : pp) {
		if (element.course_id == idd) {
			element.grade = j;
			if (j > 55) {
				element.course_status = 2;
			}
			else {
				element.course_status = 3;
			}
			
		}
	}
}

void Student::add_course(long iid, double ggrade, int status, int nnikud,int typo, int isem, string pname, int ideg)
{
	student_cource nsc;
	nsc.grade = -1;
	nsc.course_id = iid;
	nsc.course_status = 1;
	nsc.nikud = nnikud;
	nsc.t_c = typo;
	nsc.semester = isem;
	nsc.profesor_name = pname;
	nsc.course_deg = ideg;
	pp.push_back(nsc);
}

Student::Student(long a, string b,string p , string c, Date d, Address e,int ix) :People(a, p, b, c, d, e)
{
	degree = ix;
}


ostream & operator<<(ostream & os, const People & dt)
{
	os << to_string(dt.id) <<" "<< dt.first_name << " " << dt.last_name << " " << dt.my_add << " " << dt.date_of_birth << " " << dt.returnstring();
	return os;
	// TODO: insert return statement here
}

istream & operator>>(istream & is, People & dt)
{
	cout << "id:";
	is >> dt.id;
	cout << "password:";
	is >> dt.password;
	cout << "first name:";
	is >> dt.first_name;
	cout << "last name:";
	is >> dt.last_name;
	cout << "address:";
	is >> dt.my_add;
	cout << "date:";
	is >> dt.date_of_birth;
	return is;
	// TODO: insert return statement here
}



istream & operator>>(istream & is, Student & dt)
{
	cout << "id:";
	is >> dt.id;
	cout << "first name:";
	is >> dt.first_name;
	cout << "last name:";
	is >> dt.last_name;
	cout << "address:";
	is >> dt.my_add;
	cout << "date:";
	is >> dt.date_of_birth;
	cout << "enter student status"<<endl <<"1 for Bachelor's degree"<< endl << "2 for Master's degree" << endl << "3 for free student"<< endl;
	is >> dt.degree;
	while (dt.degree < 4 and dt.degree > 0) {
		cout << "wrong input!" << endl;
		cout << "enter student status"<<endl <<"1 for Bachelor's degree"<< endl << "2 for Master's degree" << endl << "3 for free student"<< endl;
		is >> dt.degree;
	}
	return is;
	// TODO: insert return statement here
}

Admin::Admin()
{
}

Admin::Admin(long a,string p, string b, string c, Date d, Address e) : People(a, p, b, c, d, e)
{

}

void Admin::options(University & x) const
{
	int flag = 1;

	while(flag){
	cout << "hello admin what you want to do:"<< endl;
	cout << "1.to add a student" << endl;
	cout << "2.to edit a student" << endl;
	cout << "3.to add a course" << endl;
	cout << "4.to add a student to course" << endl;
	cout << "5.to edit a course" << endl;
	cout << "6.to change a grade of student" << endl;
	cout << "7.add_profesor" << endl;
	cout << "8.add_profesor_to_course" << endl;
	cout << "9.exit" << endl;
	int d;
	cin >> d;
	switch (d)
	{
	case 1:
		add_a_student(x);
		break;
	case 2:
		edit_a_student(x);
		break;
	case 3:
		add_a_course(x);
		break;
	case 4:
		add_student_to_course(x);
		break;
	case 5: 
		edit_a_course(x);
		break;
	case 6:
		edit_a_student_grade(x);
		break;
	case 7:
		add_profesor(x);
		break;
	case 8:
		add_profesor_to_course(x);
		break;
	case 9 :
		flag = 0;
		break;
	default:
		break;
	}
	}
}

string Admin::returnstring() const
{
	return string();
}

void Admin::add_a_student(University & x) const
{
	Student *ss= new Student();
	cout << "enter your student:";
	cin >> *ss;
	x.add_people(ss);

}

void Admin::add_profesor(University & x) const
{
	Profesor *ss = new Profesor();
	cout << "enter your profesor:";
	cin >> *ss;
	x.add_people(ss);
}

void Admin::add_student_to_course(University & x) const
{
	long sid;
	long iid;
	cout << "enter course id:";
	cin >> iid;
	cout << "enter student id:";
	cin >> sid;
	People *thestud = &(x.get_people(sid));
	Course *g= &(x.get_course(iid));
	Student * st = (Student *)thestud;
	if ((check_req(x.get_course(iid), *st) || st->get_student_y()==3) && ( ((*g).get_num_of_students())<151) ) {
		sid = (*g).add_student(st->get_id());
		st->add_course(iid, (*g).return_grade_of(sid), (*g).return_status_of(sid), (*g).get_points(),g->get_type(), (*g).get_semester(), x.get_people(((*g).get_pro_id((*g).get_semester()))).get_first_name(), (*g).get_degree());
		
	}
	else {
		cout << "you don't pass the course req" << endl;
	}
}

void Admin::add_profesor_to_course(University & x) const
{
	long sid;
	int semester;
	long iid;
	cout << "enter course id";
	cin >> iid;
	cout << "enter profesor id:";
	cin >> sid;
	cout << "enter profesor semester"<<endl;
	cout << "1 first semester" << endl;
	cout << "2 second semester" << endl;
	cout << "3 summer semester" << endl;
	cout << "enter:";
	cin >> semester;
	People *thestud = &(x.get_people(sid));
	Course *g = &(x.get_course(iid));
	Profesor * st = (Profesor *)thestud;
	st->add_course(iid, semester);
	g->add_profesor(sid,st->getcourse_semester(iid));
}

void Admin::add_a_course(University & x)  const
{
	Course t;
	int n_c;
	cout << "enter a course:";
	cin >> t;
	cout << "how many pre cources nedeed:";
	cin >> n_c;
	long id_of_kedem;
	int i = 0;
	for (i = 0; i < n_c; i++) {
		cout << "enter id of kedem:";
		cin >> id_of_kedem;
		while (!(x.bget_course(id_of_kedem))) {
			cout << "we dont have in database course wite id " << id_of_kedem << endl;
			cout << "enter id of kedem:";
			cin >> id_of_kedem;
		}
		t.add_kedem(id_of_kedem);
	}
	x.add_course(t);
}

void Admin::edit_a_student(University & x) const
{
	long iid;
	cout << "enter student id:";
	cin >> iid;
	

	People *thestud=&(x.get_people(iid));
	Student * st = (Student *)thestud;
	cout << *st;
	cout << "change:"<<endl;
	cout << "1.first name"<<endl;
	string n;
	cout << "2.last name" << endl;
	cout << "3.date of birth" << endl;
	cout << "4.address" << endl;
	Date dd;
	Address t;
	cout << "student of year:" << endl;
	int g;
	cin >> g;
	switch (g)
	{
	case 1:
		cout << "enter the new name:";
		cin >> n;
		st->set_first_name(n);
		break;
	case 2:
		cout << "enter the last name:";
		cin >> n;
		st->set_last_name(n);
		break;
	case 3:
		cout << "enter the new date:";
		cin >> dd;
		st->set_date(dd);
		break;
	case 4:
		cout << "enter the new address:";
		cin >> t;
		st->set_address(t);
		break;
	case 5:
		int xin;
		cout << "enter the student year:";
		cin >> xin;
		st->set_student_year(xin);
		break;
	default:
		break;
		///////////////////////////////////////////////////////////////////////
	}
}

bool Admin::check_req(Course c, Student a) const
{
	for (auto& element : c.get_kedem()) {
		if (a.get_course_grade(element)<55) {
			return false;
		}
	}
	if (c.get_degree() == 2 && a.get_student_y()==1) {
		return false;
	}
	if (c.get_degree() == 1 && a.get_student_y() == 2 && c.get_type()==1) {
		return false;
	}
	if (c.bget_student_info(a.get_id()) && a.get_course_grade(c.get_id())!=-1) {
		return false;
	}

	return true;
}




void Admin::edit_a_student_grade(University & x) const
{
	long iid;
	cout << "enter student id:";
	cin >> iid;
	People *thestud = &(x.get_people(iid));
	Student * st = (Student *)thestud;
	long new_grade;
	cout << "enter the new grade:";
	cin >> new_grade;

	cout << "enter the course id";
	int c_id;
	cin >> c_id;
	st->edit_course(c_id, new_grade);
	st->calculate_avg();
	st->set_pass(st->check());
	///////////////////////
	
}

void Admin::edit_a_course(University & x) const
{
	long c_id;
	cout <<  "enter the courae id you want to edit:";
	cin >> c_id;
	Course* temp;
	temp = &(x.get_course(c_id));
	cout << *temp;
	cout << endl;
	string ifirst_name;
	int inekudot;
	int isemester; //1,2,3
	int isug_course; //1,2,3
	long ikedem;

	cout << "change:" << endl;
	cout << "1.course name" << endl;
	cout << "2.points of the course" << endl;
	cout << "3.semester" << endl;
	cout << "4.type of the course" << endl;
	cout << "5.add kedem" << endl;
	int g;
	cin >> g;
	switch (g)
	{
	case 1:
		cout << "enter the new name:";
		cin >> ifirst_name;
		(*temp).set_first_name(ifirst_name);
		break;
	case 2:
		cout << "enter the points of the course:";
		cin >> inekudot;
		(*temp).set_points(inekudot);
		break;
	case 3:
		cout << "enter the semester:";
		cin >> isemester;
		(*temp).set_semester(isemester);
		break;
	case 4:
		cout << "enter the type of te course:";
		cin >> isug_course;
		(*temp).set_type(isug_course);
		break;
	case 5:
		cout << "enter the kedem:";
		cin >> ikedem;
		(*temp).add_kedem(ikedem);
		break;
	default:
		break;

	}



}

Profesor::Profesor()
{
}

Profesor::Profesor(long a,string p, string b, string c, Date d, Address e):People(a,p, b, c, d, e)
{

}

void Profesor::options(University & x) const
{
	int userchoise;
	cout << "hello profesor, what you want to do" << endl;
	cout << "1.show my_student_info"<<endl;
	cout << "2.show my_course_info" << endl;
	cin >> userchoise;
	switch (userchoise)
	{
	case(1):
		show_student(x);
		break;
	case(2):
		show_course(x);
		break;
	default:
		break;
	}
}

void Profesor::add_course(long idd, int isem)
{
	pro_cource c;
	c.course_id = idd;
	c.semester = isem;
	pp.push_back(c);
}

int Profesor::getcourse_semester(long iid)
{
	for (auto& element :pp) {
		if (element.course_id=iid) {
			return element.semester;
		}
	}
	return 0 ;
}

void Profesor::show_student(University & x) const
{
	long iid;
	cout << "enter the student id:";
	cin >> iid;
	if (!(x.bget_people(iid))) {
		cout << "the student not in the database!"<<endl;
	}
	else if (x.check_s_p_con(iid,this->get_id())) {
		cout << x.get_people(iid);
	}
	else {
		cout << "not your student"<<endl;
	}


}

void Profesor::show_course(University & x) const
{
	long iid;
	cout << "enter course id";
	cin >> iid;
	if (!(x.bget_course(iid))) {
		cout << "the course not in db" << endl;
	}
	else if (x.get_course(iid).check_stud_prop(this->get_id())) {
		cout << x.get_course(iid);
	}
	else {
		cout << "not your course" << endl;
	}	
}

string Profesor::returnstring() const
{
	return string();
}


