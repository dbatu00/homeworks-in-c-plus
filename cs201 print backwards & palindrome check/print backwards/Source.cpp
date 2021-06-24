using namespace std;
#include <string>
#include <iostream>

int main()
{
	
	string normal, backwards;
	int s, len;
	cout << "enter string to be reversed" << endl;
	cin >> normal;

	len = normal.length();

	for(s = len ; s != 0 ; s--)
	{
		backwards += normal.at(s-1);
	}

	if(backwards == normal)
		cout << "palindrome";
	else
		cout << "not palindrome";
	
	/*
    string s;  int k;
    cout << "enter string: ";
    cin >> s;
    cout << s << " reversed is ";
    
    k = s.length() - 1; // index of last character in s
    while (k >= 0)
    {   
		cout << s.substr(k,1);
		k -= 1;
    }
    cout << endl;

	*/







	cin.get();
	cin.ignore();
	return 0;

}