// Mario Segura
// CPSC 121 Fall 16
// Implementation for Fight Class

#include "Fight.h"
#include <iostream>

using namespace std;

Fight::Fight() {

}

int Fight::takeTurn() {
	// Update turn count
	turn += 1;

	// Foe 0 attacks foe 1

	// Logic
	int attack = foes[0].attackMin + rand() % foes[0].attackRange;
	foes[1].curHealth = foes[1].curHealth - attack;

	// Display what happened
	cout << foes[0].name << " has attacked " <<
		foes[1].name << " for " <<
		attack << " damage." << endl;

	if (foes[1].curHealth <= 0)
	{
		return 2;
	}

	// Logic
	attack = foes[1].attackMin + rand() % foes[1].attackRange;
	foes[0].curHealth = foes[0].curHealth - attack;
	
	// Display what happened
	cout << foes[1].name << " has attacked " <<
		foes[0].name << " for " <<
		attack << " damage." << endl;

	// Foe 1 attacks foe 0
	if (foes[0].curHealth <= 0)
	{
		return 3;
	}

	return 1;
}

void Fight::generateFighter(Combatant &fighter) {
	cout << "Enter a name: ";
	cin >> fighter.name;
	fighter.maxHealth = rand() % 20 + 20;
	fighter.curHealth = fighter.maxHealth;
	fighter.attackMin = rand() % 3 + 3;
	fighter.attackRange = rand() % 5 + 5;
	fighter.winCount = 0;
	cout << fighter.name << " HP: " << fighter.maxHealth << " DMG: " << fighter.attackMin << "-" << fighter.attackRange + fighter.attackMin << endl;
}

void Fight::getFighters() {
	Combatant fighter1, fighter2;
	generateFighter(fighter1);
	generateFighter(fighter2);
	this->foes[0] = fighter1;
	this->foes[1] = fighter2;
}

void Fight::runFight() {
	// Reset healths
	turn = 0;
	foes[0].curHealth = foes[0].maxHealth;
	foes[1].curHealth = foes[1].maxHealth;
	int result;
	do {
		result = takeTurn();
	} while (result == 1);

	if (result == 2) {
		foes[0].winCount += 1;
		cout << foes[0].name << " has defeated " << foes[1].name <<
			" in " << turn << " turns, and has won " << foes[0].winCount << " times" << endl;
	}
	else if (result == 3) {
		foes[1].winCount += 1;
		cout << foes[1].name << " has defeated " << foes[0].name <<
			" in " << turn << " turns, and has won " << foes[1].winCount << " times" << endl;
	}
}
