#include <iostream>
#include <vector>
using namespace std;

// 2D vector function 
void numPad()
{
	vector<vector<int> > vect{ { 1, 2, 3}, { 4, 5, 6 }, { 7, 8, 9 } };
	//Output message before showing keypad
	cout << "Numpad:" << endl;
	//Iterate through 2d Vector
	for (int i = 0; i < vect.size(); i++)
	{ 
		// printing the KeyPad.
		for (int j = 0; j < vect[i].size(); j++)
			
			cout << vect[i][j] << " ";
		
		cout << endl;
	}
}




int main()
{ 
	//create variable and assign user input for Letter Selection and keypad
	
	// set switch statements for user input of either A B or C

	numPad();
}

