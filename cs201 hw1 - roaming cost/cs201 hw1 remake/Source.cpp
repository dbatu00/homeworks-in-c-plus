using namespace std;
#include <iostream>
#include <string>

int main()
{

	/* 
	There are nine inputs in this program:

•	Name of the user (of type string),
•	Price of outgoing call per minute in TL (of type double),
•	Number of minutes talked as outgoing calls (of type int),
Price of incoming call per minute in TL (of type double),
Number of minutes talked as incoming calls (of type int),
Price of internet usage per MB in TL (of type double),
GBs of internet used (of type double),
•	Price of one international SMS in TL (of type double), 
•	Number of SMS’s sent (of type int).

Seven outputs are expected in this program, all in terms of TL:

Money spent for outgoing calls (of type double),
Money spent for incoming calls (of type double),
Money spent for the internet usage (of type double),
Money spent for the SMS’s (of type double),
Total cost of all roaming services (of type double),
The tax imposed, 18% of the total cost (of type double),
Total roaming bill fee including the tax (of type double).

	*/
	string name;
	double outPerMin, inPerMin, perMB, perSMS, gbUsage, costOut, costIn, costSMS, costInternet, costTotal, tax, costRoaming;
	int outMins, inMins, smsSent;
	
	cout << "pls enter ur name: ";
	cin >> name;
	
	cout << name << ", please enter the price for outgoing call per minute: " ;
	cin >> outPerMin;
	cout << name << ", how many mins out: " ;
	cin >> outMins;
	costOut = outMins * outPerMin;
	cout << name << ", you have spent " << costOut << " TL for outgoing calls you made while you are abroad." <<  endl; cout << endl;
	

	cout << name << ", please enter the price for incoming call per minute: " ;
	cin >> inPerMin;
	cout << name << ", please enter how many minutes you have talked in incoming calls: " ;	
	cin >> inMins;
	costIn = inPerMin * inMins;
	cout << name << ", you have spent " << costIn << " TL for incoming calls you made while you are abroad." << endl; cout << endl;

	cout << name << ", please enter the price for internet usage per MB: " ;
	cin >> perMB;
	cout << name << ", please enter how many GBs you have used: " ; 
	cin >> gbUsage;
	costInternet = perMB * 1024 * gbUsage;
	cout << name << ", you have spent "<< costInternet << " TL for the internet while you are abroad." << endl; cout << endl;
	cout << endl;

	cout << name <<", please enter the price for one SMS: " ;
	cin >> perSMS;
	cout << name <<", please enter the number of SMS you have sent: " ;
	cin >> smsSent;
	costSMS = perSMS * smsSent;
	cout << name <<", you have spent " << costSMS << " TL for the SMS while you are abroad." << endl; cout << endl;
	
	costTotal = costOut + costIn + costInternet + costSMS;
	tax = (18.0 / 100) * costTotal;
	costRoaming = (118.0 /100) * costTotal;

	cout << name <<", total cost for all roaming services is " << costTotal << " TL." <<endl;
	cout << name <<", tax is " << tax << " TL." << endl;
	cout << name <<", total roaming bill fee with tax is " << costRoaming <<" TL." << endl;




	cin.ignore();
	cin.get();
	return 0;

}