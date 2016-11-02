// Author Mario Segura
// CPSC 121 Lab 6
// 9/28/2016
#include <iostream>
using namespace std;
void promptForSelection() {
	cout << "What shape would you like to calculate?" << endl
		<< "1. Triangle" << endl
		<< "2. Rectangle" << endl
		<< "Other. Exit" << endl
		<< "Input [1,2]: ";
}
int checkInput() {
	int selection;
	cin >> selection;
	return selection;
}
void drawTriangle(int size) {
	for (int i = 1; i <= size; i++) {
		for (int x = 1; x <= i; x++) {
			cout << "*";
		}
		cout << endl;
	}
}
void processTriangle() {
	int size;
	system("cls");
	cout << "How long do you want the base to be? ";
	cin >> size;
	drawTriangle(size);
}
void drawRectangle(int height, int width) {
	for (int i = 0; i < height; i++) {
		for (int x = 0; x < width; x++) {
			cout << "*";
		}
		cout << endl;
	}
}
void processRectangle() {
	int height, width;
	system("cls");
	cout << "Enter a width: ";
	cin >> width;
	cout << "Enter a height: ";
	cin >> height;
	drawRectangle(height, width);
}
int main () {
	while (true) {
		promptForSelection();
		int input = checkInput();
		if (input == 1) {
			processTriangle();
		}
		else if (input == 2) {
			processRectangle();
		}
		else {
			break;
		}
	}
	return 0;
}