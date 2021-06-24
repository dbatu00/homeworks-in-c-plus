using namespace std;
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

// Program checks if original direction(dir) is empty: If it is, then the letter is put
// After putting the letter, original direction is checked again: If it is empty, coordinates(rowPos,colPos) are updated accordingly;
// if its not empty, directions are tried according to orientation: If there is an available direction, currDir and coordinates are updated
// if not: Error is given and line is skipped

bool checkAndFill(vector< vector<char> > &matCheck, int rowPos, int colPos, const char &letter, char dir); //checks if direction is available and fills it
bool dirChange(const vector< vector<char> > &matCheck , const int &rowPos, const int &colPos, char &currDir, const string &orien, char dir); // changes direction
void dirToCoord(const char currDir, int &rowPos, int &colPos, const vector< vector<char> > &matCheck); // changes coordinates according to direction
void Print(const vector<vector<char>> & mat, const int &startRow, const int &startCol, const char &dir, const string &word, const string &orien, const bool &fillCheck);

void Print(const vector<vector<char>> & mat, const int &startRow, const int &startCol, const char &dir, const string &word, const string &orien, const bool &fillCheck)
{
	if(fillCheck) // if filling is complete and succesfull
	{   cout << "\"" << word << "\" " << "was put into the matrix with given starting point: " << startRow << "," << startCol << endl;
		cout << "direction: " << dir << "   " << "orientation: " << orien << endl;}
	else 
	{   cout << "\"" << word << "\" " << "could not be put into the matrix with given starting point: " << startRow << "," << startCol << endl;
		cout << "direction: " << dir << "   " << "orientation: " << orien << endl;}
	for (int j = 0; j < mat.size(); j++)
	{
		for (int k = 0; k < mat[0].size(); k++)
			cout << setw(4) << mat[j][k];
		
		cout << endl;
	}
}

void dirToCoord(const char currDir, int &rowPos, int &colPos, const vector< vector<char> > &matCheck)
{

	int colCheck = colPos; // tries the new direction's availability, if it is available: Updates
	int rowCheck = rowPos;
	
	if (currDir == 'r')
	{   colCheck += 1;
		if(rowCheck < matCheck.size() && colCheck < matCheck[0].size() && matCheck[rowCheck][colCheck] == '-')
			colPos = colCheck;}
	else if (currDir == 'l')
	{   colCheck -= 1;
		if(rowCheck < matCheck.size() && colCheck < matCheck[0].size() && matCheck[rowCheck][colCheck] == '-')//check
			colPos = colCheck;} // update
	else if (currDir == 'u')
	{   rowCheck -= 1;
		if(rowCheck < matCheck.size() && colCheck < matCheck[0].size() && matCheck[rowCheck][colCheck] == '-')
			rowPos = rowCheck;}
	else
	{   rowCheck += 1;
		if(rowCheck < matCheck.size() && colCheck < matCheck[0].size() && matCheck[rowCheck][colCheck] == '-')
			rowPos = rowCheck;}
}

bool dirChange(const vector< vector<char> > &matCheck , const int &rowPos, const int &colPos, char &currDir, const string &orien, char dir)
{
	int count = 0;
	bool check = false;
	currDir = dir ;
	while(count < 3 && check == false) // process is repeated three times because if direction is right; then up, down, left needs to be checked. Making three total
	{
		if( currDir == 'r' && orien == "CW" )
			currDir = 'd';
		else if( currDir == 'r' && orien == "CCW" )
			currDir = 'u';
		else if( currDir == 'l' && orien == "CW" )
			currDir = 'u';
		else if( currDir == 'l' && orien == "CCW" )
			currDir = 'd';
		else if( currDir == 'd' && orien == "CW" )
			currDir = 'l';
		else if( currDir == 'd' && orien == "CCW" )
			currDir = 'r';
		else if( currDir == 'u' && orien == "CW" )
			currDir = 'r';
		else if( currDir == 'u' && orien == "CCW" )
			currDir = 'l';
	
		if(	currDir == 'r' && rowPos < matCheck.size() && (colPos+1) < matCheck[0].size() && matCheck[rowPos][colPos+1] == '-')
			check = true;
		else if( currDir == 'l' && rowPos < matCheck.size() && (colPos-1) < matCheck[0].size() && matCheck[rowPos][colPos-1] == '-')
			check = true;
		else if( currDir == 'd' && (rowPos+1) < matCheck.size() && colPos < matCheck[0].size() && matCheck[rowPos+1][colPos] == '-')
			check = true;
		else if( currDir == 'u' && (rowPos-1) < matCheck.size() && colPos < matCheck[0].size() && matCheck[rowPos-1][colPos] == '-')
			check = true;
		else 
			count++;
	}
	if(check)
		return true; // return true if new currDir is available
	else
		return false;		
}

