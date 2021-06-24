using namespace std;
#include <string>
#include <iostream>
#include <fstream> 
#include <sstream>
#include "strutils.h"

//very cheesy solution to the problem of cout'ing double numbers like 3.4 as 03:40 (xx:xx format) instead of using precision

ifstream routesCheck(bool &exit)
{
	
	ifstream routesFile;
	string routesFileName;
	bool check = false;
	
	while(check == false)
	{
		
		cout << "Please enter a filename for route database: ";
		cin >> routesFileName;
		
		if(routesFileName == "EXIT")
		{exit = true; break;}

		routesFile.open(routesFileName.c_str()); 
	
		if (routesFile.fail())               
			cout << "Cannot open cannot open routes database file" << endl;
		
		else 
		{check = true; return routesFile;}

	}

}


ifstream timesCheck(bool &exit)
{
	
	ifstream timesFile;
	string timesFileName;
	bool check = false;
	
	while(check == false)
	{
		
		cout << "Please enter a filename for times database: ";
		cin >> timesFileName;

		if(timesFileName == "EXIT")
		{exit = true; break;}
	
		timesFile.open(timesFileName.c_str()); 
	
		if (timesFile.fail())               
			cout << "Cannot open cannot open times database file" << endl;
		
		else 
		{check = true; return timesFile;}

	}

}

double startTime(bool &exit)
{
	bool check = false;
	string startCheck = "", startCheckDummy="", foo=""; // foo is for converting char to string so that string to double converter can work
	double start = 0.0;

	while(check == false)
	{
		startCheck = ""; startCheckDummy=""; foo=""; start = 0.0;
		cout << "Please enter start time of arrival: ";
		cin >> startCheckDummy;

		if(startCheckDummy == "EXIT")
		{exit = true; break;}
		
		if(startCheckDummy.at(2) == ':' && startCheckDummy.at(0) >= 48 && startCheckDummy.at(0) <= 57 &&
		   startCheckDummy.at(1) >= 48 && startCheckDummy.at(1) <= 57 && startCheckDummy.at(3) >= 48 && startCheckDummy.at(3) <= 57 && 
		   startCheckDummy.at(4) >= 48 && startCheckDummy.at(4) <= 57)
		{
			startCheck += startCheckDummy.at(0);
			startCheck += startCheckDummy.at(1);
			startCheck += startCheckDummy.at(3);
			startCheck += startCheckDummy.at(4);

			foo = startCheck.at(0);
			start += atof(foo)*10;
			foo = startCheck.at(1);
			start += atof(foo);
			foo = startCheck.at(2);
			start += atof(foo)*0.1;
			foo = startCheck.at(3);
			start += atof(foo)*0.01;
			
			if(start >= 00.00 && start <= 23.59)
			{check = true; return start;}
			else
				cout << "Time is not in correct format" << endl;
		}
		else
			cout << "Time is not in correct format" << endl;
		
	}

	
}

void display(ifstream &routesFile, ifstream &timesFile, const double &routeStart, const string &depLoc) //delete const & if program doesnt work
{
	string r, t, depLocCheck, arrivalLoc, startCheckDummy, startCheck, foo;
	int routeID, timeID, startBabe = 0;
	double start = 0.0;
	cout << "The search results are: " << endl;
	
	while (getline(routesFile,r))
    {   
	    istringstream routes(r);
		 
        routes >> routeID >> depLocCheck >> arrivalLoc;
        
			if(depLocCheck == depLoc)
			{
				while (getline(timesFile,t))
				{
					istringstream times(t);
					times >> timeID >> startCheckDummy;
					
					startCheck = "";
				
					startCheck += startCheckDummy.at(0);
					startCheck += startCheckDummy.at(1);
					startCheck += startCheckDummy.at(3);
					startCheck += startCheckDummy.at(4);

					start = atof(startCheck) / 100.0;
					startBabe = atoi(startCheck) / 100;

					if(timeID == routeID && start >= routeStart)
					{
						if(startBabe == start)
						{
							if(startBabe < 10)
								{cout << depLoc << " " << arrivalLoc << " " << "0" << start << ".00" << endl;}
							else
								{cout << depLoc << " " << arrivalLoc << " " << start << ".00" << endl;}
						}
						else if(startBabe < 10)
						{
							cout << depLoc << " " << arrivalLoc << " " << "0" << start << endl;
							if(startCheckDummy.at(4) == '0')
								{cout << depLoc << " " << arrivalLoc << " " << start << "0" << endl;}
						}
						else if(startCheckDummy.at(4) == '0')
							{cout << depLoc << " " << arrivalLoc << " " << start << "0" << endl;}
						else
							{cout << depLoc << " " << arrivalLoc << " " <<  start << endl;}
					}
					
					start = 0.0;
					
					startBabe = 0;

				}
				timesFile.clear();
				timesFile.seekg(0);
			}

	}
	routesFile.clear();
	routesFile.seekg(0);
}


int main()
{
	bool exit = false;
	string depLoc;
	double start;
	ifstream routesFile, timesFile;
	
	routesFile = routesCheck(exit);

	timesFile = timesCheck(exit);

	cout << "Please enter departure location: ";
	cin >> depLoc;

	start = startTime(exit);

	while(!exit)
	{
		display(routesFile, timesFile, start, depLoc);
		cout << "Please enter departure location: ";
		cin >> depLoc;

		if(depLoc == "EXIT")
			exit = true;
		else
			start = startTime(exit);
	}

	cin.get();
	cin.ignore();
	return 0;
}