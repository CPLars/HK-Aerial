//HKAerial Skynet Assignment

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

	srand(static_cast<unsigned int>(time(0))); //This creates the random generator for the system to decide where to put the target and also where to search

	int TLocation = rand() % 64 + 1; //A random position the system decides to put the target
	int GHnum = 64; //The highest point of the grid
	int GLnum = 1; //The lowest point of the grid
	int SystemGuess = 1; //Starts the counter for how many times the system searches for the target
	int Scan = rand() % 64 + 1; //A random point where the system searches between 1-64

	bool TargetFound = false; //This sets the starting logic to false so the system starts the search

	//The loop that searches for the target
	do {

		cout << "\t\t\t\nScanning...";

		if (Scan > TLocation) {
			cout << "\nTarget missing in Grid " << Scan << endl;
			GHnum = Scan;
			Scan = ((GHnum - GLnum) / 2) + GLnum;
			SystemGuess++;

		}
		else if (Scan < TLocation) {
			cout << "\nTarget missing in Grid " << Scan << endl;
			GLnum = Scan;
			Scan = ((GHnum - GLnum) / 2) + GLnum;
			SystemGuess++;

 		}
		if (Scan == TLocation) {
			cout << "\nTarget found in Grid " << Scan << endl;
			cout << "\nSystem found target after " << SystemGuess << " attempts. Are you proud of me, Creator?\n\n";
			TargetFound = true;

		}

	} while (TLocation != Scan); //This makes the loop run until it finds the target

	return 0;
}