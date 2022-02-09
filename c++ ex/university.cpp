#include "pch.h"
#include "university.h"

University::University()
{
}

University::University(string iname, Address iaddress)
{
	name = iname;
	address = iaddress;
}



void University::add_people(People *ipeople)
{
	people.push_back(ipeople);
}

void University::add_course(Course icourse)
{
	course.push_back(icourse);
}

Course & University::get_course(long iid)
{
	for (int i = 0; i < course.size(); i++) {
		if (course[i].get_id() == iid) {
			return course[i];
		}
	}
}

bool University::check_s_p_con(long sid, long pid)
{
	for (int i = 0; i < course.size(); i++) {
		if (course[i].check_stud_prop_con(sid, pid)) {
			return true;
		}
	}
	return false;
}

People &  University::get_people(long iid)
{
	for (int i = 0; i < people.size(); i++) {
		if (people[i]->get_id() == iid) {
			return *people[i];
		}
	}
}

bool University::bget_course(long iid)
{
	bool boolreturn = false;
	for (int i = 0; i < course.size(); i++) {
		if (course[i].get_id() == iid) {
			boolreturn = true;
		}
	}
	return boolreturn;
}

bool University::bget_people(long iid)
{
	bool boolreturn=false;
	for (int i = 0; i < people.size(); i++) {
		if (people[i]->get_id() == iid) {
			boolreturn = true;
		}
	}
	return boolreturn;
}

