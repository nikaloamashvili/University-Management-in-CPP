// c++ ex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "date.h"
#include "address.h"
#include "university.h" 
#include "people.h"
#include <vector>
#include "course.h"

#include <fstream>

using namespace std;

int main()
{

	
	//DB
	University Hit;
	Date da(11, 11, 1999);
	Address ad("tel aviv", "rotshild", 3, 4);
	Admin a(0000,"admin","admin","-",da, ad);
	Student s((long)320820, "nik","pass", "loma", da, ad,1);
	Course c((long)1111, "angular", 5, 2, 2,2);
	Course c1((long)145, "c++", 5, 2, 1,1);
	Course c2((long)100, "java", 5, 2, 1,2);
	c.add_kedem(145);
	c.add_kedem(100);
	Hit.add_course(c);
	Hit.add_course(c1);
	Hit.add_course(c2);
	Hit.add_people(&a);
	Hit.add_people(&s);

	// student mangment system
	Admin admin1;
	admin1.login(Hit);
	/*
	ofstream MyFile("filename.txt");

	// Write to the file
	Date da(11, 11, 1999);
	MyFile << da;
	MyFile.close();
	string myText;

	// Read from the text file
	ifstream MyReadFile("filename.txt");

	// Use a while loop together with the getline() function to read the file line by line
	Date j;
	MyReadFile >> j;
	cout << j;
	// Close the file
	MyReadFile.close();
	*/



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
