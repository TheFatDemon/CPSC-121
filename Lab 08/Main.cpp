//
//  main.cpp
//  Lab 8
//
//  Created by Mario Personal on 10/5/16.
//  Copyright © 2016 Mario Segura. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

const int numberOfStudents = 10;
const int numberOfAssignments = 10;

void clear() {
#if defined(__linux__) || defined(__APPLE__)
	system("clear");
#else
	system("cls");
#endif
}

struct Assignment {
	bool defined = false;
	string assignmentName;
	double pointsPossible;
};

struct AssignmentScore {
	//Assignment assignment;
	double pointsRecieved;
};

struct Student {
	bool defined = false;
	string firstName;
	string lastName;
	AssignmentScore scores[numberOfAssignments];
};

Student students[numberOfStudents];
Assignment assignments[numberOfAssignments];

int getMenuSelection() {

	cout << "Main Menu:" << endl;
	cout << "1. Edit Students" << endl;
	cout << "2. Edit Assignments" << endl;
	cout << "3. Check Student's Average" << endl;
	cout << "4. Check Assignment Average" << endl;

	cout << "0. Exit" << endl;

	int selection;
	cin >> selection;


	// UPDATE WHEN MENU ITEM ADDED
	if (selection < 0 || selection > 4) {
		// Chose something out of bounds
		return 99;
	}

	// Chose an appropriate value
	return selection;
}

void printStudents() {
	for (int i = 0; i < numberOfStudents; i++) {
		cout << i + 1 << ". " << (students[i].defined ? students[i].firstName + " " + students[i].lastName : "(Empty)") << endl;
	}
}

void printAssignments() {
	for (int i = 0; i < numberOfAssignments; i++) {
		cout << i + 1 << ". " << (assignments[i].defined ? assignments[i].assignmentName : "(Empty)") << endl;
	}
}

void editStudentAtIndex(int index) {
	clear();

	Student student;
	student.defined = true;

	cout << "Enter Information for new Student" << endl;
	cout << "First Name: ";
	cin >> student.firstName;
	cout << "Last Name: ";
	cin >> student.lastName;

	// If there are valid assignments in Assignments array, then add them
	for (int i = 0; i < numberOfAssignments; i++) {
		if (assignments[i].defined) {
			// If there are assignments, we must add them to the student
			AssignmentScore score;
			cout << "Add Score for assignment " << assignments[i].assignmentName << ": ";
			cin >> score.pointsRecieved;
			student.scores[i] = score;
		}
	}

	// Add student to Array
	students[index] = student;
}

void editStudents() {
	// Clear the screen
	clear();
	// Prompt for student selection
	cout << "You have enough slots for " << numberOfStudents << " students" << endl;
	cout << "Which student would you like to replace or add? " << endl;
	printStudents();
	int selection;
	cin >> selection;
	if (selection == 0 || selection > numberOfStudents) {
		return;
	}
	// We now have a valid array selection
	selection--;

	editStudentAtIndex(selection);
	clear();
}

void editAssignmentAtIndex(int index) {
	clear();

	Assignment assignment;
	assignment.defined = true;

	cout << "Enter the infromation for the assignment" << endl;
	cout << "Assignment Name: ";
	cin >> assignment.assignmentName;
	cout << "Possible Points: ";
	cin >> assignment.pointsPossible;

	// We check if there are students
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].defined) {
			AssignmentScore score;
			cout << "Add Score for assignment " << assignment.assignmentName << " for " << students[i].firstName << ": ";
			cin >> score.pointsRecieved;
			students[i].scores[index] = score;
		}
	}

	assignments[index] = assignment;
}

void editAssignments() {
	// Clear screen
	clear();
	cout << "You can only " << numberOfAssignments << " assignments" << endl;
	cout << "Which assignment would you like to replace or add " << endl;
	for (int i = 0; i < numberOfAssignments; i++) {
		cout << i + 1 << ". " << (assignments[i].defined ? assignments[i].assignmentName : "(Empty)") << endl;
	}

	int selection;
	cin >> selection;
	if (selection == 0 || selection > numberOfAssignments) {
		return;
	}
	selection--;

	editAssignmentAtIndex(selection);
	clear();
}

void checkStudentAverage() {
	clear();
	cout << "Which Student Would you like to check their average?" << endl;
	printStudents();
	int selection;
	cin >> selection;
	if (selection == 0 || selection > numberOfStudents) {
		return;
	}
	selection--;
	Student student = students[selection];

	double totalPoints = 0;
	double pointsReceived = 0;
	for (int i = 0; i < numberOfAssignments; i++) {
		if (assignments[i].defined) {
			totalPoints += assignments[i].pointsPossible;
			pointsReceived += student.scores[i].pointsRecieved;
		}
	}
	clear();
	cout << student.firstName << " has a class average of " << pointsReceived / totalPoints << endl << endl;
}

void checkAssignmentAverage() {
	clear();
	cout << "Which Assignment Would you like to check its average?" << endl;
	printAssignments();
	int selection;
	cin >> selection;
	if (selection == 0 || selection > numberOfAssignments) {
		return;
	}
	selection--;
	Assignment assignment = assignments[selection];
	double totalPoints = 0;
	double pointsReceived = 0;
	for (int i = 0; i < numberOfStudents; i++) {
		if (students[i].defined) {
			pointsReceived += students[i].scores[i].pointsRecieved;
			totalPoints += assignments[selection].pointsPossible;
		}
	}
	clear();
	cout << "For Assignment " << assignment.assignmentName << " you have an average of " << pointsReceived / totalPoints << endl << endl;
}

int main(int argc, const char * argv[]) {
	clear();
	while (true) {
		int selection = getMenuSelection();

		switch (selection) {
		case 99:
			continue;
			break;
		case 1:
			editStudents();
			break;
		case 2:
			editAssignments();
			break;
		case 3:
			checkStudentAverage();
			break;
		case 4:
			checkAssignmentAverage();
			break;
		case 0:
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}