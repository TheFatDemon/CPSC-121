// Mario Segura
// CPSC 121 Fall 16
// Implementation for Fight Class

#include "Fight.h"
#include <iostream>

using namespace std;

Fight::Fight() {
	// No need for Constructor
}

int Fight::takeTurn() {
	// Update turn count
	turn += 1;

	// Get a random number between 0 and 1
	int attacker = rand() % 2;
	// If attacker is 1, foe is 0 and vice-versa
	int attacked = (attacker == 1 ? 0 : 1);

	// Logic
	int attack = foes[attacker].attackMin + rand() % foes[attacker].attackRange;
	// Subtract random attack from `attacked` health
	// Another way to write it could be 
	// foes[attacked].curHealth -= attack
	foes[attacked].curHealth = foes[attacked].curHealth - attack;

	// Display what happened
	cout << foes[attacker].name << " has attacked " <<
		foes[attacked].name << " for " <<
		attack << " damage." << endl;

	// According to specification, if foe 0 wins, return 2, if foe 1 wins, return 3, if fight continues, return 1
	if (foes[1].curHealth <= 0) {
		return 2;
	}
	else if (foes[0].curHealth <= 0) {
		return 3;
	}
	else {
		return 1;
	}
}

void Fight::generateFighter(Combatant &fighter) {
	// We have valid Combatant Objects
	// First we get their names
	cout << "Enter a name: ";
	cin >> fighter.name;

	// Generate their max health from 20-40
	fighter.maxHealth = rand() % 20 + 20;
	// Set their current health to their max health
	fighter.curHealth = fighter.maxHealth;
	// Generate their base attack from 3-6
	fighter.attackMin = rand() % 3 + 3;
	// Generate their attack range from 5-10
	fighter.attackRange = rand() % 5 + 5;
	// Set win count to 0 as these are brand new fighters
	fighter.winCount = 0;
	// Display stats
	cout << fighter.name << " HP: " << fighter.maxHealth << " DMG: " << fighter.attackMin << "-" << fighter.attackRange + fighter.attackMin << endl;

	// No Need for return as we are directly modifying the objects
}

void Fight::getFighters() {
	// Create two fighter objects
	Combatant fighter1, fighter2;
	
	// Pass these objects into the generateFighter Function
	generateFighter(fighter1);
	generateFighter(fighter2);
	
	// Add the new objects to our array
	this->foes[0] = fighter1;
	this->foes[1] = fighter2;
}

void Fight::runFight() {
	// Reset
	turn = 0;
	foes[0].curHealth = foes[0].maxHealth;
	foes[1].curHealth = foes[1].maxHealth;

	// This is the logic for the turns
	int result;
	do {
		// We loop until result is no longer 1
		result = takeTurn();
	} while (result == 1);

	// There can only be two conditions, 2 or 3
	if (result == 2) {
		// We update win count
		foes[0].winCount += 1;
		// Display stats
		cout << foes[0].name << " has defeated " << foes[1].name <<
			" in " << turn << " turns, and has won " << foes[0].winCount << " times" << endl;
	}
	else if (result == 3) {
		// Same as above
		foes[1].winCount += 1;
		cout << foes[1].name << " has defeated " << foes[0].name <<
			" in " << turn << " turns, and has won " << foes[1].winCount << " times" << endl;
	}
}
