using namespace std;
#include <string>
#include <iostream>

/*The program flow will be as follows:

main function: You will display a welcome message, and then ask for the name of the customer. Then, you should proceed to function1 with name as its parameter. The same steps will be repeated for the other customer. 

void function1(string): This function will be called from main with customer name as parameter, and it will call other given functions depending on program state. Asks the questions based on the flow chart given above. First question should be about espresso, for the rest of the questions you will construct the order. For the questions, you should make use of either function2 or function3. Note that if there were more than one customer, calling this function multiple times with appropriate parameters would have been enough.

bool function2(string): Prompts the user whether given ingredient is wanted or not. The string parameter will be an ingredient such as “foam” or “water”. When answered “yes”, this function returns true. When answered as “no”, this function returns false. 

bool function3(string, string): Prompts the user whether the given 2 ingredients are in equal amounts or not. The string parameters will be ingredients such as “milk” or “foam”. When answered “yes”, this function returns true. When answered as “no”, this function returns false. 

void function4(string, string): Takes the name of the customer and resulting coffee kind as parameters, and displays a message using them.*/

void questioner(string);
bool wantedIngredient(string);
bool function3(string, string);
void displayer(string, string);


bool equalCheck(string ingredient, string ingredient2)
{
	string ing1 = ingredient;
	string ing2 = ingredient2;
	string answer;
	cout << "Do " << ing1 << " and " << ing2 << " are in equal amounts?" << endl;
	cin >> answer;
	
	if (answer == "yes")
	{
		return true;
	}
	else
		return false;
}


bool wantedIngredient(string ingredient)
{
	
	string answer;

	cout <<"Does it have " << ingredient << "?" << endl;
	cin >> answer;

	if (answer == "yes")
		return true;
	else
		return false;
}


void displayer(string name, string coffee)
{
 
	cout << "Your order is ready " << name << "! What you want is a " << coffee <<". Enjoy!";
}


void questioner(string name)
{

	string ingredient = "espresso";
	string ingredient2;
	string coffee;
	
	cout << "Dear " << name <<", would you kindly answer our questions, so we can determine the coffee you want." << endl;

	if (wantedIngredient(ingredient))
	{
		ingredient = "milk";
		if (wantedIngredient(ingredient))
		{
			ingredient = "hot chocolate";
			if (wantedIngredient(ingredient))
			{
				coffee = "mocha";
			}
			else
			{
				ingredient = "foam";
				if (wantedIngredient(ingredient))
				{
					ingredient2 = "milk";
					if (equalCheck(ingredient,ingredient2))
					{
						coffee = "cappucino";
					}
					else
					{
						coffee = "latte";
					}
				}
				else
				{
					coffee = "au lait";
				}
			}
		}
		else
		{
			ingredient = "water";
			if (wantedIngredient(ingredient))
			{
				coffee = "americano";
			}
			else
				coffee = "espresso";

		}

	}
	else
		coffee = "filtered coffee";

	displayer(name, coffee);


}



int main()
{
	string name;


	cout << "Welcome to Pequod's Coffee! Can you tell me your name?" << endl;
	cin >> name;

	questioner(name);


	cin.ignore();
	cin.get();
	return 0;

}