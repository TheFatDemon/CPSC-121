#include <iostream>
#include <string>
using namespace std;
void main() {
	int base;
	char operand;
	cout << "Enter the first number: ";
	cin >> base;
	while (true) {
		int second;
		cout << "Chose an operand [+, -, *, /]: ";
		cin >> operand;
		cout << "Enter the second number: ";
		cin >> second;
		cout << "Result: ";
		switch (operand) {
		case '+':
			base = base + second;
			cout << base << endl;
			break;
		case '-':
			base = base - second;
			cout << base << endl;
			break;
		case '*':
			base = base * second;
			cout << base << endl;
			break;
		case '/':
			if (second == 0) {
				cout << "Error" << endl << "No dividing by zero" << endl;
				continue;
			}
			base = base / second;
			break;
		default:
			cout << "Enter a single operand...." << endl;
			continue;
			break;
		}
		cout << endl;
		cout << "Would you like to continue [Y/n]?" << endl;
		char proceeding;
		cin >> proceeding;
		if (proceeding == 'Y' || proceeding == 'y') {
			cout << "First Number: " << base << endl;
			continue;
		}
		else {
			break;
		}
	}
	system("pause");
}