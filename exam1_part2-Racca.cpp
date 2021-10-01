// Emerson Racca
// September 29, 2021
// Exam 1 - Die Rolling Game
/*
Create a 32-sided die rolling simulation ( possible outcomes 1 - 32 ).

1. Roll the die and reply with commentary based on the following flow chart. (Not posted here.)

2. Keep track and display the number of times the user has rolled, the number of times she won, and the number of times she lost.

3. Ask the user if she would like to “roll again?”.
*/

#include<iostream>
#include<cstdlib> // srand(), rand()
#include<ctime> // time(0)

using namespace std;


int main(void) {
	char rollAgain;
	srand((unsigned int)time(0)); // srand(time(0)); creates an unsigned int error.
	int rollValue;
	int numRolled = 0;
	int numWon = 0;
	int numLost = 0;

	cout << "Die Rolling Game\n\n";

	do {
		rollValue = 1 + rand() % 32;
		numRolled++;

		cout << "You rolled " << rollValue;
		cout << endl << endl;

		if (rollValue < 16) {
			cout << "Low\n";
			if (rollValue < 8) {
				cout << "Lose\n";
				numLost++;
			}		
			else
				cout << "Lose a Turn\n";
		}
		else {
			cout << "High\n";
			if (rollValue < 24)
				cout << "Roll Again\n";
			else {
				cout << "Win\n";
				numWon++;
			}
		}

		cout << "\nNumber of times rolled: " << numRolled << endl;
		cout << "Number of times won:    " << numWon << endl;
		cout << "Number of times lost:   " << numLost << endl;

		cout << "\n\nRoll again (y or n)? ";
		cin >> rollAgain;
		cout << endl;
	} while (rollAgain == 'y');

	return 0;
}