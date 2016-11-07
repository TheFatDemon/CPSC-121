#include <iostream>
#include <array>
#include <string>

using namespace std;

void main() {
	while (true) {
		// Clear Screen to make it nice
		system("cls");

		// Prompt for cents
		cout << "Enter the amount of cents needed: ";

		// Store amound of cents
		int remainingCents;
		cin >> remainingCents;

		// Create variables to hold the amount of each needed
		int quartersNeeded, dimesNeeded, nickelsNeeded, penniesNeeded;

		// Quarters are worth 25
		quartersNeeded = remainingCents / 25;
		remainingCents = remainingCents % 25;

		// Dimes are worth 10
		dimesNeeded = remainingCents / 10;
		remainingCents = remainingCents % 10;

		// Nickes are worth 5
		nickelsNeeded = remainingCents / 5;
		remainingCents = remainingCents % 5;

		// Pennies are worth 1
		penniesNeeded = remainingCents / 1;
		remainingCents = remainingCents % 1;

		// Print how many of each are needed
		cout << "You need:" << endl;
		cout << "Quarters: \t" << quartersNeeded << endl;
		cout << "Dimes: \t" << dimesNeeded << endl;
		cout << "Nickels: \t" << nickelsNeeded << endl;
		cout << "Pennies: \t" << penniesNeeded << endl << endl << endl;

		// Prompt for restart
		cout << "Would you like to restart? [y/n] ";
		string response;
		cin >> response;
		if (response == "n" || response == "N") { 
			break; 
		}
	}
}