bool checkAndFill(vector< vector<char> > &matCheck, int &rowPos, int &colPos, char letter, char currDir, const string &orien, char dir)
{
	bool check = true, fillCheck = false , dirEmpty = false;
	while(check == true) // if filling is complete check becomes false
	{
		if( rowPos < matCheck.size() && colPos < matCheck[0].size() && matCheck[rowPos][colPos] == '-' ) //checks availability of direction
		{ 
			matCheck[rowPos][colPos] = letter;	// fill
			if(currDir != dir) // if currDir is not the original direction, tries to fill the original direction
			{
				if(	dir == 'r' && rowPos < matCheck.size() && (colPos+1) < matCheck[0].size() && matCheck[rowPos][colPos+1] == '-')
					dirEmpty = true;
				else if( dir == 'l' && rowPos < matCheck.size() && (colPos-1) < matCheck[0].size() && matCheck[rowPos][colPos-1] == '-')
					dirEmpty = true;
				else if( dir == 'd' && (rowPos+1) < matCheck.size() && colPos < matCheck[0].size() && matCheck[rowPos+1][colPos] == '-')
					dirEmpty = true;
				else if( dir == 'u' && (rowPos-1) < matCheck.size() && colPos < matCheck[0].size() && matCheck[rowPos-1][colPos] == '-')
					dirEmpty = true;
				
				if (!dirEmpty) //if original direction is not filled
					dirChange(matCheck , rowPos, colPos, currDir, orien, dir); // changes and checks direction
				else
					currDir = dir; //if direction is filled, updates currDir
			}
			dirToCoord(currDir,rowPos,colPos, matCheck); // coordinates are updated after filling 
			check = false; // false means filling complete
			fillCheck = true;
		}
		else
		{   check = dirChange(matCheck , rowPos, colPos, currDir, orien, dir);	
			dirToCoord(currDir,rowPos,colPos, matCheck);	}	
	}
	return !fillCheck; // this function returns false if fillcheck is successfull ( fillError = dirChange(...) )	
}

int main(){

	int numOfRows, numOfCols, rowPos, colPos, count, startRow, startCol;
	ifstream file;
	bool fillError = false, check = false, inputCheck = true, countCheck = false;
	char dir, letter;
	string filename,firstLine, line, word, orien, checkWord, dirCheck;

	while(check == false) // keeps repeating until file is opened successfully
	{		
		cout << "Please enter the name of the file: ";
		cin >> filename;
		cout << endl;
	
		file.open(filename.c_str()); 
	
		if (file.fail())               
			cout << "File name is incorrect, please enter again:" << endl;		
		else 
			check = true; 
	}	
	getline(file,firstLine); // to take first line for initalizing the matrix
    istringstream matSize(firstLine);
	matSize >> numOfRows >> numOfCols;
	if( numOfRows <= 0 || numOfCols <= 0)
	{ cout << "Invalid number for row and/or column!" ; cin.get(); cin.ignore(); return 0;}

	vector<vector<char>> mat(numOfRows, vector<char>(numOfCols));// char matrix, all '-'
	vector<vector<char>> matCheck(numOfRows, vector<char>(numOfCols)); // second matrix to replace current matrix if word filling is successful

	for (int j = 0; j < numOfRows; j++)	// fill initial matrix
	{
		for (int k = 0; k < numOfCols; k++)
			mat[j][k] = '-';
	}
	
	matCheck = mat; 
	
	while( getline( file, line) ) 
	{ 
		inputCheck = true;
		count = 0;
		istringstream inputs(line);
		istringstream checker(line); // same istringstream to check word count
		
		while( checker >> checkWord )
			count++;
		if (count != 5)
		{   cout << "Invalid line! Number of values is different than 5."<< endl;			
			inputCheck = false;
		}
		else
		{
			inputs >> word >> rowPos >> colPos >> dirCheck >> orien;
			startCol = colPos; // starting position is kept for printing
			startRow = rowPos;
			dir = dirCheck[0]; // dirCheck is kept for printing invalid input message
				
			if( rowPos < 0 || rowPos >= numOfRows || colPos < 0 || colPos >= numOfCols )
			{ cout << "Starting point is out of range! Point: " << rowPos << "," << colPos << endl; inputCheck = false; }
			else if( dir != 'r' && dir != 'l' && dir != 'u' && dir != 'd' )
			{ cout << "Invalid input for direction! Direction: " << dirCheck << endl; inputCheck = false; }
			else if ( orien != "CCW" && orien != "CW" )
			{ cout << "Invalid input for orientation! Orientation: " << orien << endl; inputCheck = false; }
		}
		
		if(inputCheck)
		{
			for ( int p = 0; p < word.length(); p++)
			{
				letter = word.at(p); // functions work letter by letter
				fillError = checkAndFill(matCheck, rowPos, colPos, letter, dir, orien, dir);
				if (fillError)
					p = word.length();// to break for loop if word filling is unsuccessfull
			}

			if(!fillError)
			{	mat = matCheck; // update original mat if filling is succesfull
				Print(mat, startRow, startCol, dir, word, orien, !fillError);	}
			else
			{   matCheck = mat; // reset checking mat if filling is unsuccessfull
				Print(mat, startRow, startCol, dir, word, orien, !fillError);	}
		}
	}
	cin.get();
	cin.ignore();
	return 0;
}