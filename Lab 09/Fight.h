// Mario Segura
// CS 121 Fall 16
// Declares a Fight class that facilitates combat between two participants

// ifndef wrapper included so multiple inclusions doesn't cause errors
#ifndef _Fight_H
#define _Fight_H

#include <string>
struct Combatant {
	int curHealth, maxHealth, attackMin, attackRange, winCount;
	std::string name;
};

class Fight {
	//Only accessible within the class
private:
	Combatant foes[2];//Contains the two combatants doing combat
	int turn;//Counts how many turns have passed in the battle
	int takeTurn();//Returns 1 if fight continues, 2 if combatant 1 wins, 3 if fighter 2 wins. Displays details.
	void generateFighter(Combatant &fighter);//Fills in the passed combatant with random stats and user chosen name.
											 //MaxHealth: 20-40   AttackMin: 3-6	AttackRange: 5-10

											 //Usable whenever variable of type is declared, using . operator
public:
	Fight();//Constructor initializes values upon declaration
	void getFighters();//Initializes the fighters before a fight begins
	void runFight();//Begins a fight until one participant is defeated, displaying information about events.
};

#endif
