using namespace std;
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>
#include <vector>
#include "strutils.h"

				

int main()
{
	struct student
	{
		unsigned int id;        
		string name, middlename, lastname;
		double gpa;
		bool middleCheck;
	};
	
	string gradesFileName, namesFileName, g, middleChecker;
	ifstream gradesFile, namesFile;
	int count = 0, reqSize = 0;
	unsigned int ID;
	bool existCheck = false;

	vector <unsigned int> sizeCheck;

	cout << "Please enter a filename for Students Grades Results: ";
	cin >> gradesFileName;

	gradesFile.open(gradesFileName.c_str()); 
	
	if (gradesFile.fail())               
	{ cout << "Can not find the requested file. Terminating application ..." << endl; }
	

	cout << "Please enter a name for Students Names: ";
	cin >> namesFileName;
	
	namesFile.open(namesFileName.c_str()); 
	
	if (namesFile.fail())               
	{ cout << "Can not find the requested file. Terminating application ..." << endl; return 0; }

	while (getline(gradesFile,g))
      
	
	    existCheck = false;
	
		istringstream grades(g);
		while(grades >> middleChecker)
			count++;
		
		grades.clear();
		grades.seekg(0);

		sizeCheck.push_back(ID);


	cin.get();
	cin.ignore();
	return 0;
   

}
