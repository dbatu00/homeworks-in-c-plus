using namespace std;
#include <string>
#include <iostream>

// DID NOT FUNCTIONIZE!!!


// doesnt check if search is longer than source
// doesnt print the found words but cout << check; will do it
// some output spacing lines are off
// doesnt notify search or source changes
// doesnt print for source XXX and search YYY..



int main()
{
	string inputWord, source, search, sourcePart, check;
	bool searchCheck = false, sourceCheck = false, searchFormatCheck = true, sourceFormatCheck = true, exit = false;
	int choice;
	int searchFormatPos, sourceFormatPos, searchPos, sourcePos, searchLen, sourceLen;
	char foo;


	cout << " Example inputs with their meaning in parantheses: " << endl
		 << "1 thislectureisawesome (to enter a new source string)" << endl
		 << "2 lecture (to enter a new source string)" << endl
		 << "2 t?r? (to enter a source string with wildcards)" << endl
		 << "3 (to exit the program)" << endl;


	while(exit == false)
	{
		cout << "\nEnter your choice and string: ";
	
		cin >> choice;
		
		if (choice == 3)
			exit = true;
		else
			cin >> inputWord;
		
		cout << endl;

		if(choice != 1 && choice != 2 && choice != 3)
		{
			
			cout << "Choice can be 1, 2 or 3! Try again." << endl;
		
		}
		
		else if (choice == 1)
		{
			
			for(sourceFormatPos = 0; sourceFormatPos <= inputWord.length() -1; sourceFormatPos++)
			
			{
				
				foo = inputWord.at(sourceFormatPos);
				
				if(inputWord.at(sourceFormatPos) < 97 || inputWord.at(sourceFormatPos) > 122)
				
				{
					
					sourceFormatCheck = false;
					cout << "Wrong input format! Try again." << endl;
				
				}

			}

			if(sourceFormatCheck = true)
			{
				
				source = inputWord;
				sourceCheck = true;
			
			}
			
			
		}
		else if(choice == 2)
		{
			
			if(sourceCheck==true)
			
			{
				
				for(searchFormatPos = 0; searchFormatPos <= inputWord.length() -1; searchFormatPos++)
				
				{
					
					foo = inputWord.at(searchFormatPos);
					
					if(inputWord.at(searchFormatPos) < 97 || inputWord.at(searchFormatPos) > 122 )
					
					{
						if(inputWord.at(searchFormatPos) != '?')
						{
							sourceFormatCheck = false;
							cout << "Wrong input format! Try again." << endl;
						}
					
					}
				
				}
				
				if(sourceFormatCheck == true)
				
				{
					
					search = inputWord;
					searchCheck = true;
				
				}

			
			}
			
			else
				cout << "Wrong input format! Try again." << endl;

			
		}

		
		if(sourceCheck==true && searchCheck==true && exit == false)
		{
			
			searchLen = search.length();
			sourceLen = source.length();
			

			for (sourcePos= 0; sourcePos < source.length(); sourcePos++)
			{
				
				if(sourcePos + search.length() <= source.length())
				{
		
					sourcePart = source.substr(sourcePos, search.length());
					check = "";
					
					for(searchPos = 0 ; searchPos <= search.length() - 1; searchPos++)
					
					{
						
						if(search.at(searchPos) == sourcePart.at(searchPos) || search.at(searchPos) == '?')
						
						{
							
							check += sourcePart.at(searchPos);
							
							if(check == sourcePart)
							
							{
							
								cout << "found at pos: " << sourcePos << endl;
								check = "";
							
							}
						
						}
					
					}
	
				}
	
			}
		
		}

	}
		 
	cout << "See you!";
	
	cin.get();
	cin.ignore();
	return 0;


}