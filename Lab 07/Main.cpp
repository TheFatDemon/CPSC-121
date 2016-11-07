//
//  main.cpp
//  Lab 7
//
//  Created by Mario on 10/3/16.
//  Copyright © 2016 Mario Segura. All rights reserved.
//

#include <iostream>

using namespace std;

int const arraySize = 5;

int menuPromptAndResponse() {

	int response = 0;

	cout << "1. Sum" << endl
		<< "2. Mean" << endl
		<< "3. Display" << endl
		<< "4. Edit" << endl
		<< "5. Exit" << endl;

	cout << "Select a menu option [1-5]: ";

	cin >> response;

	if (response < 1 || response > 5) {
		system("cls");
		cout << "Invalid Menu Option" << endl;
		response = menuPromptAndResponse();
	}

	return response;
}

int main(int argc, const char * argv[]) {

	int numbers[arraySize];

	system("cls");
	for (int i = 0; i < arraySize; i++) {
		cout << "Integer for value " << i << ": ";
		cin >> numbers[i];
	}

	system("cls");

	while (true) {
		int response = menuPromptAndResponse();
		switch (response) {
		case 1:
		{
			// Sum
			int sum = 0;
			for (int i = 0; i < arraySize; i++) {
				sum += numbers[i];
			}
			system("cls");
			cout << "Sum of array: " << sum << endl << endl;
		}
		break;
		case 2:
		{
			// Mean
			int sum = 0;
			for (int i = 0; i < arraySize; i++) {
				sum += numbers[i];
			}

			system("cls");
			cout << "Mean of array: " << sum / arraySize << endl << endl;
		}
		break;
		case 3:
		{
			// Display
			system("cls");
			for (int i = 0; i < arraySize; i++) {
				cout << "Value of " << i << ": " << numbers[i] << endl;
			}
			cout << endl;
		}
		break;
		case 4:
		{
			// Edit
			system("cls");
			cout << "Which Value would you like to edit [0-" << arraySize - 1 << "]: ";
			int editLocation = 0;
			cin >> editLocation;
			if (editLocation < 0 || editLocation >(arraySize - 1)) {
				cout << "Invalid Array Location";
			}
			else {
				cout << "New value for " << editLocation << ": ";
				cin >> numbers[editLocation];
			}
			cout << endl;
		}
		break;
		case 5:
		default:
			// Terminate
			return 0;
			break;
		}
	}
	return 0;
}